#include<assert.h>
struct A
{
int m,n;
A(int _n, int _m) : n(_n), m(_m) { }
void foo(int &a, int &b)
{
#pragma omp task inout(a,b) input(n,m)
{
a++;
b++;
n++;
m++;
}
}
};
void foo()
{
A a(1, 2);
int n1 = 3, m1 = 4;
a.foo(n1, m1);
#pragma omp taskwait
assert(n1 == 4);
assert(m1 == 5);
assert(a.n == 2);
assert(a.m == 3);
}
int main() 
{
foo();    
}
