#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "ompvv.h"
#define ARRAY_SIZE 1024
int test_target_simd_safelen() {
OMPVV_INFOMSG("test_target_simd_safelen");
OMPVV_WARNING("This test cannot check if actual SIMD extensions at the hardware level" \
" were used, or of the generated code is different in any way");
int errors = 0;
int A[ARRAY_SIZE];
int A_host[ARRAY_SIZE];
int i, len;
for (i = 0; i < ARRAY_SIZE; ++i) {
A[i] = 1;
A_host[i] = 1;
}
#pragma omp target simd safelen(1) map(tofrom: A[0:ARRAY_SIZE])
for (i = 1; i < ARRAY_SIZE; ++i) {
A[i-1] += A[i]; 
}
#pragma omp target simd safelen(5) map(tofrom: A[0:ARRAY_SIZE])
for (i = 5; i < ARRAY_SIZE; ++i) {
A[i-5] += A[i]; 
}
#pragma omp target simd safelen(8) map(tofrom: A[0:ARRAY_SIZE])
for (i = 8; i < ARRAY_SIZE; ++i) {
A[i-8] += A[i]; 
}
#pragma omp target simd safelen(13) map(tofrom: A[0:ARRAY_SIZE])
for (i = 13; i < ARRAY_SIZE; ++i) {
A[i-13] += A[i]; 
}
#pragma omp target simd safelen(16) map(tofrom: A[0:ARRAY_SIZE])
for (i = 16; i < ARRAY_SIZE; ++i) {
A[i-16] += A[i]; 
}
#pragma omp target simd safelen(100) map(tofrom: A[0:ARRAY_SIZE])
for (i = 100; i < ARRAY_SIZE; ++i) {
A[i-100] += A[i]; 
}
#pragma omp target simd safelen(128) map(tofrom: A[0:ARRAY_SIZE])
for (i = 128; i < ARRAY_SIZE; ++i) {
A[i-128] += A[i]; 
}
for (i = 1; i < ARRAY_SIZE; ++i) {
A_host[i-1] += A_host[i]; 
}
for (i = 5; i < ARRAY_SIZE; ++i) {
A_host[i-5] += A_host[i]; 
}
for (i = 8; i < ARRAY_SIZE; ++i) {
A_host[i-8] += A_host[i]; 
}
for (i = 13; i < ARRAY_SIZE; ++i) {
A_host[i-13] += A_host[i]; 
}
for (i = 16; i < ARRAY_SIZE; ++i) {
A_host[i-16] += A_host[i]; 
}
for (i = 100; i < ARRAY_SIZE; ++i) {
A_host[i-100] += A_host[i]; 
}
for (i = 128; i < ARRAY_SIZE; ++i) {
A_host[i-128] += A_host[i]; 
}
for (i = 0; i < ARRAY_SIZE; ++i) {
OMPVV_TEST_AND_SET(errors, (A[i] != A_host[i]));
}
return errors;
}
int main() {
OMPVV_TEST_OFFLOADING;
int errors = 0;
OMPVV_TEST_AND_SET_VERBOSE(errors, test_target_simd_safelen());
OMPVV_REPORT_AND_RETURN(errors);
}
