/* -*- mode: c; indent-width: 4; -*- */
/*
   This file is part of the libaspell-win32.

   Copyright (C) 2021-2022 by Adam Young under the GNU LGPL
   license version 2.0 or 2.1.  You should have received a copy of the
   LGPL license along with this library if you did not you can find it
   at http://www.gnu.org/.
 */


#if defined(_WIN32_WINNT) && (_WIN32_WINNT < 0x0501)
#undef  _WIN32_WINNT
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif

#include "settings.h"
#include "dirs.h"

#include <cstdio>

#include <direct.h>
#include <io.h>

#include <shlobj.h>                             /* SHxx */

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "shfolder.lib")
#pragma comment(lib, "User32.lib")

static int getexedir(char *buf, int maxlen);
static void unixpath(char *path);


/**
 *  Retrieve global system configuration path, equivalent to '/etc/'.
 *
 *      <EXEPATH>
 *          <exepath>\etc\
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

        // <EXEPATH>, generally same as INSTALLDIR
        if ((len = getexedir(x_buffer, sizeof(x_buffer))) > 0) {
            _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/etc/");
            x_buffer[sizeof(x_buffer) - 1] = 0;
            if (0 == _access(x_buffer, 0)) {
                done = TRUE;
            }
        }

        // <INSTALLPATH>
        if (! done) {
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROGRAM_FILES, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/%s/etc/", ASPELL_APPLICATION_DIR);
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
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/%s/etc/", ASPELL_APPLICATION_DIR);
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
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/%s/etc/", ASPELL_APPLICATION_DIR);

            } else if (NULL != (env = getenv("ProgramFiles"))) {
                _snprintf(x_buffer, sizeof(x_buffer), "%s/%s/etc/", env, ASPELL_APPLICATION_DIR);

            } else {
                _snprintf(x_buffer, sizeof(x_buffer), "c:/Program Files/%s/etc/", ASPELL_APPLICATION_DIR);
            }
            x_buffer[sizeof(x_buffer) - 1] = 0;
            mkdir(x_buffer);
        }

        unixpath(x_buffer);
    }
    return x_buffer;
}


/**
 *  Retrieve global/share configuration path, equivalent to '/usr/share/aspell'.
 *
 *      <EXEPATH>
 *          <exepath>\share\
 *
 *      <INSTALLPATH>
 *          X:\Program Files\<aspell>\share
 *
 *              SHGetFolderPath(CSIDL_PROGRAM_FILES)
 *              or getenv(ProgramFiles)
 *
 *      <APPDATA>
 *          X:\Documents and Settings\All Users\Application Data\<aspell>\share\
 *
 *              SHGetFolderPath(CSIDL_COMMON_APPDATA)
 *              or getenv(ALLUSERSPROFILE)
 */
extern "C" const char *
aspell_DATA_DIR(void)
{
    static char x_buffer[MAX_PATH];

    if (0 == x_buffer[0]) {
        int len, done = FALSE;

        // <EXEPATH>, generally same as INSTALLDIR
        if ((len = getexedir(x_buffer, sizeof(x_buffer))) > 0) {
            _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/share/");
            x_buffer[sizeof(x_buffer) - 1] = 0;
            if (0 == _access(x_buffer, 0)) {
                done = TRUE;
            }
        }

        // <INSTALLPATH>
        if (! done) {
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROGRAM_FILES, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/%s/share/", ASPELL_APPLICATION_DIR);
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
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/%s/share/", ASPELL_APPLICATION_DIR);
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
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/%s/share/", ASPELL_APPLICATION_DIR);

            } else if (NULL != (env = getenv("ProgramFiles"))) {
                _snprintf(x_buffer, sizeof(x_buffer), "%s/%s/share/", env, ASPELL_APPLICATION_DIR);

            } else {
                _snprintf(x_buffer, sizeof(x_buffer), "c:/Program Files/%s/share/", ASPELL_APPLICATION_DIR);
            }
            x_buffer[sizeof(x_buffer) - 1] = 0;
            mkdir(x_buffer);
        }

        unixpath(x_buffer);
    }
    return x_buffer;
}


/**
 *  Retrieve installation directory, equivalent to '/usr/bin'.
 *
 *      <EXEPATH>
 *          <exepath>\..
 *
 *      <INSTALLPATH>
 *          X:\Program Files\<aspell>
 *              SHGetFolderPath(CSIDL_PROGRAM_FILES)
 *              or getenv(ProgramFiles)
 */
extern "C" const char *
aspell_INSTALL_DIR(void)
{
    static char x_buffer[MAX_PATH];

    if (0 == x_buffer[0]) {
        int len, done = FALSE;

        // <EXEPATH>, generally same as INSTALLDIR
        if ((len = getexedir(x_buffer, sizeof(x_buffer))) > 0) {
            if (len > 4 && 0 == _stricmp(x_buffer + (len - 4), "bin\\")) {
                x_buffer[len - 4] = 0; // ..
            }
            done = TRUE;
        }

         // <INSTALLPATH>
        if (! done) {
            if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROGRAM_FILES, NULL, 0, x_buffer))) {
                len = strlen(x_buffer);
                _snprintf(x_buffer + len, sizeof(x_buffer) - len, "/%s/", ASPELL_APPLICATION_DIR);
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
                _snprintf(x_buffer, sizeof(x_buffer), "%s/%s/", env, ASPELL_APPLICATION_DIR);
            } else {
                _snprintf(x_buffer, sizeof(x_buffer), "c:/Program Files/%s/", ASPELL_APPLICATION_DIR);
            }
            x_buffer[sizeof(x_buffer) - 1] = 0;
            mkdir(x_buffer);
        }

        unixpath(x_buffer);
    }
    return x_buffer;
}


static int
getexedir(char *buf, int maxlen)
{
    if (GetModuleFileNameA(NULL, buf, maxlen)) {
        const int len = (int)strlen(buf);
        char *cp;

        for (cp = buf + len; (cp > buf) && (*cp != '\\'); cp--)
            /*cont*/;
        if ('\\' == *cp) {
            cp[1] = '\0';                       // remove program
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
