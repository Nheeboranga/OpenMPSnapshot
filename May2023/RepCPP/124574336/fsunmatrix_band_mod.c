






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


#include "sundials/sundials_matrix.h"


#include "sunmatrix/sunmatrix_band.h"

SWIGEXPORT SUNMatrix _wrap_FSUNBandMatrix(int64_t const *farg1, int64_t const *farg2, int64_t const *farg3, void *farg4) {
SUNMatrix fresult ;
sunindextype arg1 ;
sunindextype arg2 ;
sunindextype arg3 ;
SUNContext arg4 = (SUNContext) 0 ;
SUNMatrix result;

arg1 = (sunindextype)(*farg1);
arg2 = (sunindextype)(*farg2);
arg3 = (sunindextype)(*farg3);
arg4 = (SUNContext)(farg4);
result = (SUNMatrix)SUNBandMatrix(arg1,arg2,arg3,arg4);
fresult = result;
return fresult;
}


SWIGEXPORT SUNMatrix _wrap_FSUNBandMatrixStorage(int64_t const *farg1, int64_t const *farg2, int64_t const *farg3, int64_t const *farg4, void *farg5) {
SUNMatrix fresult ;
sunindextype arg1 ;
sunindextype arg2 ;
sunindextype arg3 ;
sunindextype arg4 ;
SUNContext arg5 = (SUNContext) 0 ;
SUNMatrix result;

arg1 = (sunindextype)(*farg1);
arg2 = (sunindextype)(*farg2);
arg3 = (sunindextype)(*farg3);
arg4 = (sunindextype)(*farg4);
arg5 = (SUNContext)(farg5);
result = (SUNMatrix)SUNBandMatrixStorage(arg1,arg2,arg3,arg4,arg5);
fresult = result;
return fresult;
}


SWIGEXPORT void _wrap_FSUNBandMatrix_Print(SUNMatrix farg1, void *farg2) {
SUNMatrix arg1 = (SUNMatrix) 0 ;
FILE *arg2 = (FILE *) 0 ;

arg1 = (SUNMatrix)(farg1);
arg2 = (FILE *)(farg2);
SUNBandMatrix_Print(arg1,arg2);
}


SWIGEXPORT int64_t _wrap_FSUNBandMatrix_Rows(SUNMatrix farg1) {
int64_t fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
sunindextype result;

arg1 = (SUNMatrix)(farg1);
result = SUNBandMatrix_Rows(arg1);
fresult = (sunindextype)(result);
return fresult;
}


SWIGEXPORT int64_t _wrap_FSUNBandMatrix_Columns(SUNMatrix farg1) {
int64_t fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
sunindextype result;

arg1 = (SUNMatrix)(farg1);
result = SUNBandMatrix_Columns(arg1);
fresult = (sunindextype)(result);
return fresult;
}


SWIGEXPORT int64_t _wrap_FSUNBandMatrix_LowerBandwidth(SUNMatrix farg1) {
int64_t fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
sunindextype result;

arg1 = (SUNMatrix)(farg1);
result = SUNBandMatrix_LowerBandwidth(arg1);
fresult = (sunindextype)(result);
return fresult;
}


SWIGEXPORT int64_t _wrap_FSUNBandMatrix_UpperBandwidth(SUNMatrix farg1) {
int64_t fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
sunindextype result;

arg1 = (SUNMatrix)(farg1);
result = SUNBandMatrix_UpperBandwidth(arg1);
fresult = (sunindextype)(result);
return fresult;
}


SWIGEXPORT int64_t _wrap_FSUNBandMatrix_StoredUpperBandwidth(SUNMatrix farg1) {
int64_t fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
sunindextype result;

arg1 = (SUNMatrix)(farg1);
result = SUNBandMatrix_StoredUpperBandwidth(arg1);
fresult = (sunindextype)(result);
return fresult;
}


SWIGEXPORT int64_t _wrap_FSUNBandMatrix_LDim(SUNMatrix farg1) {
int64_t fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
sunindextype result;

arg1 = (SUNMatrix)(farg1);
result = SUNBandMatrix_LDim(arg1);
fresult = (sunindextype)(result);
return fresult;
}


SWIGEXPORT double * _wrap_FSUNBandMatrix_Data(SUNMatrix farg1) {
double * fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
realtype *result = 0 ;

arg1 = (SUNMatrix)(farg1);
result = (realtype *)SUNBandMatrix_Data(arg1);
fresult = result;
return fresult;
}


SWIGEXPORT void * _wrap_FSUNBandMatrix_Cols(SUNMatrix farg1) {
void * fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
realtype **result = 0 ;

arg1 = (SUNMatrix)(farg1);
result = (realtype **)SUNBandMatrix_Cols(arg1);
fresult = result;
return fresult;
}


SWIGEXPORT double * _wrap_FSUNBandMatrix_Column(SUNMatrix farg1, int64_t const *farg2) {
double * fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
sunindextype arg2 ;
realtype *result = 0 ;

arg1 = (SUNMatrix)(farg1);
arg2 = (sunindextype)(*farg2);
result = (realtype *)SUNBandMatrix_Column(arg1,arg2);
fresult = result;
return fresult;
}


SWIGEXPORT int _wrap_FSUNMatGetID_Band(SUNMatrix farg1) {
int fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
SUNMatrix_ID result;

arg1 = (SUNMatrix)(farg1);
result = (SUNMatrix_ID)SUNMatGetID_Band(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT SUNMatrix _wrap_FSUNMatClone_Band(SUNMatrix farg1) {
SUNMatrix fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
SUNMatrix result;

arg1 = (SUNMatrix)(farg1);
result = (SUNMatrix)SUNMatClone_Band(arg1);
fresult = result;
return fresult;
}


SWIGEXPORT void _wrap_FSUNMatDestroy_Band(SUNMatrix farg1) {
SUNMatrix arg1 = (SUNMatrix) 0 ;

arg1 = (SUNMatrix)(farg1);
SUNMatDestroy_Band(arg1);
}


SWIGEXPORT int _wrap_FSUNMatZero_Band(SUNMatrix farg1) {
int fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
int result;

arg1 = (SUNMatrix)(farg1);
result = (int)SUNMatZero_Band(arg1);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FSUNMatCopy_Band(SUNMatrix farg1, SUNMatrix farg2) {
int fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
SUNMatrix arg2 = (SUNMatrix) 0 ;
int result;

arg1 = (SUNMatrix)(farg1);
arg2 = (SUNMatrix)(farg2);
result = (int)SUNMatCopy_Band(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FSUNMatScaleAdd_Band(double const *farg1, SUNMatrix farg2, SUNMatrix farg3) {
int fresult ;
realtype arg1 ;
SUNMatrix arg2 = (SUNMatrix) 0 ;
SUNMatrix arg3 = (SUNMatrix) 0 ;
int result;

arg1 = (realtype)(*farg1);
arg2 = (SUNMatrix)(farg2);
arg3 = (SUNMatrix)(farg3);
result = (int)SUNMatScaleAdd_Band(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FSUNMatScaleAddI_Band(double const *farg1, SUNMatrix farg2) {
int fresult ;
realtype arg1 ;
SUNMatrix arg2 = (SUNMatrix) 0 ;
int result;

arg1 = (realtype)(*farg1);
arg2 = (SUNMatrix)(farg2);
result = (int)SUNMatScaleAddI_Band(arg1,arg2);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FSUNMatMatvec_Band(SUNMatrix farg1, N_Vector farg2, N_Vector farg3) {
int fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
N_Vector arg2 = (N_Vector) 0 ;
N_Vector arg3 = (N_Vector) 0 ;
int result;

arg1 = (SUNMatrix)(farg1);
arg2 = (N_Vector)(farg2);
arg3 = (N_Vector)(farg3);
result = (int)SUNMatMatvec_Band(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}


SWIGEXPORT int _wrap_FSUNMatSpace_Band(SUNMatrix farg1, long *farg2, long *farg3) {
int fresult ;
SUNMatrix arg1 = (SUNMatrix) 0 ;
long *arg2 = (long *) 0 ;
long *arg3 = (long *) 0 ;
int result;

arg1 = (SUNMatrix)(farg1);
arg2 = (long *)(farg2);
arg3 = (long *)(farg3);
result = (int)SUNMatSpace_Band(arg1,arg2,arg3);
fresult = (int)(result);
return fresult;
}



