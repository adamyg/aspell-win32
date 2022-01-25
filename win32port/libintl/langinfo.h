#pragma once
/*
 *  <langinfo.h>
 */
 
#include <sys/cdefs.h>

__BEGIN_DECLS

typedef enum {
    CODESET = 0
} nl_item;

const char *libintl_nl_langinfo(nl_item item);
#define nl_langinfo(__a) libintl_nl_langinfo(__a)

__END_DECLS
