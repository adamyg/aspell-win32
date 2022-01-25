/*
 *  WIN32 -- aspell_gettext_init()
 */

#include "gettext.h"

#if !defined(ENABLE_NLS)
#error ENABLE_NLS not enabled ...
#endif
#pragma message("*** ENABLE_NLS enabled ...")

#include "lock.hpp"
#include "dirs.h" // aspell_LOCALE_DIR()

static acommon::Mutex lock;
static bool did_init = false;

extern "C" void
aspell_gettext_init()
{
#if defined(ENABLE_NLS)
    {
        acommon::Lock l(&lock);
        if (did_init) return;
        did_init = true;
    }
    bindtextdomain("aspell", aspell_LOCALE_DIR());

#endif
}

