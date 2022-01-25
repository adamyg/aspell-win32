/*
 *  <namespace.h> - libintl
 */
 
#ifdef  _MSC_VER
#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif
#pragma warning(disable:4996)                   /* 'xxx' was declared deprecated */
#endif

#include <sys/cdefs.h>
#include <sys/utypes.h>
#include <sys/param.h>
#include <direct.h>
#include <io.h>

#ifndef snprintf
#if (_MSC_VER < 1500) /* MSVC 2008 (v9.0) */
#define vsnprintf       _vsnprintf
#endif /*1500*/
#if (_MSC_VER < 1900) /* MSVC 2015 (v9.0) */
#define snprintf        _snprintf
#endif /*1900*/
#endif /*snprintf*/

#ifndef open
#define open            _open
#define read            _read
#define write           _write
#define close           _close
#endif

#ifndef getcwd
#define getcwd(__a, __b) _getcwd(__a, __b)
#endif

#ifndef strdup
#define strdup(__a)     _strdup(__a)
#endif

#ifndef strcasecmp
#define strcasecmp(__a, __b) _stricmp(__a, __b)
#endif

extern char *           libintl_strsep(char **stringp, const char *delim);
#define strsep(__a,__b) libintl_strsep(__a,__b)

extern size_t           libintl_strlcat(char *dst, const char *src, size_t siz);
#define strlcat(__a,__b,__c) libintl_strlcat(__a,__b,__c)

extern size_t           libintl_strlcpy(char *dst, const char *src, size_t siz);
#define strlcpy(__a,__b,__c) libintl_strlcpy(__a,__b,__c)

#if defined(_MSC_VER)
#define LC_MESSAGES     (LC_MAX + 1)
#endif

/*end*/
