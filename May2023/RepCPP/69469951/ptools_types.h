


#pragma once


#include <ptools_config.h>


#include <stdint.h>
#endif

#include <inttypes.h>
#endif

#if defined(HAVE_INT64_T) && defined(HAVE_UINT64_T)

typedef int64_t  PTOOLS_INT64;
typedef uint64_t PTOOLS_UINT64;
#else

#if defined(HAVE_LONG_LONG) && (SIZEOF_LONG_LONG == 8)

typedef long long PTOOLS_INT64;
typedef unsigned long long PTOOLS_UINT64;
#elif defined(HAVE_LONG) && (SIZEOF_LONG == 8)

typedef long PTOOLS_INT64;
typedef unsigned long PTOOLS_UINT64;
#else
#error "No 64-bit data type found"
#endif
#endif

#if defined(HAVE_INT8_T) && defined(HAVE_UINT8_T)

typedef int8_t  PTOOLS_INT8;
typedef uint8_t PTOOLS_UINT8;
#else

#if defined(HAVE_CHAR) && (SIZEOF_CHAR == 1)

typedef char PTOOLS_INT8;
typedef unsigned char PTOOLS_UINT8;
#else
#error "No 8-bit data type found"
#endif
#endif

#if defined(HAVE_INT16_T) && defined(HAVE_UINT16_T)

typedef int16_t  PTOOLS_INT16;
typedef uint16_t PTOOLS_UINT16;
#else

#if defined(HAVE_SHORT_INT) && (SIZEOF_SHORT_INT == 2)

typedef short int PTOOLS_INT16;
typedef unsigned short int PTOOLS_UINT16;
#else
#error "No 16-bit data type found"
#endif
#endif

#if defined(HAVE_INT32_T) && defined(HAVE_UINT32_T)

typedef int32_t  PTOOLS_INT32;
typedef uint32_t PTOOLS_UINT32;
#else

#if defined(HAVE_INT) && (SIZEOF_INT == 4)

typedef int PTOOLS_INT32;
typedef unsigned int PTOOLS_UINT32;
#else
#error "No 32-bit data type found"
#endif
#endif

typedef PTOOLS_UINT64 STACK_ADDRESS;


