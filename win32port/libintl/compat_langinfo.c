/* -*- mode: c; indent-width: 4; -*- */
/*
 *  win32 langinfo() implementation
 */

#include <langinfo.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define CODESET_SZ (2 + 10)                     // CPxxxxxxxxxx
__declspec(thread) static char tls_codeset[CODESET_SZ + 1 /*NUL*/];

const char *
libintl_nl_langinfo(nl_item item)
{
    switch (item) {
    case CODESET: {
            char *codeset = tls_codeset;
            const char *locale;

            locale = setlocale (LC_ALL, NULL);  // enquire current
            if ('C' == locale[0] && 0 == locale[1]) {
                /* Sets the locale to the default, which is the user-default ANSI code page obtained
                 * from the operating system.  The locale name is set to the value returned by
                 * GetUserDefaultLocaleName. The code page is set to the value returned by GetACP.
                 */
                setlocale (LC_ALL, "");         // initialise
            }
            locale = setlocale (LC_CTYPE, NULL);

            if (locale && locale[0]) {
                /*
                 *      "lang[_country_region[.code_page]]"
                 *
                 *  If the locale name contains an encoding after the dot, return it, for example
                 *
                 *      "English_United Kingdom.1252"
                 */
                const char *dot = strchr (locale, '.');
                if (dot) {
                    char *modifier;

                    _snprintf(codeset, CODESET_SZ, "CP%s", dot + 1);
                    codeset[CODESET_SZ] = 0;

                    if (NULL != (modifier = strchr (codeset, '@'))) {
                        *modifier = 0;          // trailer and remove it.
                    }
                    return codeset;
                }
            }

            _snprintf(codeset, CODESET_SZ, "CP%u", (unsigned)GetACP());
            codeset[CODESET_SZ] = 0;
            return codeset;
        }

//ORG   return "UTF-8";  /* assume terminal is "utf-8" */
    }
    return "n/a";
}
