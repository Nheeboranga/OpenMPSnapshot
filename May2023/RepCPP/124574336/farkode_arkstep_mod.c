






#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)


#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif


#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif


#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) 
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif


#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif


#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif


#ifndef SWIGEXTERN
# ifdef __cplusplus
#   define SWIGEXTERN extern
# else
#   define SWIGEXTERN
# endif
#endif


#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif


#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif


#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif


#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif


#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif


#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


#define  SWIG_UnknownError    	   -1
#define  SWIG_IOError        	   -2
#define  SWIG_RuntimeError   	   -3
#define  SWIG_IndexError     	   -4
#define  SWIG_TypeError      	   -5
#define  SWIG_DivisionByZero 	   -6
#define  SWIG_OverflowError  	   -7
#define  SWIG_SyntaxError    	   -8
#define  SWIG_ValueError     	   -9
#define  SWIG_SystemError    	   -10
#define  SWIG_AttributeError 	   -11
#define  SWIG_MemoryError    	   -12
#define  SWIG_NullReferenceError   -13




#include <assert.h>
#define SWIG_exception_impl(DECL, CODE, MSG, RETURNNULL) \
{ printf("In " DECL ": " MSG); assert(0); RETURNNULL; }


#include <stdio.h>
#if defined(_MSC_VER) || defined(__BORLANDC__) || defined(_WATCOM)
# ifndef snprintf
#  define snprintf _snprintf
# endif
#endif



#define SWIG_contract_assert(RETURNNULL, EXPR, MSG) \
if (!(EXPR)) { SWIG_exception_impl("$decl", SWIG_ValueError, MSG, RETURNNULL); } 


#define SWIGVERSION 0x040000 
#define SWIG_VERSION SWIGVERSION


#define SWIG_as_voidptr(a) (void *)((const void *)(a)) 
#define SWIG_as_voidptrptr(a) ((void)SWIG_as_voidptr(*a),(void**)(a)) 


#include "arkode/arkode_arkstep.h"


#include <stdlib.h>
#ifdef _MSC_VER
# ifndef strtoull
#  define strtoull _strtoui64
# endif
# ifndef strtoll
#  define strtoll _strtoi64
# endif
#endif


typedef struct {
void* data;
size_t size;
} SwigArrayWrapper;


SWIGINTERN SwigArrayWrapper SwigArrayWrapper_uninitialized() {
SwigArrayWrapper result;
result.data = NULL;
result.size = 0;
return result;
}


#include <string.h>

SWIGEXPORT void * _wrap_FARKStepCreate(ARKRhsFn farg1, ARKRhsFn farg2, double const *farg3, N_Vector farg4) {
void * fresult ;
ARKRhsFn arg1 = (ARKRhsFn) 0 ;
ARKRhsFn arg2 = (ARKRhsFn) 0 ;
realtype arg3 ;
N_Vector arg4 = (N_Vector) 0 ;
void *result = 0 ;

arg1 = (ARKRhsFn)(farg1);
arg2 = (ARKRhsFn)(farg2);
arg3 = (realtype)(*farg3);
arg4 = (N_Vector)(farg4);
result = (void *)ARKStepCreate(arg1,arg2,arg3,arg4);
fresult = result;
return fresult;
}


SWIGEXPORT int _wrap_FARKStepResize(void *farg1, N_Vector farg2, double const *farg3, double const *farg4, ARKVecResizeFn farg5, void *farg6) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
realtype arg3 ;
realtype arg4 ;
ARKVecResizeFn arg5 = (ARKVecResizeFn) 0 ;
void *arg6 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
arg3 = (realtype)(*farg3);
arg4 = (realtype)(*farg4);
arg5 = (ARKVecResizeFn)(farg5);
arg6 = (void *)(farg6);
result = (int)ARKStepResize(arg1,arg2,arg3,arg4,arg5,arg6);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepReInit(void *farg1, ARKRhsFn farg2, ARKRhsFn farg3, double const *farg4, N_Vector farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKRhsFn arg2 = (ARKRhsFn) 0 ;
ARKRhsFn arg3 = (ARKRhsFn) 0 ;
realtype arg4 ;
N_Vector arg5 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKRhsFn)(farg2);
arg3 = (ARKRhsFn)(farg3);
arg4 = (realtype)(*farg4);
arg5 = (N_Vector)(farg5);
result = (int)ARKStepReInit(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepReset(void *farg1, double const *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector)(farg3);
result = (int)ARKStepReset(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSStolerances(void *farg1, double const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)ARKStepSStolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSVtolerances(void *farg1, double const *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector)(farg3);
result = (int)ARKStepSVtolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepWFtolerances(void *farg1, ARKEwtFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKEwtFn arg2 = (ARKEwtFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKEwtFn)(farg2);
result = (int)ARKStepWFtolerances(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepResStolerance(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepResStolerance(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepResVtolerance(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)ARKStepResVtolerance(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepResFtolerance(void *farg1, ARKRwtFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKRwtFn arg2 = (ARKRwtFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKRwtFn)(farg2);
result = (int)ARKStepResFtolerance(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetLinearSolver(void *farg1, SUNLinearSolver farg2, SUNMatrix farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNLinearSolver arg2 = (SUNLinearSolver) 0 ;
SUNMatrix arg3 = (SUNMatrix) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNLinearSolver)(farg2);
arg3 = (SUNMatrix)(farg3);
result = (int)ARKStepSetLinearSolver(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMassLinearSolver(void *farg1, SUNLinearSolver farg2, SUNMatrix farg3, int const *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNLinearSolver arg2 = (SUNLinearSolver) 0 ;
SUNMatrix arg3 = (SUNMatrix) 0 ;
int arg4 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNLinearSolver)(farg2);
arg3 = (SUNMatrix)(farg3);
arg4 = (int)(*farg4);
result = (int)ARKStepSetMassLinearSolver(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepRootInit(void *farg1, int const *farg2, ARKRootFn farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
ARKRootFn arg3 = (ARKRootFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (ARKRootFn)(farg3);
result = (int)ARKStepRootInit(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetDefaults(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)ARKStepSetDefaults(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetOptimalParams(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)ARKStepSetOptimalParams(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetOrder(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetOrder(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetInterpolantType(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetInterpolantType(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetInterpolantDegree(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetInterpolantDegree(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetDenseOrder(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetDenseOrder(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetNonlinearSolver(void *farg1, SUNNonlinearSolver farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNNonlinearSolver arg2 = (SUNNonlinearSolver) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNNonlinearSolver)(farg2);
result = (int)ARKStepSetNonlinearSolver(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetLinear(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetLinear(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetNonlinear(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)ARKStepSetNonlinear(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetExplicit(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)ARKStepSetExplicit(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetImplicit(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)ARKStepSetImplicit(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetImEx(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)ARKStepSetImEx(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetTables(void *farg1, int const *farg2, int const *farg3, void *farg4, void *farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
ARKodeButcherTable arg4 = (ARKodeButcherTable) 0 ;
ARKodeButcherTable arg5 = (ARKodeButcherTable) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
arg4 = (ARKodeButcherTable)(farg4);
arg5 = (ARKodeButcherTable)(farg5);
result = (int)ARKStepSetTables(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetTableNum(void *farg1, int const *farg2, int const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
result = (int)ARKStepSetTableNum(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetCFLFraction(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetCFLFraction(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetSafetyFactor(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetSafetyFactor(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetErrorBias(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetErrorBias(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxGrowth(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMaxGrowth(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMinReduction(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMinReduction(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetFixedStepBounds(void *farg1, double const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)ARKStepSetFixedStepBounds(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetAdaptivityMethod(void *farg1, int const *farg2, int const *farg3, int const *farg4, double *farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
int arg4 ;
realtype *arg5 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
arg4 = (int)(*farg4);
arg5 = (double *)(farg5);
result = (int)ARKStepSetAdaptivityMethod(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetAdaptivityFn(void *farg1, ARKAdaptFn farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKAdaptFn arg2 = (ARKAdaptFn) 0 ;
void *arg3 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKAdaptFn)(farg2);
arg3 = (void *)(farg3);
result = (int)ARKStepSetAdaptivityFn(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxFirstGrowth(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMaxFirstGrowth(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxEFailGrowth(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMaxEFailGrowth(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetSmallNumEFails(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetSmallNumEFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxCFailGrowth(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMaxCFailGrowth(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetNonlinCRDown(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetNonlinCRDown(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetNonlinRDiv(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetNonlinRDiv(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetDeltaGammaMax(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetDeltaGammaMax(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetLSetupFrequency(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetLSetupFrequency(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetPredictorMethod(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetPredictorMethod(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetStabilityFn(void *farg1, ARKExpStabFn farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKExpStabFn arg2 = (ARKExpStabFn) 0 ;
void *arg3 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKExpStabFn)(farg2);
arg3 = (void *)(farg3);
result = (int)ARKStepSetStabilityFn(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxErrTestFails(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetMaxErrTestFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxNonlinIters(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetMaxNonlinIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxConvFails(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetMaxConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetNonlinConvCoef(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetNonlinConvCoef(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetConstraints(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)ARKStepSetConstraints(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxNumSteps(void *farg1, long const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long)(*farg2);
result = (int)ARKStepSetMaxNumSteps(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxHnilWarns(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetMaxHnilWarns(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetInitStep(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetInitStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMinStep(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMinStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxStep(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMaxStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetStopTime(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetStopTime(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetFixedStep(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetFixedStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxNumConstrFails(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetMaxNumConstrFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetRootDirection(void *farg1, int *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int *arg2 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int *)(farg2);
result = (int)ARKStepSetRootDirection(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetNoInactiveRootWarn(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)ARKStepSetNoInactiveRootWarn(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetErrHandlerFn(void *farg1, ARKErrHandlerFn farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKErrHandlerFn arg2 = (ARKErrHandlerFn) 0 ;
void *arg3 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKErrHandlerFn)(farg2);
arg3 = (void *)(farg3);
result = (int)ARKStepSetErrHandlerFn(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetErrFile(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
FILE *arg2 = (FILE *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (FILE *)(farg2);
result = (int)ARKStepSetErrFile(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetUserData(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
void *arg2 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (void *)(farg2);
result = (int)ARKStepSetUserData(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetDiagnostics(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
FILE *arg2 = (FILE *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (FILE *)(farg2);
result = (int)ARKStepSetDiagnostics(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetPostprocessStepFn(void *farg1, ARKPostProcessFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKPostProcessFn arg2 = (ARKPostProcessFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKPostProcessFn)(farg2);
result = (int)ARKStepSetPostprocessStepFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetPostprocessStageFn(void *farg1, ARKPostProcessFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKPostProcessFn arg2 = (ARKPostProcessFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKPostProcessFn)(farg2);
result = (int)ARKStepSetPostprocessStageFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetStagePredictFn(void *farg1, ARKStagePredictFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKStagePredictFn arg2 = (ARKStagePredictFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKStagePredictFn)(farg2);
result = (int)ARKStepSetStagePredictFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetJacFn(void *farg1, ARKLsJacFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKLsJacFn arg2 = (ARKLsJacFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKLsJacFn)(farg2);
result = (int)ARKStepSetJacFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMassFn(void *farg1, ARKLsMassFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKLsMassFn arg2 = (ARKLsMassFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKLsMassFn)(farg2);
result = (int)ARKStepSetMassFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetJacEvalFrequency(void *farg1, long const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long)(*farg2);
result = (int)ARKStepSetJacEvalFrequency(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetLinearSolutionScaling(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetLinearSolutionScaling(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetEpsLin(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetEpsLin(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMassEpsLin(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMassEpsLin(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetLSNormFactor(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetLSNormFactor(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMassLSNormFactor(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)ARKStepSetMassLSNormFactor(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetPreconditioner(void *farg1, ARKLsPrecSetupFn farg2, ARKLsPrecSolveFn farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKLsPrecSetupFn arg2 = (ARKLsPrecSetupFn) 0 ;
ARKLsPrecSolveFn arg3 = (ARKLsPrecSolveFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKLsPrecSetupFn)(farg2);
arg3 = (ARKLsPrecSolveFn)(farg3);
result = (int)ARKStepSetPreconditioner(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMassPreconditioner(void *farg1, ARKLsMassPrecSetupFn farg2, ARKLsMassPrecSolveFn farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKLsMassPrecSetupFn arg2 = (ARKLsMassPrecSetupFn) 0 ;
ARKLsMassPrecSolveFn arg3 = (ARKLsMassPrecSolveFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKLsMassPrecSetupFn)(farg2);
arg3 = (ARKLsMassPrecSolveFn)(farg3);
result = (int)ARKStepSetMassPreconditioner(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetJacTimes(void *farg1, ARKLsJacTimesSetupFn farg2, ARKLsJacTimesVecFn farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKLsJacTimesSetupFn arg2 = (ARKLsJacTimesSetupFn) 0 ;
ARKLsJacTimesVecFn arg3 = (ARKLsJacTimesVecFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKLsJacTimesSetupFn)(farg2);
arg3 = (ARKLsJacTimesVecFn)(farg3);
result = (int)ARKStepSetJacTimes(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetJacTimesRhsFn(void *farg1, ARKRhsFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKRhsFn arg2 = (ARKRhsFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKRhsFn)(farg2);
result = (int)ARKStepSetJacTimesRhsFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMassTimes(void *farg1, ARKLsMassTimesSetupFn farg2, ARKLsMassTimesVecFn farg3, void *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKLsMassTimesSetupFn arg2 = (ARKLsMassTimesSetupFn) 0 ;
ARKLsMassTimesVecFn arg3 = (ARKLsMassTimesVecFn) 0 ;
void *arg4 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKLsMassTimesSetupFn)(farg2);
arg3 = (ARKLsMassTimesVecFn)(farg3);
arg4 = (void *)(farg4);
result = (int)ARKStepSetMassTimes(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetLinSysFn(void *farg1, ARKLsLinSysFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKLsLinSysFn arg2 = (ARKLsLinSysFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKLsLinSysFn)(farg2);
result = (int)ARKStepSetLinSysFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepEvolve(void *farg1, double const *farg2, N_Vector farg3, double *farg4, int const *farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
realtype *arg4 = (realtype *) 0 ;
int arg5 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector)(farg3);
arg4 = (realtype *)(farg4);
arg5 = (int)(*farg5);
result = (int)ARKStepEvolve(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetDky(void *farg1, double const *farg2, int const *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int arg3 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (int)(*farg3);
arg4 = (N_Vector)(farg4);
result = (int)ARKStepGetDky(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepComputeState(void *farg1, N_Vector farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
arg3 = (N_Vector)(farg3);
result = (int)ARKStepComputeState(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumExpSteps(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumExpSteps(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumAccSteps(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumAccSteps(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumStepAttempts(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumStepAttempts(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumRhsEvals(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)ARKStepGetNumRhsEvals(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumLinSolvSetups(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumLinSolvSetups(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumErrTestFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumErrTestFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetCurrentButcherTables(void *farg1, void *farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
ARKodeButcherTable *arg2 = (ARKodeButcherTable *) 0 ;
ARKodeButcherTable *arg3 = (ARKodeButcherTable *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (ARKodeButcherTable *)(farg2);
arg3 = (ARKodeButcherTable *)(farg3);
result = (int)ARKStepGetCurrentButcherTables(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetEstLocalErrors(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)ARKStepGetEstLocalErrors(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetWorkSpace(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)ARKStepGetWorkSpace(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumSteps(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumSteps(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetActualInitStep(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)ARKStepGetActualInitStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetLastStep(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)ARKStepGetLastStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetCurrentStep(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)ARKStepGetCurrentStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetCurrentTime(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)ARKStepGetCurrentTime(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetCurrentState(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector *arg2 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector *)(farg2);
result = (int)ARKStepGetCurrentState(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetCurrentGamma(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)ARKStepGetCurrentGamma(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetCurrentMassMatrix(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNMatrix *arg2 = (SUNMatrix *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNMatrix *)(farg2);
result = (int)ARKStepGetCurrentMassMatrix(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetTolScaleFactor(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)ARKStepGetTolScaleFactor(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetErrWeights(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)ARKStepGetErrWeights(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetResWeights(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)ARKStepGetResWeights(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumGEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumGEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetRootInfo(void *farg1, int *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int *arg2 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int *)(farg2);
result = (int)ARKStepGetRootInfo(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumConstrFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumConstrFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT SwigArrayWrapper _wrap_FARKStepGetReturnFlagName(long const *farg1) {
SwigArrayWrapper fresult ;
long arg1 ;
char *result = 0 ;

arg1 = (long)(*farg1);
result = (char *)ARKStepGetReturnFlagName(arg1);
fresult.size = strlen((const char*)(result));
fresult.data = (char *)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepWriteParameters(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
FILE *arg2 = (FILE *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (FILE *)(farg2);
result = (int)ARKStepWriteParameters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepWriteButcher(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
FILE *arg2 = (FILE *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (FILE *)(farg2);
result = (int)ARKStepWriteButcher(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetTimestepperStats(void *farg1, long *farg2, long *farg3, long *farg4, long *farg5, long *farg6, long *farg7, long *farg8) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
long *arg4 = (long *) 0 ;
long *arg5 = (long *) 0 ;
long *arg6 = (long *) 0 ;
long *arg7 = (long *) 0 ;
long *arg8 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
arg4 = (long *)(farg4);
arg5 = (long *)(farg5);
arg6 = (long *)(farg6);
arg7 = (long *)(farg7);
arg8 = (long *)(farg8);
result = (int)ARKStepGetTimestepperStats(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetStepStats(void *farg1, long *farg2, double *farg3, double *farg4, double *farg5, double *farg6) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
realtype *arg3 = (realtype *) 0 ;
realtype *arg4 = (realtype *) 0 ;
realtype *arg5 = (realtype *) 0 ;
realtype *arg6 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (realtype *)(farg3);
arg4 = (realtype *)(farg4);
arg5 = (realtype *)(farg5);
arg6 = (realtype *)(farg6);
result = (int)ARKStepGetStepStats(arg1,arg2,arg3,arg4,arg5,arg6);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNonlinearSystemData(void *farg1, double *farg2, void *farg3, void *farg4, void *farg5, double *farg6, void *farg7, void *farg8) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
N_Vector *arg3 = (N_Vector *) 0 ;
N_Vector *arg4 = (N_Vector *) 0 ;
N_Vector *arg5 = (N_Vector *) 0 ;
realtype *arg6 = (realtype *) 0 ;
N_Vector *arg7 = (N_Vector *) 0 ;
void **arg8 = (void **) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (N_Vector *)(farg3);
arg4 = (N_Vector *)(farg4);
arg5 = (N_Vector *)(farg5);
arg6 = (realtype *)(farg6);
arg7 = (N_Vector *)(farg7);
arg8 = (void **)(farg8);
result = (int)ARKStepGetNonlinearSystemData(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumNonlinSolvIters(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumNonlinSolvIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumNonlinSolvConvFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumNonlinSolvConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNonlinSolvStats(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)ARKStepGetNonlinSolvStats(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetLinWorkSpace(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)ARKStepGetLinWorkSpace(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumJacEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumJacEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumPrecEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumPrecEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumPrecSolves(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumPrecSolves(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumLinIters(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumLinIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumLinConvFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumLinConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumJTSetupEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumJTSetupEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumJtimesEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumJtimesEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumLinRhsEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumLinRhsEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetLastLinFlag(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetLastLinFlag(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetMassWorkSpace(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)ARKStepGetMassWorkSpace(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMassSetups(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMassSetups(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMassMultSetups(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMassMultSetups(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMassMult(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMassMult(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMassSolves(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMassSolves(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMassPrecEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMassPrecEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMassPrecSolves(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMassPrecSolves(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMassIters(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMassIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMassConvFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMassConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetNumMTSetups(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetNumMTSetups(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepGetLastMassFlag(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)ARKStepGetLastMassFlag(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT SwigArrayWrapper _wrap_FARKStepGetLinReturnFlagName(long const *farg1) {
SwigArrayWrapper fresult ;
long arg1 ;
char *result = 0 ;

arg1 = (long)(*farg1);
result = (char *)ARKStepGetLinReturnFlagName(arg1);
fresult.size = strlen((const char*)(result));
fresult.data = (char *)(result);
return fresult;
}


SWIGEXPORT void _wrap_FARKStepFree(void *farg1) {
void **arg1 = (void **) 0 ;

arg1 = (void **)(farg1);
ARKStepFree(arg1);
}


SWIGEXPORT void _wrap_FARKStepPrintMem(void *farg1, void *farg2) {
void *arg1 = (void *) 0 ;
FILE *arg2 = (FILE *) 0 ;

arg1 = (void *)(farg1);
arg2 = (FILE *)(farg2);
ARKStepPrintMem(arg1,arg2);
}


SWIGEXPORT int _wrap_FARKStepSetMaxStepsBetweenLSet(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)ARKStepSetMaxStepsBetweenLSet(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FARKStepSetMaxStepsBetweenJac(void *farg1, long const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long)(*farg2);
result = (int)ARKStepSetMaxStepsBetweenJac(arg1,arg2);
fresult = (int)(result);
return fresult;
}



