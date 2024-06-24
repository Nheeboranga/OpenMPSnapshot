#ifndef SDL_stdinc_h_
#define SDL_stdinc_h_
#include "SDL_config.h"
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif
#if defined(STDC_HEADERS)
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
#else
# if defined(HAVE_STDLIB_H)
#  include <stdlib.h>
# elif defined(HAVE_MALLOC_H)
#  include <malloc.h>
# endif
# if defined(HAVE_STDDEF_H)
#  include <stddef.h>
# endif
# if defined(HAVE_STDARG_H)
#  include <stdarg.h>
# endif
#endif
#ifdef HAVE_STRING_H
# if !defined(STDC_HEADERS) && defined(HAVE_MEMORY_H)
#  include <memory.h>
# endif
# include <string.h>
#endif
#ifdef HAVE_STRINGS_H
# include <strings.h>
#endif
#ifdef HAVE_WCHAR_H
# include <wchar.h>
#endif
#if defined(HAVE_INTTYPES_H)
# include <inttypes.h>
#elif defined(HAVE_STDINT_H)
# include <stdint.h>
#endif
#ifdef HAVE_CTYPE_H
# include <ctype.h>
#endif
#ifdef HAVE_MATH_H
# if defined(__WINRT__)
#  define _USE_MATH_DEFINES
# endif
# include <math.h>
#endif
#ifdef HAVE_FLOAT_H
# include <float.h>
#endif
#define SDL_arraysize(array)    (sizeof(array)/sizeof(array[0]))
#define SDL_TABLESIZE(table)    SDL_arraysize(table)
#define SDL_STRINGIFY_ARG(arg)  #arg
#ifdef __cplusplus
#define SDL_reinterpret_cast(type, expression) reinterpret_cast<type>(expression)
#define SDL_static_cast(type, expression) static_cast<type>(expression)
#define SDL_const_cast(type, expression) const_cast<type>(expression)
#else
#define SDL_reinterpret_cast(type, expression) ((type)(expression))
#define SDL_static_cast(type, expression) ((type)(expression))
#define SDL_const_cast(type, expression) ((type)(expression))
#endif
#define SDL_FOURCC(A, B, C, D) \
((SDL_static_cast(Uint32, SDL_static_cast(Uint8, (A))) << 0) | \
(SDL_static_cast(Uint32, SDL_static_cast(Uint8, (B))) << 8) | \
(SDL_static_cast(Uint32, SDL_static_cast(Uint8, (C))) << 16) | \
(SDL_static_cast(Uint32, SDL_static_cast(Uint8, (D))) << 24))
#ifdef __CC_ARM
#define SDL_FALSE 0
#define SDL_TRUE 1
typedef int SDL_bool;
#else
typedef enum
{
SDL_FALSE = 0,
SDL_TRUE = 1
} SDL_bool;
#endif
#define SDL_MAX_SINT8   ((Sint8)0x7F)           
#define SDL_MIN_SINT8   ((Sint8)(~0x7F))        
typedef int8_t Sint8;
#define SDL_MAX_UINT8   ((Uint8)0xFF)           
#define SDL_MIN_UINT8   ((Uint8)0x00)           
typedef uint8_t Uint8;
#define SDL_MAX_SINT16  ((Sint16)0x7FFF)        
#define SDL_MIN_SINT16  ((Sint16)(~0x7FFF))     
typedef int16_t Sint16;
#define SDL_MAX_UINT16  ((Uint16)0xFFFF)        
#define SDL_MIN_UINT16  ((Uint16)0x0000)        
typedef uint16_t Uint16;
#define SDL_MAX_SINT32  ((Sint32)0x7FFFFFFF)    
#define SDL_MIN_SINT32  ((Sint32)(~0x7FFFFFFF)) 
typedef int32_t Sint32;
#define SDL_MAX_UINT32  ((Uint32)0xFFFFFFFFu)   
#define SDL_MIN_UINT32  ((Uint32)0x00000000)    
typedef uint32_t Uint32;
#define SDL_MAX_SINT64  ((Sint64)0x7FFFFFFFFFFFFFFFll)      
#define SDL_MIN_SINT64  ((Sint64)(~0x7FFFFFFFFFFFFFFFll))   
typedef int64_t Sint64;
#define SDL_MAX_UINT64  ((Uint64)0xFFFFFFFFFFFFFFFFull)     
#define SDL_MIN_UINT64  ((Uint64)(0x0000000000000000ull))   
typedef uint64_t Uint64;
#ifndef SDL_PRIs64
#ifdef PRIs64
#define SDL_PRIs64 PRIs64
#elif defined(__WIN32__)
#define SDL_PRIs64 "I64d"
#elif defined(__LINUX__) && defined(__LP64__)
#define SDL_PRIs64 "ld"
#else
#define SDL_PRIs64 "lld"
#endif
#endif
#ifndef SDL_PRIu64
#ifdef PRIu64
#define SDL_PRIu64 PRIu64
#elif defined(__WIN32__)
#define SDL_PRIu64 "I64u"
#elif defined(__LINUX__) && defined(__LP64__)
#define SDL_PRIu64 "lu"
#else
#define SDL_PRIu64 "llu"
#endif
#endif
#ifndef SDL_PRIx64
#ifdef PRIx64
#define SDL_PRIx64 PRIx64
#elif defined(__WIN32__)
#define SDL_PRIx64 "I64x"
#elif defined(__LINUX__) && defined(__LP64__)
#define SDL_PRIx64 "lx"
#else
#define SDL_PRIx64 "llx"
#endif
#endif
#ifndef SDL_PRIX64
#ifdef PRIX64
#define SDL_PRIX64 PRIX64
#elif defined(__WIN32__)
#define SDL_PRIX64 "I64X"
#elif defined(__LINUX__) && defined(__LP64__)
#define SDL_PRIX64 "lX"
#else
#define SDL_PRIX64 "llX"
#endif
#endif
#ifdef SDL_DISABLE_ANALYZE_MACROS
#define SDL_IN_BYTECAP(x)
#define SDL_INOUT_Z_CAP(x)
#define SDL_OUT_Z_CAP(x)
#define SDL_OUT_CAP(x)
#define SDL_OUT_BYTECAP(x)
#define SDL_OUT_Z_BYTECAP(x)
#define SDL_PRINTF_FORMAT_STRING
#define SDL_SCANF_FORMAT_STRING
#define SDL_PRINTF_VARARG_FUNC( fmtargnumber )
#define SDL_SCANF_VARARG_FUNC( fmtargnumber )
#else
#if defined(_MSC_VER) && (_MSC_VER >= 1600) 
#include <sal.h>
#define SDL_IN_BYTECAP(x) _In_bytecount_(x)
#define SDL_INOUT_Z_CAP(x) _Inout_z_cap_(x)
#define SDL_OUT_Z_CAP(x) _Out_z_cap_(x)
#define SDL_OUT_CAP(x) _Out_cap_(x)
#define SDL_OUT_BYTECAP(x) _Out_bytecap_(x)
#define SDL_OUT_Z_BYTECAP(x) _Out_z_bytecap_(x)
#define SDL_PRINTF_FORMAT_STRING _Printf_format_string_
#define SDL_SCANF_FORMAT_STRING _Scanf_format_string_impl_
#else
#define SDL_IN_BYTECAP(x)
#define SDL_INOUT_Z_CAP(x)
#define SDL_OUT_Z_CAP(x)
#define SDL_OUT_CAP(x)
#define SDL_OUT_BYTECAP(x)
#define SDL_OUT_Z_BYTECAP(x)
#define SDL_PRINTF_FORMAT_STRING
#define SDL_SCANF_FORMAT_STRING
#endif
#if defined(__GNUC__)
#define SDL_PRINTF_VARARG_FUNC( fmtargnumber ) __attribute__ (( format( __printf__, fmtargnumber, fmtargnumber+1 )))
#define SDL_SCANF_VARARG_FUNC( fmtargnumber ) __attribute__ (( format( __scanf__, fmtargnumber, fmtargnumber+1 )))
#else
#define SDL_PRINTF_VARARG_FUNC( fmtargnumber )
#define SDL_SCANF_VARARG_FUNC( fmtargnumber )
#endif
#endif 
#define SDL_COMPILE_TIME_ASSERT(name, x)               \
typedef int SDL_compile_time_assert_ ## name[(x) * 2 - 1]
#ifndef DOXYGEN_SHOULD_IGNORE_THIS
SDL_COMPILE_TIME_ASSERT(uint8, sizeof(Uint8) == 1);
SDL_COMPILE_TIME_ASSERT(sint8, sizeof(Sint8) == 1);
SDL_COMPILE_TIME_ASSERT(uint16, sizeof(Uint16) == 2);
SDL_COMPILE_TIME_ASSERT(sint16, sizeof(Sint16) == 2);
SDL_COMPILE_TIME_ASSERT(uint32, sizeof(Uint32) == 4);
SDL_COMPILE_TIME_ASSERT(sint32, sizeof(Sint32) == 4);
SDL_COMPILE_TIME_ASSERT(uint64, sizeof(Uint64) == 8);
SDL_COMPILE_TIME_ASSERT(sint64, sizeof(Sint64) == 8);
#endif 
#ifndef DOXYGEN_SHOULD_IGNORE_THIS
#if !defined(__ANDROID__)
typedef enum
{
DUMMY_ENUM_VALUE
} SDL_DUMMY_ENUM;
SDL_COMPILE_TIME_ASSERT(enum, sizeof(SDL_DUMMY_ENUM) == sizeof(int));
#endif
#endif 
#include "begin_code.h"
#ifdef __cplusplus
extern "C" {
#endif
#if defined(HAVE_ALLOCA) && !defined(alloca)
# if defined(HAVE_ALLOCA_H)
#  include <alloca.h>
# elif defined(__GNUC__)
#  define alloca __builtin_alloca
# elif defined(_MSC_VER)
#  include <malloc.h>
#  define alloca _alloca
# elif defined(__WATCOMC__)
#  include <malloc.h>
# elif defined(__BORLANDC__)
#  include <malloc.h>
# elif defined(__DMC__)
#  include <stdlib.h>
# elif defined(__AIX__)
#pragma alloca
# elif defined(__MRC__)
void *alloca(unsigned);
# else
char *alloca();
# endif
#endif
#ifdef HAVE_ALLOCA
#define SDL_stack_alloc(type, count)    (type*)alloca(sizeof(type)*(count))
#define SDL_stack_free(data)
#else
#define SDL_stack_alloc(type, count)    (type*)SDL_malloc(sizeof(type)*(count))
#define SDL_stack_free(data)            SDL_free(data)
#endif
extern DECLSPEC void *SDLCALL SDL_malloc(size_t size);
extern DECLSPEC void *SDLCALL SDL_calloc(size_t nmemb, size_t size);
extern DECLSPEC void *SDLCALL SDL_realloc(void *mem, size_t size);
extern DECLSPEC void SDLCALL SDL_free(void *mem);
typedef void *(SDLCALL *SDL_malloc_func)(size_t size);
typedef void *(SDLCALL *SDL_calloc_func)(size_t nmemb, size_t size);
typedef void *(SDLCALL *SDL_realloc_func)(void *mem, size_t size);
typedef void (SDLCALL *SDL_free_func)(void *mem);
extern DECLSPEC void SDLCALL SDL_GetMemoryFunctions(SDL_malloc_func *malloc_func,
SDL_calloc_func *calloc_func,
SDL_realloc_func *realloc_func,
SDL_free_func *free_func);
extern DECLSPEC int SDLCALL SDL_SetMemoryFunctions(SDL_malloc_func malloc_func,
SDL_calloc_func calloc_func,
SDL_realloc_func realloc_func,
SDL_free_func free_func);
extern DECLSPEC int SDLCALL SDL_GetNumAllocations(void);
extern DECLSPEC char *SDLCALL SDL_getenv(const char *name);
extern DECLSPEC int SDLCALL SDL_setenv(const char *name, const char *value, int overwrite);
extern DECLSPEC void SDLCALL SDL_qsort(void *base, size_t nmemb, size_t size, int (*compare) (const void *, const void *));
extern DECLSPEC int SDLCALL SDL_abs(int x);
#define SDL_min(x, y) (((x) < (y)) ? (x) : (y))
#define SDL_max(x, y) (((x) > (y)) ? (x) : (y))
extern DECLSPEC int SDLCALL SDL_isdigit(int x);
extern DECLSPEC int SDLCALL SDL_isspace(int x);
extern DECLSPEC int SDLCALL SDL_toupper(int x);
extern DECLSPEC int SDLCALL SDL_tolower(int x);
extern DECLSPEC void *SDLCALL SDL_memset(SDL_OUT_BYTECAP(len) void *dst, int c, size_t len);
#define SDL_zero(x) SDL_memset(&(x), 0, sizeof((x)))
#define SDL_zerop(x) SDL_memset((x), 0, sizeof(*(x)))
SDL_FORCE_INLINE void SDL_memset4(void *dst, Uint32 val, size_t dwords)
{
#if defined(__GNUC__) && defined(i386)
int u0, u1, u2;
__asm__ __volatile__ (
"cld \n\t"
"rep ; stosl \n\t"
: "=&D" (u0), "=&a" (u1), "=&c" (u2)
: "0" (dst), "1" (val), "2" (SDL_static_cast(Uint32, dwords))
: "memory"
);
#else
size_t _n = (dwords + 3) / 4;
Uint32 *_p = SDL_static_cast(Uint32 *, dst);
Uint32 _val = (val);
if (dwords == 0)
return;
switch (dwords % 4)
{
case 0: do {    *_p++ = _val;   
case 3:         *_p++ = _val;   
case 2:         *_p++ = _val;   
case 1:         *_p++ = _val;   
} while ( --_n );
}
#endif
}
extern DECLSPEC void *SDLCALL SDL_memcpy(SDL_OUT_BYTECAP(len) void *dst, SDL_IN_BYTECAP(len) const void *src, size_t len);
extern DECLSPEC void *SDLCALL SDL_memmove(SDL_OUT_BYTECAP(len) void *dst, SDL_IN_BYTECAP(len) const void *src, size_t len);
extern DECLSPEC int SDLCALL SDL_memcmp(const void *s1, const void *s2, size_t len);
extern DECLSPEC size_t SDLCALL SDL_wcslen(const wchar_t *wstr);
extern DECLSPEC size_t SDLCALL SDL_wcslcpy(SDL_OUT_Z_CAP(maxlen) wchar_t *dst, const wchar_t *src, size_t maxlen);
extern DECLSPEC size_t SDLCALL SDL_wcslcat(SDL_INOUT_Z_CAP(maxlen) wchar_t *dst, const wchar_t *src, size_t maxlen);
extern DECLSPEC int SDLCALL SDL_wcscmp(const wchar_t *str1, const wchar_t *str2);
extern DECLSPEC size_t SDLCALL SDL_strlen(const char *str);
extern DECLSPEC size_t SDLCALL SDL_strlcpy(SDL_OUT_Z_CAP(maxlen) char *dst, const char *src, size_t maxlen);
extern DECLSPEC size_t SDLCALL SDL_utf8strlcpy(SDL_OUT_Z_CAP(dst_bytes) char *dst, const char *src, size_t dst_bytes);
extern DECLSPEC size_t SDLCALL SDL_strlcat(SDL_INOUT_Z_CAP(maxlen) char *dst, const char *src, size_t maxlen);
extern DECLSPEC char *SDLCALL SDL_strdup(const char *str);
extern DECLSPEC char *SDLCALL SDL_strrev(char *str);
extern DECLSPEC char *SDLCALL SDL_strupr(char *str);
extern DECLSPEC char *SDLCALL SDL_strlwr(char *str);
extern DECLSPEC char *SDLCALL SDL_strchr(const char *str, int c);
extern DECLSPEC char *SDLCALL SDL_strrchr(const char *str, int c);
extern DECLSPEC char *SDLCALL SDL_strstr(const char *haystack, const char *needle);
extern DECLSPEC size_t SDLCALL SDL_utf8strlen(const char *str);
extern DECLSPEC char *SDLCALL SDL_itoa(int value, char *str, int radix);
extern DECLSPEC char *SDLCALL SDL_uitoa(unsigned int value, char *str, int radix);
extern DECLSPEC char *SDLCALL SDL_ltoa(long value, char *str, int radix);
extern DECLSPEC char *SDLCALL SDL_ultoa(unsigned long value, char *str, int radix);
extern DECLSPEC char *SDLCALL SDL_lltoa(Sint64 value, char *str, int radix);
extern DECLSPEC char *SDLCALL SDL_ulltoa(Uint64 value, char *str, int radix);
extern DECLSPEC int SDLCALL SDL_atoi(const char *str);
extern DECLSPEC double SDLCALL SDL_atof(const char *str);
extern DECLSPEC long SDLCALL SDL_strtol(const char *str, char **endp, int base);
extern DECLSPEC unsigned long SDLCALL SDL_strtoul(const char *str, char **endp, int base);
extern DECLSPEC Sint64 SDLCALL SDL_strtoll(const char *str, char **endp, int base);
extern DECLSPEC Uint64 SDLCALL SDL_strtoull(const char *str, char **endp, int base);
extern DECLSPEC double SDLCALL SDL_strtod(const char *str, char **endp);
extern DECLSPEC int SDLCALL SDL_strcmp(const char *str1, const char *str2);
extern DECLSPEC int SDLCALL SDL_strncmp(const char *str1, const char *str2, size_t maxlen);
extern DECLSPEC int SDLCALL SDL_strcasecmp(const char *str1, const char *str2);
extern DECLSPEC int SDLCALL SDL_strncasecmp(const char *str1, const char *str2, size_t len);
extern DECLSPEC int SDLCALL SDL_sscanf(const char *text, SDL_SCANF_FORMAT_STRING const char *fmt, ...) SDL_SCANF_VARARG_FUNC(2);
extern DECLSPEC int SDLCALL SDL_vsscanf(const char *text, const char *fmt, va_list ap);
extern DECLSPEC int SDLCALL SDL_snprintf(SDL_OUT_Z_CAP(maxlen) char *text, size_t maxlen, SDL_PRINTF_FORMAT_STRING const char *fmt, ... ) SDL_PRINTF_VARARG_FUNC(3);
extern DECLSPEC int SDLCALL SDL_vsnprintf(SDL_OUT_Z_CAP(maxlen) char *text, size_t maxlen, const char *fmt, va_list ap);
#ifndef HAVE_M_PI
#ifndef M_PI
#define M_PI    3.14159265358979323846264338327950288   
#endif
#endif
extern DECLSPEC double SDLCALL SDL_acos(double x);
extern DECLSPEC float SDLCALL SDL_acosf(float x);
extern DECLSPEC double SDLCALL SDL_asin(double x);
extern DECLSPEC float SDLCALL SDL_asinf(float x);
extern DECLSPEC double SDLCALL SDL_atan(double x);
extern DECLSPEC float SDLCALL SDL_atanf(float x);
extern DECLSPEC double SDLCALL SDL_atan2(double x, double y);
extern DECLSPEC float SDLCALL SDL_atan2f(float x, float y);
extern DECLSPEC double SDLCALL SDL_ceil(double x);
extern DECLSPEC float SDLCALL SDL_ceilf(float x);
extern DECLSPEC double SDLCALL SDL_copysign(double x, double y);
extern DECLSPEC float SDLCALL SDL_copysignf(float x, float y);
extern DECLSPEC double SDLCALL SDL_cos(double x);
extern DECLSPEC float SDLCALL SDL_cosf(float x);
extern DECLSPEC double SDLCALL SDL_fabs(double x);
extern DECLSPEC float SDLCALL SDL_fabsf(float x);
extern DECLSPEC double SDLCALL SDL_floor(double x);
extern DECLSPEC float SDLCALL SDL_floorf(float x);
extern DECLSPEC double SDLCALL SDL_fmod(double x, double y);
extern DECLSPEC float SDLCALL SDL_fmodf(float x, float y);
extern DECLSPEC double SDLCALL SDL_log(double x);
extern DECLSPEC float SDLCALL SDL_logf(float x);
extern DECLSPEC double SDLCALL SDL_log10(double x);
extern DECLSPEC float SDLCALL SDL_log10f(float x);
extern DECLSPEC double SDLCALL SDL_pow(double x, double y);
extern DECLSPEC float SDLCALL SDL_powf(float x, float y);
extern DECLSPEC double SDLCALL SDL_scalbn(double x, int n);
extern DECLSPEC float SDLCALL SDL_scalbnf(float x, int n);
extern DECLSPEC double SDLCALL SDL_sin(double x);
extern DECLSPEC float SDLCALL SDL_sinf(float x);
extern DECLSPEC double SDLCALL SDL_sqrt(double x);
extern DECLSPEC float SDLCALL SDL_sqrtf(float x);
extern DECLSPEC double SDLCALL SDL_tan(double x);
extern DECLSPEC float SDLCALL SDL_tanf(float x);
#define SDL_ICONV_ERROR     (size_t)-1
#define SDL_ICONV_E2BIG     (size_t)-2
#define SDL_ICONV_EILSEQ    (size_t)-3
#define SDL_ICONV_EINVAL    (size_t)-4
typedef struct _SDL_iconv_t *SDL_iconv_t;
extern DECLSPEC SDL_iconv_t SDLCALL SDL_iconv_open(const char *tocode,
const char *fromcode);
extern DECLSPEC int SDLCALL SDL_iconv_close(SDL_iconv_t cd);
extern DECLSPEC size_t SDLCALL SDL_iconv(SDL_iconv_t cd, const char **inbuf,
size_t * inbytesleft, char **outbuf,
size_t * outbytesleft);
extern DECLSPEC char *SDLCALL SDL_iconv_string(const char *tocode,
const char *fromcode,
const char *inbuf,
size_t inbytesleft);
#define SDL_iconv_utf8_locale(S)    SDL_iconv_string("", "UTF-8", S, SDL_strlen(S)+1)
#define SDL_iconv_utf8_ucs2(S)      (Uint16 *)SDL_iconv_string("UCS-2-INTERNAL", "UTF-8", S, SDL_strlen(S)+1)
#define SDL_iconv_utf8_ucs4(S)      (Uint32 *)SDL_iconv_string("UCS-4-INTERNAL", "UTF-8", S, SDL_strlen(S)+1)
#if defined(__clang_analyzer__) && !defined(SDL_DISABLE_ANALYZE_MACROS)
#define SDL_malloc malloc
#define SDL_calloc calloc
#define SDL_realloc realloc
#define SDL_free free
#define SDL_memset memset
#define SDL_memcpy memcpy
#define SDL_memmove memmove
#define SDL_memcmp memcmp
#define SDL_strlen strlen
#define SDL_strlcpy strlcpy
#define SDL_strlcat strlcat
#define SDL_strdup strdup
#define SDL_strchr strchr
#define SDL_strrchr strrchr
#define SDL_strstr strstr
#define SDL_strcmp strcmp
#define SDL_strncmp strncmp
#define SDL_strcasecmp strcasecmp
#define SDL_strncasecmp strncasecmp
#define SDL_sscanf sscanf
#define SDL_vsscanf vsscanf
#define SDL_snprintf snprintf
#define SDL_vsnprintf vsnprintf
#endif
SDL_FORCE_INLINE void *SDL_memcpy4(SDL_OUT_BYTECAP(dwords*4) void *dst, SDL_IN_BYTECAP(dwords*4) const void *src, size_t dwords)
{
return SDL_memcpy(dst, src, dwords * 4);
}
#ifdef __cplusplus
}
#endif
#include "close_code.h"
#endif 