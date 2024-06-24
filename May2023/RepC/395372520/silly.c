#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main() 
{
omp_set_num_threads(2);   
int i, j, n = 30000; 
int *in = (int*) calloc(n, sizeof(int));
int *pos = (int*) calloc(n, sizeof(int));   
int *out = (int*) calloc(n, sizeof(int));   
#pragma omp parallel for 
for(i=0; i < n; i++)
in[i] = n-i;  
#pragma omp parallel for collapse(2) schedule(guided)
for(i=0; i < n; i++) 
for(j=0; j < n; j++)
if(in[i] > in[j]) 
pos[i]++;	
#pragma omp parallel for 
for(i=0; i < n; i++) 
out[pos[i]] = in[i];
#pragma omp parallel for  
for(i=0; i < n; i++)
if(i+1 != out[i]) 
{
printf("test failed\n");
exit(0);
}
printf("test passed\n"); 
} 