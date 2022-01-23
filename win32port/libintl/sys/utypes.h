#pragma once
/*
 *  <sys/utypes.h>
 */

#include <sys/types.h>

#if defined(HAVE_STDINT_H)
#include <stdint.h>
#else
#if defined(_MSC_VER) && !defined(_MSC_STDINT_H_TYPES)
#if (_MSC_VER < 1300)
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
#else
typedef signed __int8 int8_t;
typedef signed __int16 int16_t;
typedef signed __int32 int32_t;
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
#endif /*1300*/
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#if (_MSC_VER < 1800)
typedef uint8_t uint_fast8_t; /* optional C11 */
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
#endif
#define _MSC_STDINT_H_TYPES
#endif /*_MSC_STDINT_H_TYPES*/
#endif /*stdint.h*/

#if !defined(ssize_t)
typedef int ssize_t;
#define ssize_t ssize_t
#endif
