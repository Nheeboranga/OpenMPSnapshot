#include <omp.h>
main ()  {
int   i, n;
float a[100], b[100], sum; 
n = 100;
for (i=0; i < n; i++)
a[i] = b[i] = i * 1.0;
sum = 0.0;
#pragma omp parallel for reduction(+:sum)
for (i=0; i < n; i++)
sum = sum + (a[i] * b[i]);
printf("   Sum = %f\n",sum);
}
