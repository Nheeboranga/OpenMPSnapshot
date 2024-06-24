#include <stdio.h>
#include <omp.h>

int main()
{
int x = 0;

#pragma omp parallel
{
#pragma omp critical
{
x += omp_get_thread_num();
}
}

printf("x: %d\n", x);
}
