/* -*- mode: c; indent-width: 4; -*- */
/*
    This file is part of the libaspell-win32.

    Copyright (C) 2021-2022 by Adam Young under the GNU LGPL
    license version 2.0 or 2.1.  You should have received a copy of the
    LGPL license along with this library if you did not you can find it
    at http://www.gnu.org/.

    Assumed installation structure:

        <APPINSTALL>/aspell

            /bin            ==> /usr/bin
            /lib            ==> /usr/lib
            /etc            ==> /etc/aspell.conf
            /share          ==> /usr/lib/aspell
            /dict           ==> /usr/share/aspell
            /include        ==> /usr/include
            /doc

        $HOME/aspell/Dictionary
        $HOME/aspell/Personal

    Configuration:

        Environmental variable ASPELL_CONF, a personal configuration file,
        or a global configuration file.

        Example:

          o ASPELL_CONF
          o $HOME/.aspell.conf or X:/User/<user>/.apell.conf
          o X:/Program Files (x86)/aspell-0.60/etc/aspell.conf

    Dictionaries:

          o <APSELL_CONFIG>=<dict-dir>
          o <APPINSTALL>/dict
          o <APPINSTALL>/share [data-dir]

 */

#if defined(_WIN32_WINNT) && (_WIN32_WINNT < 0x0501)
#undef  _WIN32_WINNT
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif

#include "settings.h"
#include "buildinfo.h"
#include "dirs.h"

#include <cstdio>

#include <direct.h>
#include <io.h>

#include <shlobj.h>                             /* SHxx */

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "shfolder.lib")
#pragma comment(lib, "User32.lib")

static void set_environment(void);
static int  getdlldir(char *buf, int maxlen);
static int  getexedir(char *buf, int maxlen);
static void unixpath(char *path);


/**
 *   Retrieve the windows home directory.
 *
 *      XP: C:\Documents and Settings\Joe
 *       +: C:\Users\Joe
 */
static const char *
aspell_HOME_DIR(void)
{
    static char x_buffer[MAX_PATH];

    if (0 == x_buffer[0]) {
        if (!(SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0, x_buffer)) && x_buffer[0])) {
            if (!(SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, x_buffer)) && x_buffer[0])) {
                if (!(SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, x_buffer)) && x_buffer[0])) {
                    if (! GetCurrentDirectoryA(sizeof(x_buffer), x_buffer)) {
                        x_buffer[0] = '.', x_buffer[1] = 0;
                    }
                }
            }
        }

        unixpath(x_buffer);
#if defined(DIR_VERBOSE)
        printf("HOME_DIR=%s\n", x_buffer);
#endif
    }
    return x_buffer;
}


/**
 *  Retrieve global system configuration path, equivalent to '/etc/'.
 *
 *      <DLL|EXEPATH>
 *          <path>\etc\
 *
 *      <INSTALLPATH>
 *          X:\Program Files\<aspell>\etc
 *
 *              SHGetFolderPath(CSIDL_PROGRAM_FILES)
 *              or getenv(ProgramFiles)
 *
 *      <APPDATA>
 *          X:\Documents and Settings\All Users\Application Data\<aspell>\etc\
 *
 *              SHGetFolderPath(CSIDL_COMMON_APPDATA)
 *              or getenv(ALLUSERSPROFILE)
 */
extern "C" const char *
aspell_CONF_DIR(void)
{
    static char x_buffer[MAX_PATH];

    if (0 == x_buffer[0]) {
        int len, done = FALSE;

        // <DLL|EXEPATH>, generally same as INSTALLDIR
        if ((len = getdlldir(x_buffer, sizeof(x_buffer))) > 0 ||
                (len = getexedir(x_buffer, sizeof(x_buffer))) > 0) {
            _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\etc");
            x_buffer[sizeof(x_buffer) - 1] = 0;
            if (0 == _access(x_buffer, 0)) {
                done = TRUE;
            }
        }

        // <INSTALLPATH>
        if (! done) {
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROGRAM_FILES, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\%s\\etc", ASPELL_APPNAME);
                x_buffer[sizeof(x_buffer) - 1] = 0;
                if (0 == _access(x_buffer, 0)) {
                    done = TRUE;
                }
            }
        }

        // <APPDATA>
        if (! done)  {
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_COMMON_APPDATA, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\%s\\etc", ASPELL_APPNAME);
                x_buffer[sizeof(x_buffer) - 1] = 0;
                if (0 == _access(x_buffer, 0)) {
                    done = TRUE;
                }
            }
        }

        // default - INSTALLPATH
        if (! done) {
            const char *env;

            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROGRAM_FILES, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/%s/etc", ASPELL_APPNAME);

            } else if (NULL != (env = getenv("ProgramFiles"))) {
                _snprintf(x_buffer, sizeof(x_buffer), "%s/%s/etc", env, ASPELL_APPNAME);

            } else {
                _snprintf(x_buffer, sizeof(x_buffer), "c:/Program Files/%s/etc", ASPELL_APPNAME);
            }
            x_buffer[sizeof(x_buffer) - 1] = 0;
            mkdir(x_buffer);
        }

        unixpath(x_buffer);
#if defined(DIR_VERBOSE)
        printf("CONF_DIR=%s\n", x_buffer);
#endif
    }
    return x_buffer;
}


/**
 *  Retrieve global/share configuration path, equivalent to '/usr/share/aspell'.
 *
 *      <DLL|EXEPATH>
  *          <path>\dict\
 *
 *      <DATA_DIR>
 */
extern "C" const char *
aspell_DICT_DIR(void)
{
    static char x_buffer[MAX_PATH];

    if (0 == x_buffer[0]) {
        int len, done = FALSE;

        // <DLL|EXEPATH>, generally same as INSTALLDIR
        if ((len = getdlldir(x_buffer, sizeof(x_buffer))) > 0 ||
                (len = getexedir(x_buffer, sizeof(x_buffer))) > 0) {
            _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\dict");
            x_buffer[sizeof(x_buffer) - 1] = 0;
            if (0 == _access(x_buffer, 0)) {
                done = TRUE;
            }
        }

        // Registry
        {   HKEY hKey = 0;
            if (ERROR_SUCCESS == RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Aspell", 0, KEY_READ, &hKey)) {
                DWORD dwSize = sizeof(x_buffer);

                x_buffer[0] = 0;
                if (ERROR_SUCCESS == RegQueryValueExA(hKey, "Dictionaries", NULL, NULL, (LPBYTE)x_buffer, &dwSize) && x_buffer[0]) {
                    if (0 == _access(x_buffer, 0)) {
                        done = TRUE;
                    }
                }
                RegCloseKey(hKey);
            }
        }

        // default=<data-dict>
        if (! done) {
            strcpy(x_buffer, aspell_DATA_DIR());
        }

        unixpath(x_buffer);
#if defined(DIR_VERBOSE)
        printf("DICT_DIR=%s\n", x_buffer);
#endif
    }
    return x_buffer;
}


/**
 *  Retrieve global/share configuration path, equivalent to '/usr/share/aspell'.
 *
 *      <DLL|EXEPATH>
 *          <path>\share\
 *
 *      <INSTALLPATH>
 *          X:\Program Files (x86)\<aspell>\share\
 *          X:\Program Files\<aspell>\share\
 *
 *              SHGetFolderPath(CSIDL_PROGRAM_FILES)
 *              or getenv(ProgramFiles)
 *
 *      <HOME>
 *          X:\User\<USERNAME>\<aspell>\Dictionaries\
 *
 *      <APPDATA>
 *          X:\ProgramData\<aspell>\share\
 *          X:\Documents and Settings\All Users\Application Data\<aspell>\share\
 *
 *              SHGetFolderPath(CSIDL_COMMON_APPDATA)
 *              or getenv(ALLUSERSPROFILE)
 *
 */
extern "C" const char *
aspell_DATA_DIR(void)
{
    static char x_buffer[MAX_PATH];

    if (0 == x_buffer[0]) {
        int len, done = FALSE;

        // <DLL|EXEPATH>, generally same as INSTALLDIR
        if ((len = getdlldir(x_buffer, sizeof(x_buffer))) > 0 ||
                        (len = getexedir(x_buffer, sizeof(x_buffer))) > 0) {
            _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\share");
            x_buffer[sizeof(x_buffer) - 1] = 0;
            if (0 == _access(x_buffer, 0)) {
                done = TRUE;
            }
        }

        // Registry
        {   HKEY hKey = 0;
            if (ERROR_SUCCESS == RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Aspell", 0, KEY_READ, &hKey)) {
                DWORD dwSize = sizeof(x_buffer);

                x_buffer[0] = 0;
                if (ERROR_SUCCESS == RegQueryValueExA(hKey, "Data", NULL, NULL, (LPBYTE)x_buffer, &dwSize) && x_buffer[0]) {
                    if (0 == _access(x_buffer, 0)) {
                        done = TRUE;
                    }
                }
                RegCloseKey(hKey);
            }
        }

        // <INSTALLPATH>
        if (! done) {
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROGRAM_FILES, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\%s\\share", ASPELL_APPNAME);
                x_buffer[sizeof(x_buffer) - 1] = 0;
                if (0 == _access(x_buffer, 0)) {
                    done = TRUE;
                }
            }
        }

        // <APPDATA>
        if (! done)  {
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_COMMON_APPDATA, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\%s\\share", ASPELL_APPNAME);
                x_buffer[sizeof(x_buffer) - 1] = 0;
                if (0 == _access(x_buffer, 0)) {
                    done = TRUE;
                }
            }
        }

        // default - INSTALLPATH
        if (! done) {
            const char *env;

            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROGRAM_FILES, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\%s\\share", ASPELL_APPNAME);

            } else if (NULL != (env = getenv("ProgramFiles"))) {
                _snprintf(x_buffer, sizeof(x_buffer), "%s/%s/share", env, ASPELL_APPNAME);

            } else {
                _snprintf(x_buffer, sizeof(x_buffer), "c:/Program Files/%s/share", ASPELL_APPNAME);
            }
            x_buffer[sizeof(x_buffer) - 1] = 0;
            mkdir(x_buffer);
        }

        unixpath(x_buffer);
#if defined(DIR_VERBOSE)
        printf("DATA_DIR=%s\n", x_buffer);
#endif
    }
    return x_buffer;
}


/**
 *  Retrieve installation directory, equivalent to '/usr/bin'.
 *
 *      <DLL|EXEPATH>
 *          <path>
 *
 *      <INSTALLPATH>
 *          X:\Program Files\<aspell>
 *              SHGetFolderPath(CSIDL_PROGRAM_FILES)
 *              or getenv(ProgramFiles)
 */
extern "C" const char *
aspell_PREFIX_DIR(void)
{
    static char x_buffer[MAX_PATH];

    if (0 == x_buffer[0]) {
        int len, done = FALSE;

        // <DLL|EXEPATH>, generally same as INSTALLDIR
        // Note: WIN32_RELOCATABLE style.
        if ((len = getdlldir(x_buffer, sizeof(x_buffer))) > 0 ||
                    (len = getexedir(x_buffer, sizeof(x_buffer))) > 0) {
            done = TRUE;
        }

        // <INSTALLPATH>
        if (! done) {
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROGRAM_FILES, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "\\%s\\", ASPELL_APPNAME);
                x_buffer[sizeof(x_buffer) - 1] = 0;
                if (0 == _access(x_buffer, 0)) {
                    done = TRUE;
                }
                done = TRUE;
            }
        }

        // default - INSTALLPATH
        if (! done) {
            const char *env;
            if (NULL != (env = getenv("ProgramFiles"))) {
                _snprintf(x_buffer, sizeof(x_buffer), "%s/%s/", env, ASPELL_APPNAME);
            } else {
                _snprintf(x_buffer, sizeof(x_buffer), "c:/Program Files/%s/", ASPELL_APPNAME);
            }
            x_buffer[sizeof(x_buffer) - 1] = 0;
            mkdir(x_buffer);
        }

        unixpath(x_buffer);
#if defined(DIR_VERBOSE)
        printf("PREFIX_DIR=%s\n", x_buffer);
#endif
    }
    return x_buffer;
}


/**
 *  Setup the run-time environment.
 *
 *      o HOME
 *      o LANG
 */
static void
set_environment(void)
{
    const char *env;

    if (NULL == (env = getenv("HOME")) || !*env) {
        if (NULL != (env = aspell_HOME_DIR()) && *env) {
            _putenv_s("HOME", env);             // assign HOME
        }
    }

    // see: get_lang_env
    if (NULL == (env = getenv("LC_MESSAGES")) || !*env)  {
        if (NULL == (env = getenv("LANGUAGE")) || !*env) {
            if (NULL == (env = getenv("LANG")) || !*env) {
                char iso639[16] = {0}, iso3166[16] = {0}, lang[64] = {0};
                LCID lcid = GetThreadLocale();

                if (GetLocaleInfoA(lcid, LOCALE_SISO639LANGNAME, iso639, sizeof(iso639)) &&
                        GetLocaleInfoA(lcid, LOCALE_SISO3166CTRYNAME, iso3166, sizeof(iso3166))) {

                    snprintf(lang, sizeof(lang), "%s_%s", iso639, iso3166); // "9_9"
                    lang[sizeof(lang) - 1] = '\0';

                    _putenv_s("LANG", lang);    // assign LANG
                }
            }
        }
    }
}


#if defined(_WINDLL)
#if defined(_MSC_VER)
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#endif

static int
getdlldir(char *buf, int maxlen)
{
    set_environment();

#if defined(__WATCOMC__)
    HMODULE hm = NULL;
    if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
        GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR) &__citrus_PATH_ICONV, &hm) != 0 &&
        GetModuleFileNameA(hm, buf, maxlen)) {
#else
    if (GetModuleFileNameA((HINSTANCE)&__ImageBase, buf, maxlen)) {
#endif
        const int len = strlen(buf);
        char *cp;
        for (cp = buf + len; (cp > buf) && (*cp != '\\'); --cp)
            /*cont*/;
        if ('\\' == *cp) {
            cp[1] = '\0';                       // remove library
            if ((cp - 6) >= buf) {
                char *cp4 = cp - 4;
                if (0 == stricmp(cp4, "\\bin\\")) {
                    cp = cp4;
                    cp[1] = '\0';               // remove "bin\\"
                }
            }
            return (cp - buf) + 1;
        }
        return len;
    }
    return -1;
}

#else   //_DLL

static int
getdlldir(char *buf, int maxlen)
{
    set_environment();
    return -1;
}

#endif  //_DLL


static int
getexedir(char *buf, int maxlen)
{
    if (GetModuleFileNameA(NULL, buf, maxlen)) {
        const int len = (int)strlen(buf);
        char *cp;

        for (cp = buf + len; (cp > buf) && (*cp != '\\'); cp--)
            /*cont*/;
        if ('\\' == *cp) {
            cp[1] = '\0';                       // remove program, retain trailing '\'
            if ((cp - 6) >= buf) {
                char *cp4 = cp - 4;
                if (0 == stricmp(cp4, "\\bin\\")) {
                    cp = cp4;
                    cp[1] = '\0';               // remove "bin\\"
                }
            }
            return (int)((cp - buf) + 1);
        }
        return len;
    }
    return -1;
}


static void
unixpath(char *path)
{
    const char *in = path;

    while (*in) {
        if ('/' == *in || '\\' == *in) {
            ++in;
            while ('/' == *in || '\\' == *in) {
                ++in;
            }
            *path++ = '/';
        } else {
            *path++ = *in++;
        }
    }
    *path = 0;
}

/*end*/
