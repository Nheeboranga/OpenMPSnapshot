#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define M 512 
double CLOCK() {
struct timespec t;
clock_gettime(CLOCK_MONOTONIC,  &t);
return (t.tv_sec * 1000)+(t.tv_nsec*1e-6);
}
int main(int argc, char **argv)
{
int i,j,k;
double start, finish, total, sum;
float  a[M][M], b[M][M], c[M][M];
for (i=0; i<M; i++)
for (j=0; j<M; j++)
{
if ((i+j)%7 == 0)
a[i][j] = 2.;
else a[i][j] = 0.;
}
for (i=0; i<M; i++)
for (j=0; j<M; j++)
b[i][j] = (i/3)+(j/5); 
for (i=0; i<M; i++)
for (j=0; j<M; j++)
c[i][j] = 0.;
start = CLOCK();
double nz_val;
int nz_i;
int nz_k;
for (i=1; i<M; i++){
for (k=1; k<M; k++) {
if (a[i][k] != 0) {
nz_val = a[i][k];
nz_i = i;
nz_k = k;
break;
}
}
break;
}
const int nz_pattern = nz_i + nz_k;
#pragma omp parallel private(i,j,k) firstprivate(nz_pattern,nz_val) shared(c,b) default(none)
{
#pragma omp for
for (i=0; i<M; i++){
for (k=0; k<M; k++) {
if ((i+k)%nz_pattern == 0) { 
for (j=0; j<M; j++) {
c[i][j] += nz_val*b[k][j];
}
}
}
}
}
finish = CLOCK();
total = finish - start;
printf("Time for the loop = %f\n", total);
printf("The value of c[%d][%d] = %4.2f\n", 0, 0, c[0][0]);
printf("The value of c[%d][%d] = %4.2f\n", 31, 32, c[31][32]);
printf("The value of c[%d][%d] = %4.2f\n", 510, 0, c[510][0]);
printf("The value of c[%d][%d] = %4.2f\n", 511, 511, c[511][511]);
return 0;
}
