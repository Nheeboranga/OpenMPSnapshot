#if defined(__STDC__)
#  if (__STDC_VERSION__ >= 199901L)
#     define _XOPEN_SOURCE 700
#  endif
#endif
#if !defined(_OPENMP)
#error "OpenMP support needed for this code"
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#if defined(_OPENMP)
#define CPU_TIME (clock_gettime( CLOCK_REALTIME, &ts ), (double)ts.tv_sec + \
(double)ts.tv_nsec * 1e-9)
#define CPU_TIME_th (clock_gettime( CLOCK_THREAD_CPUTIME_ID, &myts ), (double)myts.tv_sec +	\
(double)myts.tv_nsec * 1e-9)
#else
#define CPU_TIME (clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &ts ), (double)ts.tv_sec + \
(double)ts.tv_nsec * 1e-9)
#endif
#define N_default 100
int main( int argc, char **argv )
{
unsigned long long int N = N_default;
int     nthreads = 1;  
double *array;
struct  timespec ts;
if ( argc > 1 )
N = (unsigned long long int)atoll( *(argv+1) );
#pragma omp parallel
#pragma omp master
nthreads = omp_get_num_threads();
printf("omp summation with %d threads\n", nthreads );
if ( (array = (double*)malloc( N* sizeof(double) )) == NULL )
{
printf("I'm sorry, there is not enough memory to host %llu bytes\n",
N * sizeof(double) );
return 1;
}
#pragma omp parallel for
for ( int ii = 0; ii < N; ii++ )
array[ii] = (double)ii;
double S           = 0;                                   
double tstart      = CPU_TIME;
#pragma omp parallel for reduction(+:S)
for (int ii = 0; ii < N; ii++ )
S += array[ii];
double tend = CPU_TIME;
printf("Sum is %g, process took %g of wall-clock time\n\n",
S, tend - tstart );
free( array );
return 0;
}