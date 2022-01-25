#pragma once
/*
 *  <sys/cdefs.h>
 */

#include <assert.h>

#ifndef __BEGIN_DECLS
#  ifdef __cplusplus
#     define __BEGIN_DECLS      extern "C" {
#     define __END_DECLS        }
#  else
#     define __BEGIN_DECLS
#     define __END_DECLS
#  endif
#endif

#ifndef __P
#  if (__STDC__) || defined(__cplusplus) || \
         defined(_MSC_VER) || defined(__PARADIGM__) || defined(__GNUC__) || \
         defined(__BORLANDC__) || defined(__WATCOMC__)
#     define __P(x)             x
#  else
#     define __P(x)             ()
#  endif
#endif

#ifndef __RCSID
#define __RCSID(__x)            /*nothing*/
#endif

#if defined(__GNUC__)
#define __packed                __attribute__((packed, aligned(1)))
#else
#define __packed                /**/
#endif

#define __UNCONST(__x)          ((void *)(__x))

#define _DIAGASSERT(__x)        assert(__x)

/*end*/
