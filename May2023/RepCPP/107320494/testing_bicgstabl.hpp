

#pragma once
#ifndef TESTING_BICGSTABL_HPP
#define TESTING_BICGSTABL_HPP

#include "utility.hpp"

#include <rocalution/rocalution.hpp>

using namespace rocalution;

static bool check_residual(float res)
{
return (res < 1e-1f);
}

static bool check_residual(double res)
{
return (res < 1e-5);
}

template <typename T>
bool testing_bicgstabl(Arguments argus)
{
int          ndim    = argus.size;
std::string  precond = argus.precond;
unsigned int format  = argus.format;
int          l       = argus.index;

set_device_rocalution(device);
init_rocalution();

LocalMatrix<T> A;
LocalVector<T> x;
LocalVector<T> b;
LocalVector<T> e;

int* csr_ptr = NULL;
int* csr_col = NULL;
T*   csr_val = NULL;

int nrow = gen_2d_laplacian(ndim, &csr_ptr, &csr_col, &csr_val);
int nnz  = csr_ptr[nrow];

A.SetDataPtrCSR(&csr_ptr, &csr_col, &csr_val, "A", nnz, nrow, nrow);

A.MoveToAccelerator();
x.MoveToAccelerator();
b.MoveToAccelerator();
e.MoveToAccelerator();

x.Allocate("x", A.GetN());
b.Allocate("b", A.GetM());
e.Allocate("e", A.GetN());

e.Ones();
A.Apply(e, &b);

x.SetRandomUniform(12345ULL, -3.0, 4.0);

BiCGStabl<LocalMatrix<T>, LocalVector<T>, T> ls;

Preconditioner<LocalMatrix<T>, LocalVector<T>, T>* p;

if(precond == "None")
p = NULL;
else if(precond == "Chebyshev")
{

T lambda_min;
T lambda_max;

A.Gershgorin(lambda_min, lambda_max);

AIChebyshev<LocalMatrix<T>, LocalVector<T>, T>* cheb
= new AIChebyshev<LocalMatrix<T>, LocalVector<T>, T>;
cheb->Set(3, lambda_max / 7.0, lambda_max);

p = cheb;
}
else if(precond == "FSAI")
p = new FSAI<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "SPAI")
p = new SPAI<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "TNS")
p = new TNS<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "Jacobi")
p = new Jacobi<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "GS")
p = new GS<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "SGS")
p = new SGS<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "ILU")
p = new ILU<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "ILUT")
p = new ILUT<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "IC")
p = new IC<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "MCGS")
p = new MultiColoredGS<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "MCSGS")
p = new MultiColoredSGS<LocalMatrix<T>, LocalVector<T>, T>;
else if(precond == "MCILU")
p = new MultiColoredILU<LocalMatrix<T>, LocalVector<T>, T>;
else
return false;

ls.Verbose(0);
ls.SetOperator(A);

if(p != NULL)
{
ls.SetPreconditioner(*p);
}

ls.Init(1e-8, 0.0, 1e+8, 10000);
ls.SetOrder(l);
ls.Build();

A.ConvertTo(format, format == BCSR ? argus.blockdim : 1);

ls.Solve(b, &x);

x.ScaleAdd(-1.0, e);
T nrm2 = x.Norm();

bool success = check_residual(nrm2);

ls.Clear();
if(p != NULL)
{
delete p;
}

stop_rocalution();

return success;
}

#endif 