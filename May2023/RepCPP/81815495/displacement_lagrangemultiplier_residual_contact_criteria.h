
#pragma once



#include "utilities/table_stream_utility.h"
#include "solving_strategies/convergencecriterias/convergence_criteria.h"
#include "utilities/color_utilities.h"
#include "utilities/constraint_utilities.h"

namespace Kratos
{







template<   class TSparseSpace,
class TDenseSpace >
class DisplacementLagrangeMultiplierResidualContactCriteria
: public ConvergenceCriteria< TSparseSpace, TDenseSpace >
{
public:


KRATOS_CLASS_POINTER_DEFINITION( DisplacementLagrangeMultiplierResidualContactCriteria );

KRATOS_DEFINE_LOCAL_FLAG( ENSURE_CONTACT );
KRATOS_DEFINE_LOCAL_FLAG( PRINTING_OUTPUT );
KRATOS_DEFINE_LOCAL_FLAG( TABLE_IS_INITIALIZED );
KRATOS_DEFINE_LOCAL_FLAG( ROTATION_DOF_IS_CONSIDERED );
KRATOS_DEFINE_LOCAL_FLAG( INITIAL_RESIDUAL_IS_SET );

typedef ConvergenceCriteria< TSparseSpace, TDenseSpace >                                    BaseType;

typedef DisplacementLagrangeMultiplierResidualContactCriteria< TSparseSpace, TDenseSpace > ClassType;

typedef typename BaseType::DofsArrayType                                               DofsArrayType;

typedef typename BaseType::TSystemMatrixType                                       TSystemMatrixType;

typedef typename BaseType::TSystemVectorType                                       TSystemVectorType;

typedef TSparseSpace                                                                 SparseSpaceType;

typedef TableStreamUtility::Pointer                                          TablePrinterPointerType;

typedef std::size_t                                                                        IndexType;



explicit DisplacementLagrangeMultiplierResidualContactCriteria()
: BaseType()
{
}


explicit DisplacementLagrangeMultiplierResidualContactCriteria(Kratos::Parameters ThisParameters)
: BaseType()
{
ThisParameters = this->ValidateAndAssignParameters(ThisParameters, this->GetDefaultParameters());
this->AssignSettings(ThisParameters);
}


explicit DisplacementLagrangeMultiplierResidualContactCriteria(
const double DispRatioTolerance,
const double DispAbsTolerance,
const double RotRatioTolerance,
const double RotAbsTolerance,
const double LMRatioTolerance,
const double LMAbsTolerance,
const bool EnsureContact = false,
const bool PrintingOutput = false
)
: BaseType()
{
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::ENSURE_CONTACT, EnsureContact);
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::PRINTING_OUTPUT, PrintingOutput);
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::TABLE_IS_INITIALIZED, false);
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED, false);
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::INITIAL_RESIDUAL_IS_SET, false);

mDispRatioTolerance = DispRatioTolerance;
mDispAbsTolerance = DispAbsTolerance;

mRotRatioTolerance = RotRatioTolerance;
mRotAbsTolerance = RotAbsTolerance;

mLMRatioTolerance = LMRatioTolerance;
mLMAbsTolerance = LMAbsTolerance;
}

/
typename BaseType::Pointer Create(Parameters ThisParameters) const override
{
return Kratos::make_shared<ClassType>(ThisParameters);
}


bool PostCriteria(
ModelPart& rModelPart,
DofsArrayType& rDofSet,
const TSystemMatrixType& rA,
const TSystemVectorType& rDx,
const TSystemVectorType& rb
) override
{
if (SparseSpaceType::Size(rb) != 0) { 
double disp_residual_solution_norm = 0.0, rot_residual_solution_norm = 0.0, lm_residual_solution_norm = 0.0;
IndexType disp_dof_num(0), rot_dof_num(0), lm_dof_num(0);

struct AuxValues {
std::size_t dof_id = 0;
double residual_dof_value = 0.0;
};

const std::size_t number_active_dofs = rb.size();

const std::function<bool(const VariableData&)> check_without_rot =
[](const VariableData& rCurrVar) -> bool {return true;};
const std::function<bool(const VariableData&)> check_with_rot =
[](const VariableData& rCurrVar) -> bool {return ((rCurrVar == DISPLACEMENT_X) || (rCurrVar == DISPLACEMENT_Y) || (rCurrVar == DISPLACEMENT_Z));};
const auto* p_check_disp = (mOptions.Is(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED)) ? &check_with_rot : &check_without_rot;

using SixReduction = CombinedReduction<SumReduction<double>, SumReduction<double>, SumReduction<double>, SumReduction<IndexType>, SumReduction<IndexType>, SumReduction<IndexType>>;
std::tie(disp_residual_solution_norm,rot_residual_solution_norm,lm_residual_solution_norm,disp_dof_num,rot_dof_num,lm_dof_num) = block_for_each<SixReduction>(rDofSet, AuxValues(), [this,p_check_disp,&number_active_dofs,&rb](Dof<double>& rDof, AuxValues& aux_values) {
aux_values.dof_id = rDof.EquationId();

if (aux_values.dof_id < number_active_dofs) {
if (mActiveDofs[aux_values.dof_id] == 1) {
aux_values.residual_dof_value = rb[aux_values.dof_id];

const auto& r_curr_var = rDof.GetVariable();
if ((r_curr_var == VECTOR_LAGRANGE_MULTIPLIER_X) || (r_curr_var == VECTOR_LAGRANGE_MULTIPLIER_Y) || (r_curr_var == VECTOR_LAGRANGE_MULTIPLIER_Z) || (r_curr_var == LAGRANGE_MULTIPLIER_CONTACT_PRESSURE)) {
return std::make_tuple(0.0,0.0,std::pow(aux_values.residual_dof_value, 2),0,0,1);
} else if ((*p_check_disp)(r_curr_var)) {
return std::make_tuple(std::pow(aux_values.residual_dof_value, 2),0.0,0.0,1,0,0);
} else { 
KRATOS_DEBUG_ERROR_IF_NOT((r_curr_var == ROTATION_X) || (r_curr_var == ROTATION_Y) || (r_curr_var == ROTATION_Z)) << "Variable must be a ROTATION and it is: " << r_curr_var.Name() << std::endl;
return std::make_tuple(0.0,std::pow(aux_values.residual_dof_value, 2),0.0,0,1,0);
}
}
}
return std::make_tuple(0.0,0.0,0.0,0,0,0);
});

mDispCurrentResidualNorm = disp_residual_solution_norm;
mRotCurrentResidualNorm = rot_residual_solution_norm;
mLMCurrentResidualNorm = lm_residual_solution_norm;

double residual_disp_ratio = 1.0;
double residual_rot_ratio = 1.0;
double residual_lm_ratio = 1.0;

if (mOptions.IsNot(DisplacementLagrangeMultiplierResidualContactCriteria::INITIAL_RESIDUAL_IS_SET)) {
mDispInitialResidualNorm = (disp_residual_solution_norm == 0.0) ? 1.0 : disp_residual_solution_norm;
mLMInitialResidualNorm = (lm_residual_solution_norm == 0.0) ? 1.0 : lm_residual_solution_norm;
residual_disp_ratio = 1.0;
residual_lm_ratio = 1.0;
if (mOptions.Is(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED)) {
mRotInitialResidualNorm = (rot_residual_solution_norm == 0.0) ? 1.0 : rot_residual_solution_norm;
residual_rot_ratio = 1.0;
}
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::INITIAL_RESIDUAL_IS_SET, true);
}

residual_disp_ratio = mDispCurrentResidualNorm/mDispInitialResidualNorm;

residual_rot_ratio = mRotCurrentResidualNorm/mRotInitialResidualNorm;

residual_lm_ratio = mLMCurrentResidualNorm/mLMInitialResidualNorm;

KRATOS_ERROR_IF(mOptions.Is(DisplacementLagrangeMultiplierResidualContactCriteria::ENSURE_CONTACT) && residual_lm_ratio == 0.0) << "ERROR::CONTACT LOST::ARE YOU SURE YOU ARE SUPPOSED TO HAVE CONTACT?" << std::endl;

const double residual_disp_abs = mDispCurrentResidualNorm/disp_dof_num;
const double residual_rot_abs = mRotCurrentResidualNorm/rot_dof_num;
const double residual_lm_abs = mLMCurrentResidualNorm/lm_dof_num;

ProcessInfo& r_process_info = rModelPart.GetProcessInfo();

if (rModelPart.GetCommunicator().MyPID() == 0 && this->GetEchoLevel() > 0) {
if (r_process_info.Has(TABLE_UTILITY)) {
std::cout.precision(4);
TablePrinterPointerType p_table = r_process_info[TABLE_UTILITY];
auto& Table = p_table->GetTable();
if (mOptions.Is(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED)) {
Table << residual_disp_ratio << mDispRatioTolerance << residual_disp_abs << mDispAbsTolerance << residual_rot_ratio << mRotRatioTolerance << residual_rot_abs << mRotAbsTolerance << residual_lm_ratio << mLMRatioTolerance << residual_lm_abs << mLMAbsTolerance;
} else {
Table << residual_disp_ratio << mDispRatioTolerance << residual_disp_abs << mDispAbsTolerance << residual_lm_ratio << mLMRatioTolerance << residual_lm_abs << mLMAbsTolerance;
}
} else {
std::cout.precision(4);
if (mOptions.IsNot(DisplacementLagrangeMultiplierResidualContactCriteria::PRINTING_OUTPUT)) {
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << BOLDFONT("RESIDUAL CONVERGENCE CHECK") << "\tSTEP: " << r_process_info[STEP] << "\tNL ITERATION: " << r_process_info[NL_ITERATION_NUMBER] << std::endl << std::scientific;
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << BOLDFONT("\tDISPLACEMENT: RATIO = ") << residual_disp_ratio << BOLDFONT(" EXP.RATIO = ") << mDispRatioTolerance << BOLDFONT(" ABS = ") << residual_disp_abs << BOLDFONT(" EXP.ABS = ") << mDispAbsTolerance << std::endl;
if (mOptions.Is(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED)) {
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << BOLDFONT("\tROTATION: RATIO = ") << residual_rot_ratio << BOLDFONT(" EXP.RATIO = ") << mRotRatioTolerance << BOLDFONT(" ABS = ") << residual_rot_abs << BOLDFONT(" EXP.ABS = ") << mRotAbsTolerance << std::endl;
}
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << BOLDFONT("\tLAGRANGE MUL: RATIO = ") << residual_lm_ratio << BOLDFONT(" EXP.RATIO = ") << mLMRatioTolerance << BOLDFONT(" ABS = ") << residual_lm_abs << BOLDFONT(" EXP.ABS = ") << mLMAbsTolerance << std::endl;
} else {
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << "RESIDUAL CONVERGENCE CHECK" << "\tSTEP: " << r_process_info[STEP] << "\tNL ITERATION: " << r_process_info[NL_ITERATION_NUMBER] << std::endl << std::scientific;
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << "\tDISPLACEMENT: RATIO = " << residual_disp_ratio << " EXP.RATIO = " << mDispRatioTolerance << " ABS = " << residual_disp_abs << " EXP.ABS = " << mDispAbsTolerance << std::endl;
if (mOptions.Is(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED)) {
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << "\tROTATION: RATIO = " << residual_rot_ratio << " EXP.RATIO = " << mRotRatioTolerance << " ABS = " << residual_rot_abs << " EXP.ABS = " << mRotAbsTolerance << std::endl;
}
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << "\tLAGRANGE MUL: RATIO = " << residual_lm_ratio << " EXP.RATIO = " << mLMRatioTolerance << " ABS = " << residual_lm_abs << " EXP.ABS = " << mLMAbsTolerance << std::endl;
}
}
}

r_process_info[CONVERGENCE_RATIO] = (residual_disp_ratio > residual_lm_ratio) ? residual_disp_ratio : residual_lm_ratio;
r_process_info[RESIDUAL_NORM] = (residual_lm_abs > mLMAbsTolerance) ? residual_lm_abs : mLMAbsTolerance;

const bool disp_converged = (residual_disp_ratio <= mDispRatioTolerance || residual_disp_abs <= mDispAbsTolerance);
const bool rot_converged = (mOptions.Is(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED)) ? (residual_rot_ratio <= mRotRatioTolerance || residual_rot_abs <= mRotAbsTolerance) : true;
const bool lm_converged = (mOptions.IsNot(DisplacementLagrangeMultiplierResidualContactCriteria::ENSURE_CONTACT) && residual_lm_ratio == 0.0) ? true : (residual_lm_ratio <= mLMRatioTolerance || residual_lm_abs <= mLMAbsTolerance);

if (disp_converged && rot_converged && lm_converged ) {
if (rModelPart.GetCommunicator().MyPID() == 0 && this->GetEchoLevel() > 0) {
if (r_process_info.Has(TABLE_UTILITY)) {
TablePrinterPointerType p_table = r_process_info[TABLE_UTILITY];
auto& Table = p_table->GetTable();
if (mOptions.IsNot(DisplacementLagrangeMultiplierResidualContactCriteria::PRINTING_OUTPUT))
Table << BOLDFONT(FGRN("       Achieved"));
else
Table << "Achieved";
} else {
if (mOptions.IsNot(DisplacementLagrangeMultiplierResidualContactCriteria::PRINTING_OUTPUT))
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << BOLDFONT("\tResidual") << " convergence is " << BOLDFONT(FGRN("achieved")) << std::endl;
else
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << "\tResidual convergence is achieved" << std::endl;
}
}
return true;
} else {
if (rModelPart.GetCommunicator().MyPID() == 0 && this->GetEchoLevel() > 0) {
if (r_process_info.Has(TABLE_UTILITY)) {
TablePrinterPointerType p_table = r_process_info[TABLE_UTILITY];
auto& r_table = p_table->GetTable();
if (mOptions.IsNot(DisplacementLagrangeMultiplierResidualContactCriteria::PRINTING_OUTPUT))
r_table << BOLDFONT(FRED("   Not achieved"));
else
r_table << "Not achieved";
} else {
if (mOptions.IsNot(DisplacementLagrangeMultiplierResidualContactCriteria::PRINTING_OUTPUT))
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << BOLDFONT("\tResidual") << " convergence is " << BOLDFONT(FRED(" not achieved")) << std::endl;
else
KRATOS_INFO("DisplacementLagrangeMultiplierResidualContactCriteria") << "\tResidual convergence is not achieved" << std::endl;
}
}
return false;
}
} else 
return true;
}


void Initialize( ModelPart& rModelPart) override
{
BaseType::mConvergenceCriteriaIsInitialized = true;

mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED, ContactUtilities::CheckModelPartHasRotationDoF(rModelPart));

ProcessInfo& r_process_info = rModelPart.GetProcessInfo();
if (r_process_info.Has(TABLE_UTILITY) && mOptions.IsNot(DisplacementLagrangeMultiplierResidualContactCriteria::TABLE_IS_INITIALIZED)) {
TablePrinterPointerType p_table = r_process_info[TABLE_UTILITY];
auto& r_table = p_table->GetTable();
r_table.AddColumn("DP RATIO", 10);
r_table.AddColumn("EXP. RAT", 10);
r_table.AddColumn("ABS", 10);
r_table.AddColumn("EXP. ABS", 10);
if (mOptions.Is(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED)) {
r_table.AddColumn("RT RATIO", 10);
r_table.AddColumn("EXP. RAT", 10);
r_table.AddColumn("ABS", 10);
r_table.AddColumn("EXP. ABS", 10);
}
r_table.AddColumn("LM RATIO", 10);
r_table.AddColumn("EXP. RAT", 10);
r_table.AddColumn("ABS", 10);
r_table.AddColumn("EXP. ABS", 10);
r_table.AddColumn("CONVERGENCE", 15);
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::TABLE_IS_INITIALIZED, true);
}
}


void InitializeSolutionStep(
ModelPart& rModelPart,
DofsArrayType& rDofSet,
const TSystemMatrixType& rA,
const TSystemVectorType& rDx,
const TSystemVectorType& rb
) override
{
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::INITIAL_RESIDUAL_IS_SET, false);

ConstraintUtilities::ComputeActiveDofs(rModelPart, mActiveDofs, rDofSet);
}


Parameters GetDefaultParameters() const override
{
Parameters default_parameters = Parameters(R"(
{
"name"                                 : "displacement_lagrangemultiplier_residual_contact_criteria",
"ensure_contact"                       : false,
"print_convergence_criterion"          : false,
"residual_relative_tolerance"          : 1.0e-4,
"residual_absolute_tolerance"          : 1.0e-9,
"rotation_residual_relative_tolerance" : 1.0e-4,
"rotation_residual_absolute_tolerance" : 1.0e-9,
"contact_residual_relative_tolerance"  : 1.0e-4,
"contact_residual_absolute_tolerance"  : 1.0e-9
})");

const Parameters base_default_parameters = BaseType::GetDefaultParameters();
default_parameters.RecursivelyAddMissingParameters(base_default_parameters);
return default_parameters;
}


static std::string Name()
{
return "displacement_lagrangemultiplier_residual_contact_criteria";
}




std::string Info() const override
{
return "DisplacementLagrangeMultiplierResidualContactCriteria";
}

void PrintInfo(std::ostream& rOStream) const override
{
rOStream << Info();
}

void PrintData(std::ostream& rOStream) const override
{
rOStream << Info();
}


protected:






void AssignSettings(const Parameters ThisParameters) override
{
BaseType::AssignSettings(ThisParameters);

mDispRatioTolerance = ThisParameters["residual_relative_tolerance"].GetDouble();
mDispAbsTolerance = ThisParameters["residual_absolute_tolerance"].GetDouble();

mRotRatioTolerance = ThisParameters["rotation_residual_relative_tolerance"].GetDouble();
mRotAbsTolerance = ThisParameters["rotation_residual_absolute_tolerance"].GetDouble();

mLMRatioTolerance =  ThisParameters["contact_displacement_absolute_tolerance"].GetDouble();
mLMAbsTolerance =  ThisParameters["contact_residual_absolute_tolerance"].GetDouble();

mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::ENSURE_CONTACT, ThisParameters["ensure_contact"].GetBool());
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::PRINTING_OUTPUT, ThisParameters["print_convergence_criterion"].GetBool());
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::TABLE_IS_INITIALIZED, false);
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::ROTATION_DOF_IS_CONSIDERED, false);
mOptions.Set(DisplacementLagrangeMultiplierResidualContactCriteria::INITIAL_RESIDUAL_IS_SET, false);
}




private:


Flags mOptions; 

double mDispRatioTolerance;      
double mDispAbsTolerance;        
double mDispInitialResidualNorm; 
double mDispCurrentResidualNorm; 

double mRotRatioTolerance;      
double mRotAbsTolerance;        
double mRotInitialResidualNorm; 
double mRotCurrentResidualNorm; 

double mLMRatioTolerance;      
double mLMAbsTolerance;        
double mLMInitialResidualNorm; 
double mLMCurrentResidualNorm; 

std::vector<int> mActiveDofs;     






};  


template<class TSparseSpace, class TDenseSpace>
const Kratos::Flags DisplacementLagrangeMultiplierResidualContactCriteria<TSparseSpace, TDenseSpace>::ENSURE_CONTACT(Kratos::Flags::Create(0));
template<class TSparseSpace, class TDenseSpace>
const Kratos::Flags DisplacementLagrangeMultiplierResidualContactCriteria<TSparseSpace, TDenseSpace>::PRINTING_OUTPUT(Kratos::Flags::Create(1));
template<class TSparseSpace, class TDenseSpace>
const Kratos::Flags DisplacementLagrangeMultiplierResidualContactCriteria<TSparseSpace, TDenseSpace>::TABLE_IS_INITIALIZED(Kratos::Flags::Create(2));
template<class TSparseSpace, class TDenseSpace>
const Kratos::Flags DisplacementLagrangeMultiplierResidualContactCriteria<TSparseSpace, TDenseSpace>::ROTATION_DOF_IS_CONSIDERED(Kratos::Flags::Create(3));
template<class TSparseSpace, class TDenseSpace>
const Kratos::Flags DisplacementLagrangeMultiplierResidualContactCriteria<TSparseSpace, TDenseSpace>::INITIAL_RESIDUAL_IS_SET(Kratos::Flags::Create(4));
}
