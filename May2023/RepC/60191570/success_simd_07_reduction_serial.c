#include <stdio.h>
#include <math.h>
int main()
{
int i;
int s = 0;
int t = 0;
int d = 0;
float e = 0.0f;
float f = 0.0f;
int N = 104;
#pragma omp simd reduction(+:s,f,t) 
for(i=0; i<N; i++)
{
s += (i+1);
f += (i+1.0f);
}
#pragma omp simd reduction(-:d, e) 
for(i=0; i<N; i++)
{
d -= (i+1);
e -= (i+1.0f);
}
printf("%d %f %d %f %d\n", s, f, d, e, t);
if ((s != 5460) || (f != 5460.0f)
|| (d != -5460) || (e != -5460.0f)
|| (t != 0))
{
printf("FAILED\n");
return 1;
}
return 0;
}
