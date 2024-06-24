#include <chrono>
#include <math.h>
#include <stdio.h>

struct full_data
{
int sizex;
int sizey;
int Nmats;
double * __restrict rho;
double * __restrict rho_mat_ave;
double * __restrict p;
double * __restrict Vf;
double * __restrict t;
double * __restrict V;
double * __restrict x;
double * __restrict y;
double * __restrict n;
double * __restrict rho_ave;
};

struct compact_data
{
int sizex;
int sizey;
int Nmats;
double * __restrict rho_compact;
double * __restrict rho_compact_list;
double * __restrict rho_mat_ave_compact;
double * __restrict rho_mat_ave_compact_list;
double * __restrict p_compact;
double * __restrict p_compact_list;
double * __restrict Vf_compact_list;
double * __restrict t_compact;
double * __restrict t_compact_list;
double * __restrict V;
double * __restrict x;
double * __restrict y;
double * __restrict n;
double * __restrict rho_ave_compact;
int * __restrict imaterial;
int * __restrict matids;
int * __restrict nextfrac;
int * __restrict mmc_index;
int * __restrict mmc_i;
int * __restrict mmc_j;
int mm_len;
int mmc_cells;
};


void compact_cell_centric(full_data cc, compact_data ccc, int argc, char** argv)
{

int sizex = cc.sizex;
int sizey = cc.sizey;
int Nmats = cc.Nmats;
int mmc_cells = ccc.mmc_cells;
int mm_len = ccc.mm_len;

int    *imaterial = ccc.imaterial;
int    *matids = ccc.matids;
int    *nextfrac = ccc.nextfrac;
int    *mmc_index = ccc.mmc_index;
int    *mmc_i = ccc.mmc_i;
int    *mmc_j = ccc.mmc_j;
double *x = ccc.x;
double *y = ccc.y;
double *rho_compact = ccc.rho_compact;
double *rho_compact_list = ccc.rho_compact_list;
double *rho_mat_ave_compact = ccc.rho_mat_ave_compact;
double *rho_mat_ave_compact_list = ccc.rho_mat_ave_compact_list;
double *p_compact = ccc.p_compact;
double *p_compact_list = ccc.p_compact_list;
double *t_compact = ccc.t_compact;
double *t_compact_list = ccc.t_compact_list;
double *V = ccc.V;
double *Vf_compact_list = ccc.Vf_compact_list;
double *n = ccc.n;
double *rho_ave_compact = ccc.rho_ave_compact;

#pragma omp target data map(to: imaterial[:sizex*sizey],\
matids[:mm_len], \
nextfrac[:mm_len], \
mmc_index[:mmc_cells+1], \
mmc_i[:mmc_cells+1], \
mmc_j[:mmc_cells+1]) \
map(tofrom: x[:sizex*sizey], \
y[:sizex*sizey], \
rho_compact[:sizex*sizey], \
rho_compact_list[:mm_len], \
rho_mat_ave_compact[:sizex*sizey], \
rho_mat_ave_compact_list[:mm_len], \
p_compact[:sizex*sizey], \
p_compact_list[:mm_len], \
t_compact[:sizex*sizey], \
t_compact_list[:mm_len], \
V[:sizex*sizey], \
Vf_compact_list[:mm_len], \
n[:Nmats], \
rho_ave_compact[:sizex*sizey])
{

const int thx = 32;
const int thy = 4;

#ifdef DEBUG
auto t0 = std::chrono::system_clock::now();
#endif

#pragma omp target teams distribute parallel for collapse(2) thread_limit(thy*thx)
for (int j = 0; j < sizey; j++) {
for (int i = 0; i < sizex; i++) {
#ifdef FUSED
double ave = 0.0;
int ix = imaterial[i+sizex*j];

if (ix <= 0) {
#ifdef LINKED
for (ix = -ix; ix >= 0; ix = nextfrac[ix]) {
ave += rho_compact_list[ix] * Vf_compact_list[ix];
}
#else
for (int idx = mmc_index[-ix]; idx < mmc_index[-ix+1]; idx++) {
ave += rho_compact_list[idx] * Vf_compact_list[idx];  
}
#endif
rho_ave_compact[i+sizex*j] = ave/V[i+sizex*j];
}
else {
#endif
rho_ave_compact[i+sizex*j] = rho_compact[i+sizex*j] / V[i+sizex*j];
#ifdef FUSED
}
#endif

}
}

#ifndef FUSED

#pragma omp target teams distribute parallel for thread_limit(thx*thy)
for (int c = 0; c < mmc_cells; c++) {
double ave = 0.0;
for (int m = mmc_index[c]; m < mmc_index[c+1]; m++) {
ave +=  rho_compact_list[m] * Vf_compact_list[m];
}
rho_ave_compact[mmc_i[c]+sizex*mmc_j[c]] = ave/V[mmc_i[c]+sizex*mmc_j[c]];
}
#endif

#ifdef DEBUG
std::chrono::duration<double> t1 = std::chrono::system_clock::now() - t0;
printf("Compact matrix, cell centric, alg 1: %g sec\n", t1.count());
t0 = std::chrono::system_clock::now();
#endif

#pragma omp target teams distribute parallel for collapse(2) thread_limit(thy*thx)
for (int j = 0; j < sizey; j++) {
for (int i = 0; i < sizex; i++) {
int ix = imaterial[i+sizex*j];
if (ix <= 0) {
#ifdef FUSED

#ifdef LINKED
for (ix = -ix; ix >= 0; ix = nextfrac[ix]) {
double nm = n[matids[ix]];
p_compact_list[ix] = (nm * rho_compact_list[ix] * t_compact_list[ix]) / Vf_compact_list[ix];
}
#else
for (int idx = mmc_index[-ix]; idx < mmc_index[-ix+1]; idx++) {
double nm = n[matids[idx]];
p_compact_list[idx] = (nm * rho_compact_list[idx] * t_compact_list[idx]) / Vf_compact_list[idx];
}
#endif
#endif
}
else {
int mat = ix - 1;
p_compact[i+sizex*j] = n[mat] * rho_compact[i+sizex*j] * t_compact[i+sizex*j];;
}
}
}
#ifndef FUSED
#pragma omp target teams distribute parallel for thread_limit(thx*thy)
for (int idx = 0; idx < mm_len; idx++) {
double nm = n[matids[idx]];
p_compact_list[idx] = (nm * rho_compact_list[idx] * t_compact_list[idx]) / Vf_compact_list[idx];
}
#endif

#ifdef DEBUG
std::chrono::duration<double> t2 = std::chrono::system_clock::now() - t0;
printf("Compact matrix, cell centric, alg 2: %g sec\n", t2.count());

t0 = std::chrono::system_clock::now();
#endif
#pragma omp target teams distribute parallel for collapse(2) thread_limit(thy*thx)
for (int j = 1; j < sizey-1; j++) {
for (int i = 1; i < sizex-1; i++) {

double xo = x[i+sizex*j];
double yo = y[i+sizex*j];

double dsqr[9];

for (int nj = -1; nj <= 1; nj++) {
for (int ni = -1; ni <= 1; ni++) {
dsqr[(nj+1)*3 + (ni+1)] = 0.0;
double xi = x[(i+ni)+sizex*(j+nj)];
double yi = y[(i+ni)+sizex*(j+nj)];
dsqr[(nj+1)*3 + (ni+1)] += (xo - xi) * (xo - xi);
dsqr[(nj+1)*3 + (ni+1)] += (yo - yi) * (yo - yi);
}
}

int ix = imaterial[i+sizex*j];

if (ix <= 0) {

#ifdef LINKED
for (ix = -ix; ix >= 0; ix = nextfrac[ix]) {
#else
for (int ix = mmc_index[-imaterial[i+sizex*j]]; ix < mmc_index[-imaterial[i+sizex*j]+1]; ix++) {
#endif
int mat = matids[ix];
double rho_sum = 0.0;
int Nn = 0;

for (int nj = -1; nj <= 1; nj++) {
for (int ni = -1; ni <= 1; ni++) {
int ci = i+ni, cj = j+nj;
int jx = imaterial[ci+sizex*cj];

if (jx <= 0) {
#ifdef LINKED
for (jx = -jx; jx >= 0; jx = nextfrac[jx]) {
#else
for (int jx = mmc_index[-imaterial[ci+sizex*cj]]; jx < mmc_index[-imaterial[ci+sizex*cj]+1]; jx++) {
#endif
if (matids[jx] == mat) {
rho_sum += rho_compact_list[jx] / dsqr[(nj+1)*3 + (ni+1)];
Nn += 1;

break;
}
}
}
else {

int mat_neighbour = jx - 1;
if (mat == mat_neighbour) {
rho_sum += rho_compact[ci+sizex*cj] / dsqr[(nj+1)*3 + (ni+1)];
Nn += 1;
}
} 
} 
} 

rho_mat_ave_compact_list[ix] = rho_sum / Nn;
} 
} 
else {

int mat = ix - 1;

double rho_sum = 0.0;
int Nn = 0;

for (int nj = -1; nj <= 1; nj++) {
if ((j + nj < 0) || (j + nj >= sizey)) 
continue;

for (int ni = -1; ni <= 1; ni++) {
if ((i + ni < 0) || (i + ni >= sizex)) 
continue;

int ci = i+ni, cj = j+nj;
int jx = imaterial[ci+sizex*cj];

if (jx <= 0) {
#ifdef LINKED
for (jx = -jx; jx >= 0; jx = nextfrac[jx]) {
#else
for (int jx = mmc_index[-imaterial[ci+sizex*cj]]; jx < mmc_index[-imaterial[ci+sizex*cj]+1]; jx++) {
#endif
if (matids[jx] == mat) {
rho_sum += rho_compact_list[jx] / dsqr[(nj+1)*3 + (ni+1)];
Nn += 1;

break;
}
}
}
else {

int mat_neighbour = jx - 1;
if (mat == mat_neighbour) {
rho_sum += rho_compact[ci+sizex*cj] / dsqr[(nj+1)*3 + (ni+1)];
Nn += 1;
}
} 
} 
} 
rho_mat_ave_compact[i+sizex*j] = rho_sum / Nn;
} 
}
}
}
#ifdef DEBUG
std::chrono::duration<double> t3 = std::chrono::system_clock::now() - t0;
printf("Compact matrix, cell centric, alg 3: %g sec\n", t3.count());
#endif
}

bool compact_check_results(full_data cc, compact_data ccc)
{
int sizex = cc.sizex;
int sizey = cc.sizey;
int Nmats = cc.Nmats;
int mmc_cells = ccc.mmc_cells;
int mm_len = ccc.mm_len;


printf("Checking results of compact representation... ");
for (int j = 0; j < sizey; j++) {
for (int i = 0; i < sizex; i++) {
if (fabs(cc.rho_ave[i+sizex*j] - ccc.rho_ave_compact[i+sizex*j]) > 0.0001) {
printf("1. full matrix and compact cell-centric values are not equal! (%f, %f, %d, %d)\n",
cc.rho_ave[i+sizex*j], ccc.rho_ave_compact[i+sizex*j], i, j);
return false;
}
int ix = ccc.imaterial[i+sizex*j];
if (ix <= 0) {
#ifdef LINKED
for (ix = -ix; ix >= 0; ix = ccc.nextfrac[ix]) {
#else
for (int ix = ccc.mmc_index[-ccc.imaterial[i+sizex*j]]; ix < ccc.mmc_index[-ccc.imaterial[i+sizex*j]+1]; ix++) {
#endif
int mat = ccc.matids[ix];
if (fabs(cc.p[(i+sizex*j)*Nmats+mat] - ccc.p_compact_list[ix]) > 0.0001) {
printf("2. full matrix and compact cell-centric values are not equal! (%f, %f, %d, %d, %d)\n",
cc.p[(i+sizex*j)*Nmats+mat], ccc.p_compact_list[ix], i, j, mat);
return false;
}

if (fabs(cc.rho_mat_ave[(i+sizex*j)*Nmats+mat] - ccc.rho_mat_ave_compact_list[ix]) > 0.0001) {
printf("3. full matrix and compact cell-centric values are not equal! (%f, %f, %d, %d, %d)\n",
cc.rho_mat_ave[(i+sizex*j)*Nmats+mat], ccc.rho_mat_ave_compact_list[ix], i, j, mat);
return false;
}
}
}
else {
int mat = ix - 1;
if (fabs(cc.p[(i+sizex*j)*Nmats+mat] - ccc.p_compact[i+sizex*j]) > 0.0001) {
printf("2. full matrix and compact cell-centric values are not equal! (%f, %f, %d, %d, %d)\n",
cc.p[(i+sizex*j)*Nmats+mat], ccc.p_compact[i+sizex*j], i, j, mat);
return false;
}

if (fabs(cc.rho_mat_ave[(i+sizex*j)*Nmats+mat] - ccc.rho_mat_ave_compact[i+sizex*j]) > 0.0001) {
printf("3. full matrix and compact cell-centric values are not equal! (%f, %f, %d, %d, %d)\n",
cc.rho_mat_ave[(i+sizex*j)*Nmats+mat], ccc.rho_mat_ave_compact[i+sizex*j], i, j, mat);
return false;
}
}
}
}
printf("All tests passed!\n");
return true;
}
