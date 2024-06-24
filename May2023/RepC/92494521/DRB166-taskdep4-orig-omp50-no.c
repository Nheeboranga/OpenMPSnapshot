#include <stdio.h>
#include <omp.h>
void foo(){
int x = 0, y = 2;
#pragma omp task depend(inout: x) shared(x)
x++;                                                
#pragma omp task shared(y)
y--;                                                
#pragma omp taskwait depend(in: x)                  
printf("x=%d\n",x);
#pragma omp taskwait                                
printf("y=%d\n",y);
}
int main(){
#pragma omp parallel
#pragma omp single
foo();
return 0;
}