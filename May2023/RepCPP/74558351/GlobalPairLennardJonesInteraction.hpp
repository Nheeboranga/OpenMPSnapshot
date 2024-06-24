#ifndef MJOLNIR_OMP_GLOBAL_PAIR_LENNARD_JONES_INTEARACTION_HPP
#define MJOLNIR_OMP_GLOBAL_PAIR_LENNARD_JONES_INTEARACTION_HPP
#include <mjolnir/omp/OpenMPSimulatorTraits.hpp>
#include <mjolnir/omp/System.hpp>
#include <mjolnir/forcefield/global/GlobalPairLennardJonesInteraction.hpp>

namespace mjolnir
{

template<typename realT, template<typename, typename> class boundaryT>
class GlobalPairInteraction<
OpenMPSimulatorTraits<realT, boundaryT>,
LennardJonesPotential<realT>
> final : public GlobalInteractionBase<OpenMPSimulatorTraits<realT, boundaryT>>
{
public:

using traits_type     = OpenMPSimulatorTraits<realT, boundaryT>;
using base_type       = GlobalInteractionBase<traits_type>;
using real_type       = typename base_type::real_type;
using coordinate_type = typename base_type::coordinate_type;
using system_type     = typename base_type::system_type;
using topology_type   = typename base_type::topology_type;
using boundary_type   = typename base_type::boundary_type;
using potential_type  = LennardJonesPotential<real_type>;
using partition_type  = SpatialPartition<traits_type, potential_type>;
using parameter_list_type = ParameterList<traits_type, potential_type>;

public:
GlobalPairInteraction()  = default;
~GlobalPairInteraction() override {}

GlobalPairInteraction(potential_type&& pot, parameter_list_type&& para,
partition_type&& part)
: potential_(std::move(pot)), parameters_(std::move(para)),
partition_(std::move(part))
{}


void initialize(const system_type& sys, const topology_type& topol) override
{
MJOLNIR_GET_DEFAULT_LOGGER();
MJOLNIR_LOG_FUNCTION();
MJOLNIR_LOG_INFO("potential is ", this->name());

this->potential_ .initialize(sys);
this->parameters_.initialize(sys, topol, potential_);
this->partition_ .initialize(sys, parameters_.cref());
}


void update(const system_type& sys, const topology_type& topol) override
{
MJOLNIR_GET_DEFAULT_LOGGER();
MJOLNIR_LOG_FUNCTION();
MJOLNIR_LOG_INFO("potential is ", this->name());

this->potential_ .initialize(sys);
this->parameters_.update(sys, topol, potential_);
this->partition_.initialize(sys, this->parameters_.cref());
}

void reduce_margin(const real_type dmargin, const system_type& sys) override
{
this->partition_.reduce_margin(dmargin, sys, this->parameters_.cref());
return;
}
void scale_margin(const real_type scale, const system_type& sys) override
{
this->partition_.scale_margin(scale, sys, this->parameters_.cref());
return;
}

void calc_force(system_type& sys) const noexcept override
{
this->template calc_force_and_virial_impl<false>(sys);
return ;
}
void calc_force_and_virial(system_type& sys) const noexcept override
{
this->template calc_force_and_virial_impl<true>(sys);
return ;
}
real_type calc_force_and_energy(system_type& sys) const noexcept override
{
return this->template calc_force_virial_energy_impl<false>(sys);
}
real_type calc_force_virial_energy(system_type& sys) const noexcept override
{
return this->template calc_force_virial_energy_impl<true>(sys);
}

real_type calc_energy(const system_type& sys) const noexcept override
{
real_type E(0);

const auto coef_at_cutoff  = potential_.coef_at_cutoff();
const auto cutoff_ratio    = potential_.cutoff_ratio();
const auto cutoff_ratio_sq = cutoff_ratio * cutoff_ratio;

const auto leading_participants = this->parameters_.leading_participants();
#pragma omp parallel for reduction(+:E)
for(std::size_t idx=0; idx < leading_participants.size(); ++idx)
{
const auto i = leading_participants[idx];
for(const auto& ptnr : this->partition_.partners(i))
{
const auto  j    = ptnr.index;
const auto& para = ptnr.parameter();

const coordinate_type rij =
sys.adjust_direction(sys.position(i), sys.position(j));
const real_type l_sq = math::length_sq(rij);

const real_type sigma_sq = para.sigma * para.sigma;
if(sigma_sq * cutoff_ratio_sq < l_sq) {continue;}

const real_type epsilon = para.epsilon;

const real_type s2l2 = sigma_sq / l_sq;
const real_type s6l6 = s2l2 * s2l2 * s2l2;

E += 4 * epsilon * (s6l6 * s6l6 - s6l6 - coef_at_cutoff);
}
}
return E;
}

std::string name() const override {return "GlobalPairLennardJones";}

base_type* clone() const override
{
return new GlobalPairInteraction(*this);
}

private:

template<bool NeedVirial>
void calc_force_and_virial_impl(system_type& sys) const noexcept
{
const auto cutoff_ratio    = potential_.cutoff_ratio();
const auto cutoff_ratio_sq = cutoff_ratio * cutoff_ratio;

const auto leading_participants = this->parameters_.leading_participants();
#pragma omp parallel for
for(std::size_t idx=0; idx < leading_participants.size(); ++idx)
{
const std::size_t thread_id = omp_get_thread_num();
const auto i = leading_participants[idx];
for(const auto& ptnr : this->partition_.partners(i))
{
const auto  j    = ptnr.index;
const auto& para = ptnr.parameter();

const coordinate_type rij =
sys.adjust_direction(sys.position(i), sys.position(j));
const real_type l_sq = math::length_sq(rij);

const real_type sigma_sq = para.sigma * para.sigma;
if(sigma_sq * cutoff_ratio_sq < l_sq) {continue;}

const real_type epsilon = para.epsilon;

const real_type rcp_l_sq = 1 / l_sq;
const real_type s2l2 = sigma_sq * rcp_l_sq;
const real_type s6l6 = s2l2 * s2l2 * s2l2;

const coordinate_type f = rij *
(24 * epsilon * (s6l6 - 2 * s6l6 * s6l6) * rcp_l_sq);

sys.force_thread(thread_id, i) += f;
sys.force_thread(thread_id, j) -= f;

if(NeedVirial)
{
sys.virial_thread(thread_id) += math::tensor_product(rij, -f);
}
}
}
return ;
}
template<bool NeedVirial>
real_type calc_force_virial_energy_impl(system_type& sys) const noexcept
{
const auto coef_at_cutoff  = potential_.coef_at_cutoff();
const auto cutoff_ratio    = potential_.cutoff_ratio();
const auto cutoff_ratio_sq = cutoff_ratio * cutoff_ratio;

real_type energy = 0;
const auto leading_participants = this->parameters_.leading_participants();
#pragma omp parallel for reduction(+:energy)
for(std::size_t idx=0; idx < leading_participants.size(); ++idx)
{
const std::size_t thread_id = omp_get_thread_num();
const auto i = leading_participants[idx];
for(const auto& ptnr : this->partition_.partners(i))
{
const auto  j    = ptnr.index;
const auto& para = ptnr.parameter();

const coordinate_type rij =
sys.adjust_direction(sys.position(i), sys.position(j));
const real_type l_sq = math::length_sq(rij);

const real_type sigma_sq = para.sigma * para.sigma;
if(sigma_sq * cutoff_ratio_sq < l_sq) {continue;}

const real_type epsilon = para.epsilon;

const real_type rcp_l_sq = 1 / l_sq;
const real_type s2l2 = sigma_sq * rcp_l_sq;
const real_type s6l6 = s2l2 * s2l2 * s2l2;

energy += 4 * epsilon * (s6l6 * s6l6 - s6l6 - coef_at_cutoff);

const coordinate_type f = rij *
(24 * epsilon * (s6l6 - 2 * s6l6 * s6l6) * rcp_l_sq);

sys.force_thread(thread_id, i) += f;
sys.force_thread(thread_id, j) -= f;

if(NeedVirial)
{
sys.virial_thread(thread_id) += math::tensor_product(rij, -f);
}
}
}
return energy;
}

private:

potential_type      potential_;
parameter_list_type parameters_;
partition_type      partition_;
};

} 

#ifdef MJOLNIR_SEPARATE_BUILD
#include <mjolnir/core/BoundaryCondition.hpp>

namespace mjolnir
{
extern template class GlobalPairInteraction<OpenMPSimulatorTraits<double, UnlimitedBoundary>       , LennardJonesPotential<double>>;
extern template class GlobalPairInteraction<OpenMPSimulatorTraits<float,  UnlimitedBoundary>       , LennardJonesPotential<float >>;
extern template class GlobalPairInteraction<OpenMPSimulatorTraits<double, CuboidalPeriodicBoundary>, LennardJonesPotential<double>>;
extern template class GlobalPairInteraction<OpenMPSimulatorTraits<float,  CuboidalPeriodicBoundary>, LennardJonesPotential<float >>;
} 
#endif 

#endif 
