/* -*- mode: c; indent-width: 4; -*- */
/*
 *  win32 langinfo() implementation
 */

#include <langinfo.h>

const char *
libintl_nl_langinfo(nl_item item)
{
    switch (item) {
    case CODESET: /* assume terminal is "utf-8" */
        return "UTF-8";
    }
    return "n/a";
}
