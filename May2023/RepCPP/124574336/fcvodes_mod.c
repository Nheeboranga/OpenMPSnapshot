






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
{STAN_SUNDIALS_PRINTF("In " DECL ": " MSG); assert(0); RETURNNULL; }


enum {
SWIG_MEM_OWN = 0x01,
SWIG_MEM_RVALUE = 0x02,
SWIG_MEM_CONST = 0x04
};


#define SWIG_check_mutable(SWIG_CLASS_WRAPPER, TYPENAME, FNAME, FUNCNAME, RETURNNULL) \
if ((SWIG_CLASS_WRAPPER).cmemflags & SWIG_MEM_CONST) { \
SWIG_exception_impl(FUNCNAME, SWIG_TypeError, \
"Cannot pass const " TYPENAME " (class " FNAME ") " \
"as a mutable reference", \
RETURNNULL); \
}


#define SWIG_check_nonnull(SWIG_CLASS_WRAPPER, TYPENAME, FNAME, FUNCNAME, RETURNNULL) \
if (!(SWIG_CLASS_WRAPPER).cptr) { \
SWIG_exception_impl(FUNCNAME, SWIG_TypeError, \
"Cannot pass null " TYPENAME " (class " FNAME ") " \
"as a reference", RETURNNULL); \
}


#define SWIG_check_mutable_nonnull(SWIG_CLASS_WRAPPER, TYPENAME, FNAME, FUNCNAME, RETURNNULL) \
SWIG_check_nonnull(SWIG_CLASS_WRAPPER, TYPENAME, FNAME, FUNCNAME, RETURNNULL); \
SWIG_check_mutable(SWIG_CLASS_WRAPPER, TYPENAME, FNAME, FUNCNAME, RETURNNULL);


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


#include "cvodes/cvodes.h"
#include "cvodes/cvodes_bandpre.h"
#include "cvodes/cvodes_bbdpre.h"
#include "cvodes/cvodes_diag.h"
#include "cvodes/cvodes_ls.h"


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


typedef struct {
void* cptr;
int cmemflags;
} SwigClassWrapper;


SWIGINTERN SwigClassWrapper SwigClassWrapper_uninitialized() {
SwigClassWrapper result;
result.cptr = NULL;
result.cmemflags = 0;
return result;
}


SWIGINTERN void SWIG_assign(SwigClassWrapper* self, SwigClassWrapper other) {
if (self->cptr == NULL) {

if (other.cmemflags & SWIG_MEM_RVALUE) {

self->cptr = other.cptr;
self->cmemflags = other.cmemflags & (~SWIG_MEM_RVALUE);
} else {

self->cptr = other.cptr;
self->cmemflags = other.cmemflags & (~SWIG_MEM_OWN);
}
} else if (other.cptr == NULL) {

free(self->cptr);
*self = SwigClassWrapper_uninitialized();
} else {
if (self->cmemflags & SWIG_MEM_OWN) {
free(self->cptr);
}
self->cptr = other.cptr;
if (other.cmemflags & SWIG_MEM_RVALUE) {

self->cmemflags = other.cmemflags & ~SWIG_MEM_RVALUE;
} else {

self->cmemflags = other.cmemflags & ~SWIG_MEM_OWN;
}
}
}

SWIGEXPORT void * _wrap_FCVodeCreate(int const *farg1, void *farg2) {
void * fresult ;
int arg1 ;
SUNContext arg2 = (SUNContext) 0 ;
void *result = 0 ;

arg1 = (int)(*farg1);
arg2 = (SUNContext)(farg2);
result = (void *)CVodeCreate(arg1,arg2);
fresult = result;
return fresult;
}


SWIGEXPORT int _wrap_FCVodeInit(void *farg1, CVRhsFn farg2, double const *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
CVRhsFn arg2 = (CVRhsFn) 0 ;
realtype arg3 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVRhsFn)(farg2);
arg3 = (realtype)(*farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeInit(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeReInit(void *farg1, double const *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeReInit(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSStolerances(void *farg1, double const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)CVodeSStolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSVtolerances(void *farg1, double const *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeSVtolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeWFtolerances(void *farg1, CVEwtFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
CVEwtFn arg2 = (CVEwtFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVEwtFn)(farg2);
result = (int)CVodeWFtolerances(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetConstraints(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)CVodeSetConstraints(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetErrFile(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
FILE *arg2 = (FILE *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (FILE *)(farg2);
result = (int)CVodeSetErrFile(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetErrHandlerFn(void *farg1, CVErrHandlerFn farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
CVErrHandlerFn arg2 = (CVErrHandlerFn) 0 ;
void *arg3 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVErrHandlerFn)(farg2);
arg3 = (void *)(farg3);
result = (int)CVodeSetErrHandlerFn(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetInitStep(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)CVodeSetInitStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLSetupFrequency(void *farg1, long const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long)(*farg2);
result = (int)CVodeSetLSetupFrequency(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxConvFails(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetMaxConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxErrTestFails(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetMaxErrTestFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxHnilWarns(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetMaxHnilWarns(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxNonlinIters(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetMaxNonlinIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxNumSteps(void *farg1, long const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long)(*farg2);
result = (int)CVodeSetMaxNumSteps(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxOrd(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetMaxOrd(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxStep(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)CVodeSetMaxStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMinStep(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)CVodeSetMinStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMonitorFn(void *farg1, CVMonitorFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
CVMonitorFn arg2 = (CVMonitorFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVMonitorFn)(farg2);
result = (int)CVodeSetMonitorFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMonitorFrequency(void *farg1, long const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long)(*farg2);
result = (int)CVodeSetMonitorFrequency(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetNlsRhsFn(void *farg1, CVRhsFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
CVRhsFn arg2 = (CVRhsFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVRhsFn)(farg2);
result = (int)CVodeSetNlsRhsFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetNonlinConvCoef(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)CVodeSetNonlinConvCoef(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetNonlinearSolver(void *farg1, SUNNonlinearSolver farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNNonlinearSolver arg2 = (SUNNonlinearSolver) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNNonlinearSolver)(farg2);
result = (int)CVodeSetNonlinearSolver(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetStabLimDet(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetStabLimDet(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetStopTime(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)CVodeSetStopTime(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetUserData(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
void *arg2 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (void *)(farg2);
result = (int)CVodeSetUserData(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeRootInit(void *farg1, int const *farg2, CVRootFn farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVRootFn arg3 = (CVRootFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVRootFn)(farg3);
result = (int)CVodeRootInit(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetRootDirection(void *farg1, int *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int *arg2 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int *)(farg2);
result = (int)CVodeSetRootDirection(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetNoInactiveRootWarn(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)CVodeSetNoInactiveRootWarn(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVode(void *farg1, double const *farg2, N_Vector farg3, double *farg4, int const *farg5) {
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
result = (int)CVode(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeComputeState(void *farg1, N_Vector farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeComputeState(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeComputeStateSens(void *farg1, void *farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector *arg2 = (N_Vector *) 0 ;
N_Vector *arg3 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector *)(farg2);
arg3 = (N_Vector *)(farg3);
result = (int)CVodeComputeStateSens(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeComputeStateSens1(void *farg1, int const *farg2, N_Vector farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (N_Vector)(farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeComputeStateSens1(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetDky(void *farg1, double const *farg2, int const *farg3, N_Vector farg4) {
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
result = (int)CVodeGetDky(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetWorkSpace(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVodeGetWorkSpace(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumSteps(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumSteps(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumRhsEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumRhsEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumLinSolvSetups(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumLinSolvSetups(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumErrTestFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumErrTestFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetLastOrder(void *farg1, int *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int *arg2 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int *)(farg2);
result = (int)CVodeGetLastOrder(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetCurrentOrder(void *farg1, int *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int *arg2 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int *)(farg2);
result = (int)CVodeGetCurrentOrder(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetCurrentGamma(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)CVodeGetCurrentGamma(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumStabLimOrderReds(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumStabLimOrderReds(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetActualInitStep(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)CVodeGetActualInitStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetLastStep(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)CVodeGetLastStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetCurrentStep(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)CVodeGetCurrentStep(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetCurrentState(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector *arg2 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector *)(farg2);
result = (int)CVodeGetCurrentState(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetCurrentStateSens(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector **arg2 = (N_Vector **) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector **)(farg2);
result = (int)CVodeGetCurrentStateSens(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetCurrentSensSolveIndex(void *farg1, int *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int *arg2 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int *)(farg2);
result = (int)CVodeGetCurrentSensSolveIndex(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetCurrentTime(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)CVodeGetCurrentTime(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetTolScaleFactor(void *farg1, double *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
result = (int)CVodeGetTolScaleFactor(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetErrWeights(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)CVodeGetErrWeights(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetEstLocalErrors(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)CVodeGetEstLocalErrors(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumGEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumGEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetRootInfo(void *farg1, int *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int *arg2 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int *)(farg2);
result = (int)CVodeGetRootInfo(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetIntegratorStats(void *farg1, long *farg2, long *farg3, long *farg4, long *farg5, int *farg6, int *farg7, double *farg8, double *farg9, double *farg10, double *farg11) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
long *arg4 = (long *) 0 ;
long *arg5 = (long *) 0 ;
int *arg6 = (int *) 0 ;
int *arg7 = (int *) 0 ;
realtype *arg8 = (realtype *) 0 ;
realtype *arg9 = (realtype *) 0 ;
realtype *arg10 = (realtype *) 0 ;
realtype *arg11 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
arg4 = (long *)(farg4);
arg5 = (long *)(farg5);
arg6 = (int *)(farg6);
arg7 = (int *)(farg7);
arg8 = (realtype *)(farg8);
arg9 = (realtype *)(farg9);
arg10 = (realtype *)(farg10);
arg11 = (realtype *)(farg11);
result = (int)CVodeGetIntegratorStats(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNonlinearSystemData(void *farg1, double *farg2, void *farg3, void *farg4, void *farg5, double *farg6, double *farg7, void *farg8, void *farg9) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
N_Vector *arg3 = (N_Vector *) 0 ;
N_Vector *arg4 = (N_Vector *) 0 ;
N_Vector *arg5 = (N_Vector *) 0 ;
realtype *arg6 = (realtype *) 0 ;
realtype *arg7 = (realtype *) 0 ;
N_Vector *arg8 = (N_Vector *) 0 ;
void **arg9 = (void **) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (N_Vector *)(farg3);
arg4 = (N_Vector *)(farg4);
arg5 = (N_Vector *)(farg5);
arg6 = (realtype *)(farg6);
arg7 = (realtype *)(farg7);
arg8 = (N_Vector *)(farg8);
arg9 = (void **)(farg9);
result = (int)CVodeGetNonlinearSystemData(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNonlinearSystemDataSens(void *farg1, double *farg2, void *farg3, void *farg4, double *farg5, double *farg6, void *farg7, void *farg8) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
N_Vector **arg3 = (N_Vector **) 0 ;
N_Vector **arg4 = (N_Vector **) 0 ;
realtype *arg5 = (realtype *) 0 ;
realtype *arg6 = (realtype *) 0 ;
N_Vector **arg7 = (N_Vector **) 0 ;
void **arg8 = (void **) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (N_Vector **)(farg3);
arg4 = (N_Vector **)(farg4);
arg5 = (realtype *)(farg5);
arg6 = (realtype *)(farg6);
arg7 = (N_Vector **)(farg7);
arg8 = (void **)(farg8);
result = (int)CVodeGetNonlinearSystemDataSens(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumNonlinSolvIters(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumNonlinSolvIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumNonlinSolvConvFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumNonlinSolvConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNonlinSolvStats(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVodeGetNonlinSolvStats(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT SwigArrayWrapper _wrap_FCVodeGetReturnFlagName(long const *farg1) {
SwigArrayWrapper fresult ;
long arg1 ;
char *result = 0 ;

arg1 = (long)(*farg1);
result = (char *)CVodeGetReturnFlagName(arg1);
fresult.size = strlen((const char*)(result));
fresult.data = (char *)(result);
return fresult;
}


SWIGEXPORT void _wrap_FCVodeFree(void *farg1) {
void **arg1 = (void **) 0 ;

arg1 = (void **)(farg1);
CVodeFree(arg1);
}


SWIGEXPORT int _wrap_FCVodeSetJacTimesRhsFn(void *farg1, CVRhsFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
CVRhsFn arg2 = (CVRhsFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVRhsFn)(farg2);
result = (int)CVodeSetJacTimesRhsFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadInit(void *farg1, CVQuadRhsFn farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
CVQuadRhsFn arg2 = (CVQuadRhsFn) 0 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVQuadRhsFn)(farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeQuadInit(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadReInit(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)CVodeQuadReInit(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadSStolerances(void *farg1, double const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)CVodeQuadSStolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadSVtolerances(void *farg1, double const *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeQuadSVtolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetQuadErrCon(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetQuadErrCon(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuad(void *farg1, double *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeGetQuad(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadDky(void *farg1, double const *farg2, int const *farg3, N_Vector farg4) {
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
result = (int)CVodeGetQuadDky(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadNumRhsEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetQuadNumRhsEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadNumErrTestFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetQuadNumErrTestFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadErrWeights(void *farg1, N_Vector farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector)(farg2);
result = (int)CVodeGetQuadErrWeights(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadStats(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVodeGetQuadStats(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT void _wrap_FCVodeQuadFree(void *farg1) {
void *arg1 = (void *) 0 ;

arg1 = (void *)(farg1);
CVodeQuadFree(arg1);
}


SWIGEXPORT int _wrap_FCVodeSensInit(void *farg1, int const *farg2, int const *farg3, CVSensRhsFn farg4, void *farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
CVSensRhsFn arg4 = (CVSensRhsFn) 0 ;
N_Vector *arg5 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
arg4 = (CVSensRhsFn)(farg4);
arg5 = (N_Vector *)(farg5);
result = (int)CVodeSensInit(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSensInit1(void *farg1, int const *farg2, int const *farg3, CVSensRhs1Fn farg4, void *farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
CVSensRhs1Fn arg4 = (CVSensRhs1Fn) 0 ;
N_Vector *arg5 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
arg4 = (CVSensRhs1Fn)(farg4);
arg5 = (N_Vector *)(farg5);
result = (int)CVodeSensInit1(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSensReInit(void *farg1, int const *farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
N_Vector *arg3 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (N_Vector *)(farg3);
result = (int)CVodeSensReInit(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSensSStolerances(void *farg1, double const *farg2, double *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
realtype *arg3 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (realtype *)(farg3);
result = (int)CVodeSensSStolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSensSVtolerances(void *farg1, double const *farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector *arg3 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector *)(farg3);
result = (int)CVodeSensSVtolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSensEEtolerances(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)CVodeSensEEtolerances(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetSensDQMethod(void *farg1, int const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)CVodeSetSensDQMethod(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetSensErrCon(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetSensErrCon(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetSensMaxNonlinIters(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetSensMaxNonlinIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetSensParams(void *farg1, double *farg2, double *farg3, int *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
realtype *arg3 = (realtype *) 0 ;
int *arg4 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (realtype *)(farg3);
arg4 = (int *)(farg4);
result = (int)CVodeSetSensParams(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetNonlinearSolverSensSim(void *farg1, SUNNonlinearSolver farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNNonlinearSolver arg2 = (SUNNonlinearSolver) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNNonlinearSolver)(farg2);
result = (int)CVodeSetNonlinearSolverSensSim(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetNonlinearSolverSensStg(void *farg1, SUNNonlinearSolver farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNNonlinearSolver arg2 = (SUNNonlinearSolver) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNNonlinearSolver)(farg2);
result = (int)CVodeSetNonlinearSolverSensStg(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetNonlinearSolverSensStg1(void *farg1, SUNNonlinearSolver farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNNonlinearSolver arg2 = (SUNNonlinearSolver) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNNonlinearSolver)(farg2);
result = (int)CVodeSetNonlinearSolverSensStg1(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSensToggleOff(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)CVodeSensToggleOff(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSens(void *farg1, double *farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
N_Vector *arg3 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (N_Vector *)(farg3);
result = (int)CVodeGetSens(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSens1(void *farg1, double *farg2, int const *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int arg3 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (int)(*farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeGetSens1(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensDky(void *farg1, double const *farg2, int const *farg3, void *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int arg3 ;
N_Vector *arg4 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (int)(*farg3);
arg4 = (N_Vector *)(farg4);
result = (int)CVodeGetSensDky(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensDky1(void *farg1, double const *farg2, int const *farg3, int const *farg4, N_Vector farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int arg3 ;
int arg4 ;
N_Vector arg5 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (int)(*farg3);
arg4 = (int)(*farg4);
arg5 = (N_Vector)(farg5);
result = (int)CVodeGetSensDky1(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensNumRhsEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetSensNumRhsEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumRhsEvalsSens(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumRhsEvalsSens(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensNumErrTestFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetSensNumErrTestFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensNumLinSolvSetups(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetSensNumLinSolvSetups(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensErrWeights(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector *arg2 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector *)(farg2);
result = (int)CVodeGetSensErrWeights(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensStats(void *farg1, long *farg2, long *farg3, long *farg4, long *farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
long *arg4 = (long *) 0 ;
long *arg5 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
arg4 = (long *)(farg4);
arg5 = (long *)(farg5);
result = (int)CVodeGetSensStats(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensNumNonlinSolvIters(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetSensNumNonlinSolvIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensNumNonlinSolvConvFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetSensNumNonlinSolvConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetSensNonlinSolvStats(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVodeGetSensNonlinSolvStats(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetStgrSensNumNonlinSolvIters(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetStgrSensNumNonlinSolvIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetStgrSensNumNonlinSolvConvFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetStgrSensNumNonlinSolvConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetStgrSensNonlinSolvStats(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVodeGetStgrSensNonlinSolvStats(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT void _wrap_FCVodeSensFree(void *farg1) {
void *arg1 = (void *) 0 ;

arg1 = (void *)(farg1);
CVodeSensFree(arg1);
}


SWIGEXPORT int _wrap_FCVodeQuadSensInit(void *farg1, CVQuadSensRhsFn farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
CVQuadSensRhsFn arg2 = (CVQuadSensRhsFn) 0 ;
N_Vector *arg3 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVQuadSensRhsFn)(farg2);
arg3 = (N_Vector *)(farg3);
result = (int)CVodeQuadSensInit(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadSensReInit(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector *arg2 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector *)(farg2);
result = (int)CVodeQuadSensReInit(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadSensSStolerances(void *farg1, double const *farg2, double *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
realtype *arg3 = (realtype *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (realtype *)(farg3);
result = (int)CVodeQuadSensSStolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadSensSVtolerances(void *farg1, double const *farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector *arg3 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector *)(farg3);
result = (int)CVodeQuadSensSVtolerances(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadSensEEtolerances(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)CVodeQuadSensEEtolerances(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetQuadSensErrCon(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetQuadSensErrCon(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadSens(void *farg1, double *farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
N_Vector *arg3 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (N_Vector *)(farg3);
result = (int)CVodeGetQuadSens(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadSens1(void *farg1, double *farg2, int const *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype *arg2 = (realtype *) 0 ;
int arg3 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype *)(farg2);
arg3 = (int)(*farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeGetQuadSens1(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadSensDky(void *farg1, double const *farg2, int const *farg3, void *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int arg3 ;
N_Vector *arg4 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (int)(*farg3);
arg4 = (N_Vector *)(farg4);
result = (int)CVodeGetQuadSensDky(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadSensDky1(void *farg1, double const *farg2, int const *farg3, int const *farg4, N_Vector farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int arg3 ;
int arg4 ;
N_Vector arg5 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (int)(*farg3);
arg4 = (int)(*farg4);
arg5 = (N_Vector)(farg5);
result = (int)CVodeGetQuadSensDky1(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadSensNumRhsEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetQuadSensNumRhsEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadSensNumErrTestFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetQuadSensNumErrTestFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadSensErrWeights(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
N_Vector *arg2 = (N_Vector *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (N_Vector *)(farg2);
result = (int)CVodeGetQuadSensErrWeights(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadSensStats(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVodeGetQuadSensStats(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT void _wrap_FCVodeQuadSensFree(void *farg1) {
void *arg1 = (void *) 0 ;

arg1 = (void *)(farg1);
CVodeQuadSensFree(arg1);
}


SWIGEXPORT int _wrap_FCVodeAdjInit(void *farg1, long const *farg2, int const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long arg2 ;
int arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long)(*farg2);
arg3 = (int)(*farg3);
result = (int)CVodeAdjInit(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeAdjReInit(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)CVodeAdjReInit(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT void _wrap_FCVodeAdjFree(void *farg1) {
void *arg1 = (void *) 0 ;

arg1 = (void *)(farg1);
CVodeAdjFree(arg1);
}


SWIGEXPORT int _wrap_FCVodeCreateB(void *farg1, int const *farg2, int *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int *arg3 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int *)(farg3);
result = (int)CVodeCreateB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeInitB(void *farg1, int const *farg2, CVRhsFnB farg3, double const *farg4, N_Vector farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVRhsFnB arg3 = (CVRhsFnB) 0 ;
realtype arg4 ;
N_Vector arg5 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVRhsFnB)(farg3);
arg4 = (realtype)(*farg4);
arg5 = (N_Vector)(farg5);
result = (int)CVodeInitB(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeInitBS(void *farg1, int const *farg2, CVRhsFnBS farg3, double const *farg4, N_Vector farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVRhsFnBS arg3 = (CVRhsFnBS) 0 ;
realtype arg4 ;
N_Vector arg5 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVRhsFnBS)(farg3);
arg4 = (realtype)(*farg4);
arg5 = (N_Vector)(farg5);
result = (int)CVodeInitBS(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeReInitB(void *farg1, int const *farg2, double const *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeReInitB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSStolerancesB(void *farg1, int const *farg2, double const *farg3, double const *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
realtype arg4 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
arg4 = (realtype)(*farg4);
result = (int)CVodeSStolerancesB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSVtolerancesB(void *farg1, int const *farg2, double const *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeSVtolerancesB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadInitB(void *farg1, int const *farg2, CVQuadRhsFnB farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVQuadRhsFnB arg3 = (CVQuadRhsFnB) 0 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVQuadRhsFnB)(farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeQuadInitB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadInitBS(void *farg1, int const *farg2, CVQuadRhsFnBS farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVQuadRhsFnBS arg3 = (CVQuadRhsFnBS) 0 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVQuadRhsFnBS)(farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeQuadInitBS(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadReInitB(void *farg1, int const *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeQuadReInitB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadSStolerancesB(void *farg1, int const *farg2, double const *farg3, double const *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
realtype arg4 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
arg4 = (realtype)(*farg4);
result = (int)CVodeQuadSStolerancesB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeQuadSVtolerancesB(void *farg1, int const *farg2, double const *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeQuadSVtolerancesB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeF(void *farg1, double const *farg2, N_Vector farg3, double *farg4, int const *farg5, int *farg6) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
realtype *arg4 = (realtype *) 0 ;
int arg5 ;
int *arg6 = (int *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector)(farg3);
arg4 = (realtype *)(farg4);
arg5 = (int)(*farg5);
arg6 = (int *)(farg6);
result = (int)CVodeF(arg1,arg2,arg3,arg4,arg5,arg6);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeB(void *farg1, double const *farg2, int const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (int)(*farg3);
result = (int)CVodeB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetAdjNoSensi(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)CVodeSetAdjNoSensi(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetUserDataB(void *farg1, int const *farg2, void *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
void *arg3 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (void *)(farg3);
result = (int)CVodeSetUserDataB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxOrdB(void *farg1, int const *farg2, int const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
result = (int)CVodeSetMaxOrdB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxNumStepsB(void *farg1, int const *farg2, long const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
long arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (long)(*farg3);
result = (int)CVodeSetMaxNumStepsB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetStabLimDetB(void *farg1, int const *farg2, int const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
result = (int)CVodeSetStabLimDetB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetInitStepB(void *farg1, int const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)CVodeSetInitStepB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMinStepB(void *farg1, int const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)CVodeSetMinStepB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetMaxStepB(void *farg1, int const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)CVodeSetMaxStepB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetConstraintsB(void *farg1, int const *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeSetConstraintsB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetQuadErrConB(void *farg1, int const *farg2, int const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
result = (int)CVodeSetQuadErrConB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetNonlinearSolverB(void *farg1, int const *farg2, SUNNonlinearSolver farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
SUNNonlinearSolver arg3 = (SUNNonlinearSolver) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (SUNNonlinearSolver)(farg3);
result = (int)CVodeSetNonlinearSolverB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetB(void *farg1, int const *farg2, double *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype *arg3 = (realtype *) 0 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype *)(farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeGetB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetQuadB(void *farg1, int const *farg2, double *farg3, N_Vector farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype *arg3 = (realtype *) 0 ;
N_Vector arg4 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype *)(farg3);
arg4 = (N_Vector)(farg4);
result = (int)CVodeGetQuadB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT void * _wrap_FCVodeGetAdjCVodeBmem(void *farg1, int const *farg2) {
void * fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
void *result = 0 ;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (void *)CVodeGetAdjCVodeBmem(arg1,arg2);
fresult = result;
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetAdjY(void *farg1, double const *farg2, N_Vector farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
arg3 = (N_Vector)(farg3);
result = (int)CVodeGetAdjY(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT void _wrap_CVadjCheckPointRec_my_addr_set(SwigClassWrapper const *farg1, void *farg2) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
void *arg2 = (void *) 0 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::my_addr", return );
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
arg2 = (void *)(farg2);
if (arg1) (arg1)->my_addr = arg2;
}


SWIGEXPORT void * _wrap_CVadjCheckPointRec_my_addr_get(SwigClassWrapper const *farg1) {
void * fresult ;
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
void *result = 0 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::my_addr", return 0);
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
result = (void *) ((arg1)->my_addr);
fresult = result;
return fresult;
}


SWIGEXPORT void _wrap_CVadjCheckPointRec_next_addr_set(SwigClassWrapper const *farg1, void *farg2) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
void *arg2 = (void *) 0 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::next_addr", return );
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
arg2 = (void *)(farg2);
if (arg1) (arg1)->next_addr = arg2;
}


SWIGEXPORT void * _wrap_CVadjCheckPointRec_next_addr_get(SwigClassWrapper const *farg1) {
void * fresult ;
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
void *result = 0 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::next_addr", return 0);
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
result = (void *) ((arg1)->next_addr);
fresult = result;
return fresult;
}


SWIGEXPORT void _wrap_CVadjCheckPointRec_t0_set(SwigClassWrapper const *farg1, double const *farg2) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
realtype arg2 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::t0", return );
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
arg2 = (realtype)(*farg2);
if (arg1) (arg1)->t0 = arg2;
}


SWIGEXPORT double _wrap_CVadjCheckPointRec_t0_get(SwigClassWrapper const *farg1) {
double fresult ;
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
realtype result;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::t0", return 0);
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
result = (realtype) ((arg1)->t0);
fresult = (realtype)(result);
return fresult;
}


SWIGEXPORT void _wrap_CVadjCheckPointRec_t1_set(SwigClassWrapper const *farg1, double const *farg2) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
realtype arg2 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::t1", return );
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
arg2 = (realtype)(*farg2);
if (arg1) (arg1)->t1 = arg2;
}


SWIGEXPORT double _wrap_CVadjCheckPointRec_t1_get(SwigClassWrapper const *farg1) {
double fresult ;
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
realtype result;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::t1", return 0);
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
result = (realtype) ((arg1)->t1);
fresult = (realtype)(result);
return fresult;
}


SWIGEXPORT void _wrap_CVadjCheckPointRec_nstep_set(SwigClassWrapper const *farg1, long const *farg2) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
long arg2 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::nstep", return );
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
arg2 = (long)(*farg2);
if (arg1) (arg1)->nstep = arg2;
}


SWIGEXPORT long _wrap_CVadjCheckPointRec_nstep_get(SwigClassWrapper const *farg1) {
long fresult ;
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
long result;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::nstep", return 0);
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
result = (long) ((arg1)->nstep);
fresult = (long)(result);
return fresult;
}


SWIGEXPORT void _wrap_CVadjCheckPointRec_order_set(SwigClassWrapper const *farg1, int const *farg2) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
int arg2 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::order", return );
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
arg2 = (int)(*farg2);
if (arg1) (arg1)->order = arg2;
}


SWIGEXPORT int _wrap_CVadjCheckPointRec_order_get(SwigClassWrapper const *farg1) {
int fresult ;
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
int result;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::order", return 0);
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
result = (int) ((arg1)->order);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT void _wrap_CVadjCheckPointRec_step_set(SwigClassWrapper const *farg1, double const *farg2) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
realtype arg2 ;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::step", return );
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
arg2 = (realtype)(*farg2);
if (arg1) (arg1)->step = arg2;
}


SWIGEXPORT double _wrap_CVadjCheckPointRec_step_get(SwigClassWrapper const *farg1) {
double fresult ;
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
realtype result;

SWIG_check_mutable_nonnull(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::step", return 0);
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
result = (realtype) ((arg1)->step);
fresult = (realtype)(result);
return fresult;
}


SWIGEXPORT SwigClassWrapper _wrap_new_CVadjCheckPointRec() {
SwigClassWrapper fresult ;
CVadjCheckPointRec *result = 0 ;

result = (CVadjCheckPointRec *)calloc(1, sizeof(CVadjCheckPointRec));
fresult.cptr = result;
fresult.cmemflags = SWIG_MEM_RVALUE | (1 ? SWIG_MEM_OWN : 0);
return fresult;
}


SWIGEXPORT void _wrap_delete_CVadjCheckPointRec(SwigClassWrapper *farg1) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;

SWIG_check_mutable(*farg1, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVadjCheckPointRec::~CVadjCheckPointRec()", return );
arg1 = (CVadjCheckPointRec *)(farg1->cptr);
free((char *) arg1);
}


SWIGEXPORT void _wrap_CVadjCheckPointRec_op_assign__(SwigClassWrapper *farg1, SwigClassWrapper const *farg2) {
CVadjCheckPointRec *arg1 = (CVadjCheckPointRec *) 0 ;
CVadjCheckPointRec *arg2 = 0 ;

(void)sizeof(arg1);
(void)sizeof(arg2);
SWIG_assign(farg1, *farg2);

}


SWIGEXPORT int _wrap_FCVodeGetAdjCheckPointsInfo(void *farg1, SwigClassWrapper const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
CVadjCheckPointRec *arg2 = (CVadjCheckPointRec *) 0 ;
int result;

arg1 = (void *)(farg1);
SWIG_check_mutable(*farg2, "CVadjCheckPointRec *", "CVadjCheckPointRec", "CVodeGetAdjCheckPointsInfo(void *,CVadjCheckPointRec *)", return 0);
arg2 = (CVadjCheckPointRec *)(farg2->cptr);
result = (int)CVodeGetAdjCheckPointsInfo(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetJacTimesRhsFnB(void *farg1, int const *farg2, CVRhsFn farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVRhsFn arg3 = (CVRhsFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVRhsFn)(farg3);
result = (int)CVodeSetJacTimesRhsFnB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetAdjDataPointHermite(void *farg1, int const *farg2, double *farg3, N_Vector farg4, N_Vector farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype *arg3 = (realtype *) 0 ;
N_Vector arg4 = (N_Vector) 0 ;
N_Vector arg5 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype *)(farg3);
arg4 = (N_Vector)(farg4);
arg5 = (N_Vector)(farg5);
result = (int)CVodeGetAdjDataPointHermite(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetAdjDataPointPolynomial(void *farg1, int const *farg2, double *farg3, int *farg4, N_Vector farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype *arg3 = (realtype *) 0 ;
int *arg4 = (int *) 0 ;
N_Vector arg5 = (N_Vector) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype *)(farg3);
arg4 = (int *)(farg4);
arg5 = (N_Vector)(farg5);
result = (int)CVodeGetAdjDataPointPolynomial(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetAdjCurrentCheckPoint(void *farg1, void *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
void **arg2 = (void **) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (void **)(farg2);
result = (int)CVodeGetAdjCurrentCheckPoint(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBandPrecInit(void *farg1, int64_t const *farg2, int64_t const *farg3, int64_t const *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
sunindextype arg2 ;
sunindextype arg3 ;
sunindextype arg4 ;
int result;

arg1 = (void *)(farg1);
arg2 = (sunindextype)(*farg2);
arg3 = (sunindextype)(*farg3);
arg4 = (sunindextype)(*farg4);
result = (int)CVBandPrecInit(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBandPrecGetWorkSpace(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVBandPrecGetWorkSpace(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBandPrecGetNumRhsEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVBandPrecGetNumRhsEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBandPrecInitB(void *farg1, int const *farg2, int64_t const *farg3, int64_t const *farg4, int64_t const *farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
sunindextype arg3 ;
sunindextype arg4 ;
sunindextype arg5 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (sunindextype)(*farg3);
arg4 = (sunindextype)(*farg4);
arg5 = (sunindextype)(*farg5);
result = (int)CVBandPrecInitB(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBBDPrecInit(void *farg1, int64_t const *farg2, int64_t const *farg3, int64_t const *farg4, int64_t const *farg5, int64_t const *farg6, double const *farg7, CVLocalFn farg8, CVCommFn farg9) {
int fresult ;
void *arg1 = (void *) 0 ;
sunindextype arg2 ;
sunindextype arg3 ;
sunindextype arg4 ;
sunindextype arg5 ;
sunindextype arg6 ;
realtype arg7 ;
CVLocalFn arg8 = (CVLocalFn) 0 ;
CVCommFn arg9 = (CVCommFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (sunindextype)(*farg2);
arg3 = (sunindextype)(*farg3);
arg4 = (sunindextype)(*farg4);
arg5 = (sunindextype)(*farg5);
arg6 = (sunindextype)(*farg6);
arg7 = (realtype)(*farg7);
arg8 = (CVLocalFn)(farg8);
arg9 = (CVCommFn)(farg9);
result = (int)CVBBDPrecInit(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBBDPrecReInit(void *farg1, int64_t const *farg2, int64_t const *farg3, double const *farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
sunindextype arg2 ;
sunindextype arg3 ;
realtype arg4 ;
int result;

arg1 = (void *)(farg1);
arg2 = (sunindextype)(*farg2);
arg3 = (sunindextype)(*farg3);
arg4 = (realtype)(*farg4);
result = (int)CVBBDPrecReInit(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBBDPrecGetWorkSpace(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVBBDPrecGetWorkSpace(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBBDPrecGetNumGfnEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVBBDPrecGetNumGfnEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBBDPrecInitB(void *farg1, int const *farg2, int64_t const *farg3, int64_t const *farg4, int64_t const *farg5, int64_t const *farg6, int64_t const *farg7, double const *farg8, CVLocalFnB farg9, CVCommFnB farg10) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
sunindextype arg3 ;
sunindextype arg4 ;
sunindextype arg5 ;
sunindextype arg6 ;
sunindextype arg7 ;
realtype arg8 ;
CVLocalFnB arg9 = (CVLocalFnB) 0 ;
CVCommFnB arg10 = (CVCommFnB) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (sunindextype)(*farg3);
arg4 = (sunindextype)(*farg4);
arg5 = (sunindextype)(*farg5);
arg6 = (sunindextype)(*farg6);
arg7 = (sunindextype)(*farg7);
arg8 = (realtype)(*farg8);
arg9 = (CVLocalFnB)(farg9);
arg10 = (CVCommFnB)(farg10);
result = (int)CVBBDPrecInitB(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVBBDPrecReInitB(void *farg1, int const *farg2, int64_t const *farg3, int64_t const *farg4, double const *farg5) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
sunindextype arg3 ;
sunindextype arg4 ;
realtype arg5 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (sunindextype)(*farg3);
arg4 = (sunindextype)(*farg4);
arg5 = (realtype)(*farg5);
result = (int)CVBBDPrecReInitB(arg1,arg2,arg3,arg4,arg5);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVDiag(void *farg1) {
int fresult ;
void *arg1 = (void *) 0 ;
int result;

arg1 = (void *)(farg1);
result = (int)CVDiag(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVDiagGetWorkSpace(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVDiagGetWorkSpace(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVDiagGetNumRhsEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVDiagGetNumRhsEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVDiagGetLastFlag(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVDiagGetLastFlag(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT SwigArrayWrapper _wrap_FCVDiagGetReturnFlagName(long const *farg1) {
SwigArrayWrapper fresult ;
long arg1 ;
char *result = 0 ;

arg1 = (long)(*farg1);
result = (char *)CVDiagGetReturnFlagName(arg1);
fresult.size = strlen((const char*)(result));
fresult.data = (char *)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVDiagB(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVDiagB(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLinearSolver(void *farg1, SUNLinearSolver farg2, SUNMatrix farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
SUNLinearSolver arg2 = (SUNLinearSolver) 0 ;
SUNMatrix arg3 = (SUNMatrix) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (SUNLinearSolver)(farg2);
arg3 = (SUNMatrix)(farg3);
result = (int)CVodeSetLinearSolver(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetJacFn(void *farg1, CVLsJacFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
CVLsJacFn arg2 = (CVLsJacFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVLsJacFn)(farg2);
result = (int)CVodeSetJacFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetJacEvalFrequency(void *farg1, long const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long)(*farg2);
result = (int)CVodeSetJacEvalFrequency(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLinearSolutionScaling(void *farg1, int const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
result = (int)CVodeSetLinearSolutionScaling(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetEpsLin(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)CVodeSetEpsLin(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLSNormFactor(void *farg1, double const *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
realtype arg2 ;
int result;

arg1 = (void *)(farg1);
arg2 = (realtype)(*farg2);
result = (int)CVodeSetLSNormFactor(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetPreconditioner(void *farg1, CVLsPrecSetupFn farg2, CVLsPrecSolveFn farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
CVLsPrecSetupFn arg2 = (CVLsPrecSetupFn) 0 ;
CVLsPrecSolveFn arg3 = (CVLsPrecSolveFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVLsPrecSetupFn)(farg2);
arg3 = (CVLsPrecSolveFn)(farg3);
result = (int)CVodeSetPreconditioner(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetJacTimes(void *farg1, CVLsJacTimesSetupFn farg2, CVLsJacTimesVecFn farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
CVLsJacTimesSetupFn arg2 = (CVLsJacTimesSetupFn) 0 ;
CVLsJacTimesVecFn arg3 = (CVLsJacTimesVecFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVLsJacTimesSetupFn)(farg2);
arg3 = (CVLsJacTimesVecFn)(farg3);
result = (int)CVodeSetJacTimes(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLinSysFn(void *farg1, CVLsLinSysFn farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
CVLsLinSysFn arg2 = (CVLsLinSysFn) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (CVLsLinSysFn)(farg2);
result = (int)CVodeSetLinSysFn(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetLinWorkSpace(void *farg1, long *farg2, long *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)CVodeGetLinWorkSpace(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumJacEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumJacEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumPrecEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumPrecEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumPrecSolves(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumPrecSolves(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumLinIters(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumLinIters(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumLinConvFails(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumLinConvFails(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumJTSetupEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumJTSetupEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumJtimesEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumJtimesEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetNumLinRhsEvals(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetNumLinRhsEvals(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetLinSolveStats(void *farg1, long *farg2, long *farg3, long *farg4, long *farg5, long *farg6, long *farg7, long *farg8, long *farg9) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
long *arg4 = (long *) 0 ;
long *arg5 = (long *) 0 ;
long *arg6 = (long *) 0 ;
long *arg7 = (long *) 0 ;
long *arg8 = (long *) 0 ;
long *arg9 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
arg4 = (long *)(farg4);
arg5 = (long *)(farg5);
arg6 = (long *)(farg6);
arg7 = (long *)(farg7);
arg8 = (long *)(farg8);
arg9 = (long *)(farg9);
result = (int)CVodeGetLinSolveStats(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeGetLastLinFlag(void *farg1, long *farg2) {
int fresult ;
void *arg1 = (void *) 0 ;
long *arg2 = (long *) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (long *)(farg2);
result = (int)CVodeGetLastLinFlag(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT SwigArrayWrapper _wrap_FCVodeGetLinReturnFlagName(long const *farg1) {
SwigArrayWrapper fresult ;
long arg1 ;
char *result = 0 ;

arg1 = (long)(*farg1);
result = (char *)CVodeGetLinReturnFlagName(arg1);
fresult.size = strlen((const char*)(result));
fresult.data = (char *)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLinearSolverB(void *farg1, int const *farg2, SUNLinearSolver farg3, SUNMatrix farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
SUNLinearSolver arg3 = (SUNLinearSolver) 0 ;
SUNMatrix arg4 = (SUNMatrix) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (SUNLinearSolver)(farg3);
arg4 = (SUNMatrix)(farg4);
result = (int)CVodeSetLinearSolverB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetJacFnB(void *farg1, int const *farg2, CVLsJacFnB farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVLsJacFnB arg3 = (CVLsJacFnB) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVLsJacFnB)(farg3);
result = (int)CVodeSetJacFnB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetJacFnBS(void *farg1, int const *farg2, CVLsJacFnBS farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVLsJacFnBS arg3 = (CVLsJacFnBS) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVLsJacFnBS)(farg3);
result = (int)CVodeSetJacFnBS(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetEpsLinB(void *farg1, int const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)CVodeSetEpsLinB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLSNormFactorB(void *farg1, int const *farg2, double const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
realtype arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (realtype)(*farg3);
result = (int)CVodeSetLSNormFactorB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLinearSolutionScalingB(void *farg1, int const *farg2, int const *farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
int arg3 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (int)(*farg3);
result = (int)CVodeSetLinearSolutionScalingB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetPreconditionerB(void *farg1, int const *farg2, CVLsPrecSetupFnB farg3, CVLsPrecSolveFnB farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVLsPrecSetupFnB arg3 = (CVLsPrecSetupFnB) 0 ;
CVLsPrecSolveFnB arg4 = (CVLsPrecSolveFnB) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVLsPrecSetupFnB)(farg3);
arg4 = (CVLsPrecSolveFnB)(farg4);
result = (int)CVodeSetPreconditionerB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetPreconditionerBS(void *farg1, int const *farg2, CVLsPrecSetupFnBS farg3, CVLsPrecSolveFnBS farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVLsPrecSetupFnBS arg3 = (CVLsPrecSetupFnBS) 0 ;
CVLsPrecSolveFnBS arg4 = (CVLsPrecSolveFnBS) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVLsPrecSetupFnBS)(farg3);
arg4 = (CVLsPrecSolveFnBS)(farg4);
result = (int)CVodeSetPreconditionerBS(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetJacTimesB(void *farg1, int const *farg2, CVLsJacTimesSetupFnB farg3, CVLsJacTimesVecFnB farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVLsJacTimesSetupFnB arg3 = (CVLsJacTimesSetupFnB) 0 ;
CVLsJacTimesVecFnB arg4 = (CVLsJacTimesVecFnB) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVLsJacTimesSetupFnB)(farg3);
arg4 = (CVLsJacTimesVecFnB)(farg4);
result = (int)CVodeSetJacTimesB(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetJacTimesBS(void *farg1, int const *farg2, CVLsJacTimesSetupFnBS farg3, CVLsJacTimesVecFnBS farg4) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVLsJacTimesSetupFnBS arg3 = (CVLsJacTimesSetupFnBS) 0 ;
CVLsJacTimesVecFnBS arg4 = (CVLsJacTimesVecFnBS) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVLsJacTimesSetupFnBS)(farg3);
arg4 = (CVLsJacTimesVecFnBS)(farg4);
result = (int)CVodeSetJacTimesBS(arg1,arg2,arg3,arg4);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLinSysFnB(void *farg1, int const *farg2, CVLsLinSysFnB farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVLsLinSysFnB arg3 = (CVLsLinSysFnB) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVLsLinSysFnB)(farg3);
result = (int)CVodeSetLinSysFnB(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FCVodeSetLinSysFnBS(void *farg1, int const *farg2, CVLsLinSysFnBS farg3) {
int fresult ;
void *arg1 = (void *) 0 ;
int arg2 ;
CVLsLinSysFnBS arg3 = (CVLsLinSysFnBS) 0 ;
int result;

arg1 = (void *)(farg1);
arg2 = (int)(*farg2);
arg3 = (CVLsLinSysFnBS)(farg3);
result = (int)CVodeSetLinSysFnBS(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}



