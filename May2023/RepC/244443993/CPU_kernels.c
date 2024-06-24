#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "UDTypes.h"
#define max(x,y) ((x<y)?y:x)
#define min(x,y) ((x>y)?y:x)
#define PI 3.14159265359
float kernel_value_CPU(float v){
float rValue = 0;
const float z = v*v;
float num = (z* (z* (z* (z* (z* (z* (z* (z* (z* (z* (z* (z* (z*
(z* 0.210580722890567e-22f  + 0.380715242345326e-19f ) +
0.479440257548300e-16f) + 0.435125971262668e-13f ) +
0.300931127112960e-10f) + 0.160224679395361e-7f  ) +
0.654858370096785e-5f)  + 0.202591084143397e-2f  ) +
0.463076284721000e0f)   + 0.754337328948189e2f   ) +
0.830792541809429e4f)   + 0.571661130563785e6f   ) +
0.216415572361227e8f)   + 0.356644482244025e9f   ) +
0.144048298227235e10f);
float den = (z*(z*(z-0.307646912682801e4f)+0.347626332405882e7f)-0.144048298227235e10f);
rValue = -num/den;
return rValue;
}
void calculateLUT(float beta, float width, float** LUT, unsigned int* sizeLUT){
float v;
float cutoff2 = (width*width)/4.0;
unsigned int size;
if(width > 0){
size = (unsigned int)(10000*width);
(*LUT) = (float*) malloc (size*sizeof(float));
unsigned int k;
for(k=0; k<size; ++k){
v = (((float)k)/((float)size))*cutoff2;
(*LUT)[k] = kernel_value_CPU(beta*sqrt(1.0-(v/cutoff2)));
}
(*sizeLUT) = size;
}
}
float kernel_value_LUT(float v, float* LUT, int sizeLUT, float _1overCutoff2)
{
unsigned int k0;
float v0;
v *= (float)sizeLUT;
k0=(unsigned int)(v*_1overCutoff2);
v0 = ((float)k0)/_1overCutoff2;
return  LUT[k0] + ((v-v0)*(LUT[k0+1]-LUT[k0])/_1overCutoff2);
}
int gridding_Gold(unsigned int n, parameters params, ReconstructionSample* sample, float* LUT, unsigned int sizeLUT, cmplx* gridData, float* sampleDensity){
unsigned int NxL, NxH;
unsigned int NyL, NyH;
unsigned int NzL, NzH;
int nx;
int ny;
int nz;
float w;
unsigned int idx;
unsigned int idx0;
unsigned int idxZ;
unsigned int idxY;
float Dx2[100];
float Dy2[100];
float Dz2[100];
float *dx2=NULL;
float *dy2=NULL;
float *dz2=NULL;
float dy2dz2;
float v;
unsigned int size_x = params.gridSize[0];
unsigned int size_y = params.gridSize[1];
unsigned int size_z = params.gridSize[2];
float cutoff = ((float)(params.kernelWidth))/2.0; 
float cutoff2 = cutoff*cutoff;                    
float _1overCutoff2 = 1/cutoff2;                
float beta = PI * sqrt(4*params.kernelWidth*params.kernelWidth/(params.oversample*params.oversample) * (params.oversample-.5)*(params.oversample-.5)-.8);
int i;
for (i=0; i < n; i++){
ReconstructionSample pt = sample[i];
float kx = pt.kX;
float ky = pt.kY;
float kz = pt.kZ;
NxL = max((kx - cutoff), 0.0);
NxH = min((kx + cutoff), size_x-1.0);
NyL = max((ky - cutoff), 0.0);
NyH = min((ky + cutoff), size_y-1.0);
NzL = max((kz - cutoff), 0.0);
NzH = min((kz + cutoff), size_z-1.0);
if((pt.real != 0.0 || pt.imag != 0.0) && pt.sdc!=0.0)
{
for(dz2 = Dz2, nz=NzL; nz<=NzH; ++nz, ++dz2)
{
*dz2 = ((kz-nz)*(kz-nz));
}
for(dx2=Dx2,nx=NxL; nx<=NxH; ++nx,++dx2)
{
*dx2 = ((kx-nx)*(kx-nx));
}
for(dy2=Dy2, ny=NyL; ny<=NyH; ++ny,++dy2)
{
*dy2 = ((ky-ny)*(ky-ny));
}
idxZ = (NzL-1)*size_x*size_y;
for(dz2=Dz2, nz=NzL; nz<=NzH; ++nz, ++dz2)
{
idxZ += size_x*size_y;
idxY = (NyL-1)*size_x;
if((*dz2)<cutoff2)
{
for(dy2=Dy2, ny=NyL; ny<=NyH; ++ny, ++dy2)
{
idxY += size_x;
dy2dz2=(*dz2)+(*dy2);
idx0 = idxY + idxZ;
if(dy2dz2<cutoff2)
{
for(dx2=Dx2, nx=NxL; nx<=NxH; ++nx, ++dx2)
{
v = dy2dz2+(*dx2);
if(v<cutoff2)
{
idx = nx + idx0;
if (params.useLUT){
w = kernel_value_LUT(v, LUT, sizeLUT, _1overCutoff2) * pt.sdc;
} else {
w = kernel_value_CPU(beta*sqrt(1.0-(v*_1overCutoff2))) * pt.sdc;
}
gridData[idx].real += (w*pt.real);
gridData[idx].imag += (w*pt.imag);
sampleDensity[idx] += 1.0;
}
}
}
}
}
}
}
}
}
int gridding_Gold_Parallel(unsigned int n, parameters params, ReconstructionSample* sample, float* LUT, unsigned int sizeLUT, cmplx* gridData, float* sampleDensity){
unsigned int size_x = params.gridSize[0];
unsigned int size_y = params.gridSize[1];
unsigned int size_z = params.gridSize[2];
float cutoff = ((float)(params.kernelWidth))/2.0; 
float cutoff2 = cutoff*cutoff;                    
float _1overCutoff2 = 1/cutoff2;                
float beta = PI * sqrt(4*params.kernelWidth*params.kernelWidth/(params.oversample*params.oversample) * (params.oversample-.5)*(params.oversample-.5)-.8);
double t2_1 = omp_get_wtime();
#pragma omp parallel for schedule(dynamic,5000) default(none) shared(gridData,sampleDensity,beta,LUT,sizeLUT,params,n,cutoff,cutoff2,_1overCutoff2,size_x,size_y,size_z,sample)
for (int i=0; i < n; i++){
ReconstructionSample pt = sample[i];
unsigned int NxL, NxH;
unsigned int NyL, NyH;
unsigned int NzL, NzH;
int nx;
int ny;
int nz;
float w;
unsigned int idx;
unsigned int idx0;
unsigned int idxZ;
unsigned int idxY;
float Dx2[100];
float Dy2[100];
float Dz2[100];
float *dx2=NULL;
float *dy2=NULL;
float *dz2=NULL;
float dy2dz2;
float v;
float kx = pt.kX;
float ky = pt.kY;
float kz = pt.kZ;
NxL = max((kx - cutoff), 0.0);
NxH = min((kx + cutoff), size_x-1.0);
NyL = max((ky - cutoff), 0.0);
NyH = min((ky + cutoff), size_y-1.0);
NzL = max((kz - cutoff), 0.0);
NzH = min((kz + cutoff), size_z-1.0);
if((pt.real != 0.0 || pt.imag != 0.0) && pt.sdc!=0.0)
{
for(dz2 = Dz2, nz=NzL; nz<=NzH; ++nz, ++dz2)
{
*dz2 = ((kz-nz)*(kz-nz));
}
for(dx2=Dx2,nx=NxL; nx<=NxH; ++nx,++dx2)
{
*dx2 = ((kx-nx)*(kx-nx));
}
for(dy2=Dy2, ny=NyL; ny<=NyH; ++ny,++dy2)
{
*dy2 = ((ky-ny)*(ky-ny));
}
idxZ = (NzL-1)*size_x*size_y;
for(dz2=Dz2, nz=NzL; nz<=NzH; ++nz, ++dz2)
{
idxZ += size_x*size_y;
idxY = (NyL-1)*size_x;
if((*dz2)<cutoff2)
{
for(dy2=Dy2, ny=NyL; ny<=NyH; ++ny, ++dy2)
{
idxY += size_x;
dy2dz2=(*dz2)+(*dy2);
idx0 = idxY + idxZ;
if(dy2dz2<cutoff2)
{
for(dx2=Dx2, nx=NxL; nx<=NxH; ++nx, ++dx2)
{
v = dy2dz2+(*dx2);
if(v<cutoff2)
{
idx = nx + idx0;
if (params.useLUT){
w = kernel_value_LUT(v, LUT, sizeLUT, _1overCutoff2) * pt.sdc;
} else {
w = kernel_value_CPU(beta*sqrt(1.0-(v*_1overCutoff2))) * pt.sdc;
}
#pragma omp atomic
gridData[idx].real += (w*pt.real);
#pragma omp atomic
gridData[idx].imag += (w*pt.imag);
#pragma omp atomic
sampleDensity[idx] += 1.0;
}
}
}
}
}
}
}
}
}