#ifndef DIRS_H_INCLUDED
#define DIRS_H_INCLUDED
#pragma once
/*
 *  WIN32 -- directories
 */

#define ASPELL_APPLICATION_DIR "aspell-0.60"    /* application directory */

#define DATA_DIR aspell_DATA_DIR()
#define DICT_DIR "<data-dir>"
#define CONF_DIR aspell_CONF_DIR()
#define PREFIX  aspell_INSTALL_DIR()

extern "C" const char *aspell_CONF_DIR();
extern "C" const char *aspell_DATA_DIR();
extern "C" const char *aspell_INSTALL_DIR();

#endif //DIRS_H_INCLUDED
