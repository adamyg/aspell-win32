#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED
#pragma once
/*
 *  WIN32 -- settings
 *
 *  see: aspell-0.60.8/gen/settings.h.in
 */

//  -------------------------------------------------------------------------------------

#define HAVE_INTTYPES_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRINGS_H 1
#define HAVE_STRING_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1

//  -------------------------------------------------------------------------------------

#ifndef C_EXPORT
#define C_EXPORT extern "C"
#endif

#include "BuildInfo.h"

//  -------------------------------------------------------------------------------------

#if defined(_MSC_VER)
#if !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS 1
#endif //_CRT_SECURE_NO_WARNINGS

#pragma warning(disable:4146) // unary minus operator applied to unsigned type, result still unsigned.
#pragma warning(disable:4521) // multiple assignment operators specified.
#pragma warning(disable:4522) // multiple copy operators specified.
#pragma warning(disable:4800) // forcing value to bool true or false.
#pragma warning(disable:4996) // 'xxx': The POSIX name for this item is deprecated.

#elif defined(__WATCOMC__)
#endif

#include <sys/stat.h>

#if !defined(F_OK) //_access()
#define F_OK 0                                  /* 00 Existence only */
#define W_OK 2                                  /* 02 Write permission */
#define R_OK 4                                  /* 04 Read permission */
#define A_OK 6                                  /* 06 (access) Read and write permission */
#endif

#if !defined(S_ISREG) && defined(S_IFMT) && defined(S_IFREG)
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#endif

#include "asc_ctype.hpp"                        /* see: file_util.cpp */

#if (_MSC_VER < 1900)                           /* see: markdown.cpp */
#include "filter_char.hpp"
inline void blank(acommon::FilterChar & chr) {  // global namespace
  if (!acommon::asc_isspace(chr)) {
    chr = ' ';
  }
}
#endif //1900

#endif //SETTINGS_H_INCLUDED

//end
