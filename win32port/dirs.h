#ifndef DIRS_H_INCLUDED
#define DIRS_H_INCLUDED
#pragma once
/*
 *  WIN32 -- directories
 */

#include "buildinfo.h"

#define DATA_DIR aspell_DATA_DIR()
#define DICT_DIR "<data-dir>" /*<prefix:/dictionaries|prefix:/dict|data-dir>*/
#define CONF_DIR aspell_CONF_DIR()
#define PREFIX aspell_PREFIX_DIR()

extern "C" const char *aspell_CONF_DIR(void);
extern "C" const char *aspell_DATA_DIR(void);
extern "C" const char *aspell_DICT_DIR(void);
extern "C" const char *aspell_PREFIX_DIR(void);

#endif //DIRS_H_INCLUDED
