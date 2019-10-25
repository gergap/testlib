#ifndef __STDINTCOMPAT_H__
#define __STDINTCOMPAT_H__

#if defined(_MSC_VER) || defined(__MINGW32__)
#include <float.h>
#include <limits.h>

/* 7.18.1.1 Exact-width integer types */
typedef __int8            int8_t;
typedef __int16           int16_t;
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;

/* 7.18.1.2 Minimum-width integer types */
typedef int8_t    int_least8_t;
typedef int16_t   int_least16_t;
typedef int32_t   int_least32_t;
typedef int64_t   int_least64_t;
typedef uint8_t   uint_least8_t;
typedef uint16_t  uint_least16_t;
typedef uint32_t  uint_least32_t;
typedef uint64_t  uint_least64_t;

/* 7.18.1.3 Fastest minimum-width integer types */
typedef int8_t    int_fast8_t;
typedef int16_t   int_fast16_t;
typedef int32_t   int_fast32_t;
typedef int64_t   int_fast64_t;
typedef uint8_t   uint_fast8_t;
typedef uint16_t  uint_fast16_t;
typedef uint32_t  uint_fast32_t;
typedef uint64_t  uint_fast64_t;

/* 7.18.1.4 Integer types capable of holding object pointers */
#ifdef _WIN64
typedef __int64           intptr_t;
typedef unsigned __int64  uintptr_t;
#else
typedef int               intptr_t;
typedef unsigned int      uintptr_t;
#endif

/* 7.18.1.5 Greatest-width integer types */
typedef int64_t   intmax_t;
typedef uint64_t  uintmax_t;

#else
/* There is no need to use this header on standard compliant systems. */
# error "Use this header only with Microsoft Visual C++ compilers!"
#endif

/* integer constant makros for MS compiler */
#define INT8_C(x)   x##i8
#define UINT8_C(x)  x##ui8
#define INT16_C(x)  x##i16
#define UINT16_C(x) x##ui16
#define INT32_C(x)  x##i32
#define UINT32_C(x) x##ui32
#define INT64_C(x)  x##i64
#define UINT64_C(x) x##ui64

/* integer max constants */
#define INT8_MAX   _I8_MAX
#define UINT8_MAX  _UI8_MAX
#define INT16_MAX  _I16_MAX
#define UINT16_MAX _UI16_MAX
#define INT32_MAX  _I32_MAX
#define UINT32_MAX _UI32_MAX
#define INT64_MAX  _I64_MAX
#define UINT64_MAX _UI64_MAX
#define FLOAT_MAX  FLT_MAX
#define DOUBLE_MAX DBL_MAX
#ifdef _WIN64
# define UINTPTR_MAX UINT64_MAX
# define INTPTR_MAX INT64_MAX
#else
# define UINTPTR_MAX UINT32_MAX
# define INTPTR_MAX INT32_MAX
#endif

/* integer min constants */
#define INT8_MIN   _I8_MIN
#define INT16_MIN  _I16_MIN
#define INT32_MIN  _I32_MIN
#define INT64_MIN  _I64_MIN
#define FLOAT_MIN  FLT_MIN
#define DOUBLE_MIN DBL_MIN
#ifdef _WIN64
# define INTPTR_MIN INT64_MIN
#else
# define INTPTR_MIN INT32_MIN
#endif

#endif /* __STDINTCOMPAT_H__ */
