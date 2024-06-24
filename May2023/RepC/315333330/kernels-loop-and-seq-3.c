#include <stdlib.h>
#define N 32
unsigned int
foo (int n, unsigned int *a)
{
#pragma acc kernels copy (a[0:N])
{
for (int i = 0; i < n; i++)
a[i] = 1;
a[0] = 2;
}
return a[0];
}
int
main (void)
{
unsigned int a[N];
unsigned res, i;
for (i = 0; i < N; ++i)
a[i] = i % 4;
res = foo (N, a);
if (res != 2)
abort ();
return 0;
}
