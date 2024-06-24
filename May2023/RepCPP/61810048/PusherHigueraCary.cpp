

#include "PusherHigueraCary.h"

#include <iostream>
#include <cmath>

#include "Species.h"

#include "Particles.h"

PusherHigueraCary::PusherHigueraCary( Params &params, Species *species )
: Pusher( params, species )
{
}

PusherHigueraCary::~PusherHigueraCary()
{
}



void PusherHigueraCary::operator()( Particles &particles, SmileiMPI *smpi, int istart, int iend, int ithread, int ipart_buffer_offset )
{
std::vector<double> *Epart = &( smpi->dynamics_Epart[ithread] );
std::vector<double> *Bpart = &( smpi->dynamics_Bpart[ithread] );

const int nparts = vecto ? Epart->size() / 3 :
particles.size(); 

const double *const __restrict__ Ex = &( ( *Epart )[0*nparts] );
const double *const __restrict__ Ey = &( ( *Epart )[1*nparts] );
const double *const __restrict__ Ez = &( ( *Epart )[2*nparts] );
const double *const __restrict__ Bx = &( ( *Bpart )[0*nparts] );
const double *const __restrict__ By = &( ( *Bpart )[1*nparts] );
const double *const __restrict__ Bz = &( ( *Bpart )[2*nparts] );

double * __restrict__ invgf = &( smpi->dynamics_invgf[ithread][0] );

double *const __restrict__ position_x = particles.getPtrPosition( 0 );
double *const __restrict__ position_y = nDim_ > 1 ? particles.getPtrPosition( 1 ) : nullptr;
double *const __restrict__ position_z = nDim_ > 2 ? particles.getPtrPosition( 2 ) : nullptr;

double *const __restrict__ momentum_x = particles.getPtrMomentum(0);
double *const __restrict__ momentum_y = particles.getPtrMomentum(1);
double *const __restrict__ momentum_z = particles.getPtrMomentum(2);

short * __restrict__ charge = particles.getPtrCharge();

#pragma omp simd
for( int ipart=istart ; ipart<iend; ipart++ ) {

const int ipart2 = ipart - ipart_buffer_offset;

const double charge_over_mass_dts2 = ( double )( charge[ipart] )*one_over_mass_*dts2;

double pxsm = charge_over_mass_dts2*( Ex[ipart2] );
double pysm = charge_over_mass_dts2*( Ey[ipart2] );
double pzsm = charge_over_mass_dts2*( Ez[ipart2] );

const double umx = momentum_x[ipart] + pxsm;
const double umy = momentum_y[ipart] + pysm;
const double umz = momentum_z[ipart] + pzsm;

const double gfm2 = ( 1.0 + umx*umx + umy*umy + umz*umz );

double Tx    = charge_over_mass_dts2 * ( Bx[ipart2] );
double Ty    = charge_over_mass_dts2 * ( By[ipart2] );
double Tz    = charge_over_mass_dts2 * ( Bz[ipart2] );

const double beta2 = Tx*Tx + Ty*Ty + Tz*Tz;

const double local_invgf = 1./std::sqrt( 0.5*( gfm2 - beta2 +
std::sqrt( (gfm2 - beta2)*(gfm2 - beta2) + 4.0*( beta2 + std::pow( Tx*umx + Ty*umy + Tz*umz, 2 ) ) ) ) );

Tx    *= local_invgf;
Ty    *= local_invgf;
Tz    *= local_invgf;

const double Tx2   = Tx*Tx;
const double Ty2   = Ty*Ty;
const double Tz2   = Tz*Tz;

const double TxTy  = Tx*Ty;
const double TyTz  = Ty*Tz;
const double TzTx  = Tz*Tx;

const double inv_det_T = 1.0/( 1.0+Tx2+Ty2+Tz2 );

const double upx = ( ( 1.0+Tx2-Ty2-Tz2 )* umx  +      2.0*( TxTy+Tz )* umy  +      2.0*( TzTx-Ty )* umz )*inv_det_T;
const double upy = ( 2.0*( TxTy-Tz )* umx  + ( 1.0-Tx2+Ty2-Tz2 )* umy  +      2.0*( TyTz+Tx )* umz )*inv_det_T;
const double upz = ( 2.0*( TzTx+Ty )* umx  +      2.0*( TyTz-Tx )* umy  + ( 1.0-Tx2-Ty2+Tz2 )* umz )*inv_det_T;

pxsm += upx;
pysm += upy;
pzsm += upz;

invgf[ipart2] = 1. / std::sqrt( 1.0 + pxsm*pxsm + pysm*pysm + pzsm*pzsm );

momentum_x[ipart] = pxsm;
momentum_y[ipart] = pysm;
momentum_z[ipart] = pzsm;

position_x[ipart] += dt*momentum_x[ipart]*invgf[ipart2];
if (nDim_>1) {
position_y[ipart] += dt*momentum_y[ipart]*invgf[ipart2];
if (nDim_>2) {
position_z[ipart] += dt*momentum_z[ipart]*invgf[ipart2];
}
}
} 



}