#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <polybench.h>
#include "correlation.h"
static
void init_array (int m,
int n,
DATA_TYPE *float_n,
DATA_TYPE POLYBENCH_2D(data,M,N,m,n))
{
int i, j;
*float_n = 1.2;
for (i = 0; i < m; i++)
for (j = 0; j < n; j++)
data[i][j] = ((DATA_TYPE) i*j) / M;
}
static
void print_array(int m,
DATA_TYPE POLYBENCH_2D(symmat,M,M,m,m))
{
int i, j;
for (i = 0; i < m; i++)
for (j = 0; j < m; j++) {
fprintf (stderr, DATA_PRINTF_MODIFIER, symmat[i][j]);
if ((i * m + j) % 20 == 0) fprintf (stderr, "\n");
}
fprintf (stderr, "\n");
}
static
void kernel_correlation(int m, int n,
DATA_TYPE float_n,
DATA_TYPE POLYBENCH_2D(data,M,N,m,n),
DATA_TYPE POLYBENCH_2D(symmat,M,M,m,m),
DATA_TYPE POLYBENCH_1D(mean,M,m),
DATA_TYPE POLYBENCH_1D(stddev,M,m))
{
int i, j, j1, j2;
DATA_TYPE eps = 0.1f;
#define sqrt_of_array_cell(x,j) sqrt(x[j])
#pragma scop
for (j = 0; j < _PB_M; j++)
{
mean[j] = 0.0;
for (i = 0; i < _PB_N; i++)
mean[j] += data[i][j];
mean[j] /= float_n;
}
for (j = 0; j < _PB_M; j++)
{
stddev[j] = 0.0;
for (i = 0; i < _PB_N; i++)
stddev[j] += (data[i][j] - mean[j]) * (data[i][j] - mean[j]);
stddev[j] /= float_n;
stddev[j] = sqrt_of_array_cell(stddev, j);
stddev[j] = stddev[j] <= eps ? 1.0 : stddev[j];
}
for (i = 0; i < _PB_N; i++)
for (j = 0; j < _PB_M; j++)
{
data[i][j] -= mean[j];
data[i][j] /= sqrt(float_n) * stddev[j];
}
for (j1 = 0; j1 < _PB_M-1; j1++)
{
symmat[j1][j1] = 1.0;
for (j2 = j1+1; j2 < _PB_M; j2++)
{
symmat[j1][j2] = 0.0;
for (i = 0; i < _PB_N; i++)
symmat[j1][j2] += (data[i][j1] * data[i][j2]);
symmat[j2][j1] = symmat[j1][j2];
}
}
symmat[_PB_M-1][_PB_M-1] = 1.0;
#pragma endscop
}
int main(int argc, char** argv)
{
int n = N;
int m = M;
DATA_TYPE float_n;
POLYBENCH_2D_ARRAY_DECL(data,DATA_TYPE,M,N,m,n);
POLYBENCH_2D_ARRAY_DECL(symmat,DATA_TYPE,M,M,m,m);
POLYBENCH_1D_ARRAY_DECL(mean,DATA_TYPE,M,m);
POLYBENCH_1D_ARRAY_DECL(stddev,DATA_TYPE,M,m);
init_array (m, n, &float_n, POLYBENCH_ARRAY(data));
polybench_start_instruments;
kernel_correlation (m, n, float_n,
POLYBENCH_ARRAY(data),
POLYBENCH_ARRAY(symmat),
POLYBENCH_ARRAY(mean),
POLYBENCH_ARRAY(stddev));
polybench_stop_instruments;
polybench_print_instruments;
polybench_prevent_dce(print_array(m, POLYBENCH_ARRAY(symmat)));
POLYBENCH_FREE_ARRAY(data);
POLYBENCH_FREE_ARRAY(symmat);
POLYBENCH_FREE_ARRAY(mean);
POLYBENCH_FREE_ARRAY(stddev);
return 0;
}
