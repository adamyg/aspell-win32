#
# PDCurses: 3.9
#

set(PROJECT_NAME PDCurses)
set(ROOT_NAMESPACE PDCurses)

################################################################################
# Source groups
################################################################################

set(Header_Files
        "../../submodule/PDCurses/curses.h"
        "../../submodule/PDCurses/curspriv.h"
        "../../submodule/PDCurses/panel.h"
        )
source_group("Header Files" FILES ${Header_Files})

set(Header_Files__win32
        "../../submodule/PDCurses/wincon/pdcwin.h"
        )
source_group("Header Files\\win32" FILES ${Header_Files__win32})

set(Source_Files__lib
        "../../submodule/PDCurses/pdcurses/addch.c"
        "../../submodule/PDCurses/pdcurses/addchstr.c"
        "../../submodule/PDCurses/pdcurses/addstr.c"
        "../../submodule/PDCurses/pdcurses/attr.c"
        "../../submodule/PDCurses/pdcurses/beep.c"
        "../../submodule/PDCurses/pdcurses/bkgd.c"
        "../../submodule/PDCurses/pdcurses/border.c"
        "../../submodule/PDCurses/pdcurses/clear.c"
        "../../submodule/PDCurses/pdcurses/color.c"
        "../../submodule/PDCurses/pdcurses/debug.c"
        "../../submodule/PDCurses/pdcurses/delch.c"
        "../../submodule/PDCurses/pdcurses/deleteln.c"
        "../../submodule/PDCurses/pdcurses/getch.c"
        "../../submodule/PDCurses/pdcurses/getstr.c"
        "../../submodule/PDCurses/pdcurses/getyx.c"
        "../../submodule/PDCurses/pdcurses/inch.c"
        "../../submodule/PDCurses/pdcurses/inchstr.c"
        "../../submodule/PDCurses/pdcurses/initscr.c"
        "../../submodule/PDCurses/pdcurses/inopts.c"
        "../../submodule/PDCurses/pdcurses/insch.c"
        "../../submodule/PDCurses/pdcurses/insstr.c"
        "../../submodule/PDCurses/pdcurses/instr.c"
        "../../submodule/PDCurses/pdcurses/kernel.c"
        "../../submodule/PDCurses/pdcurses/keyname.c"
        "../../submodule/PDCurses/pdcurses/mouse.c"
        "../../submodule/PDCurses/pdcurses/move.c"
        "../../submodule/PDCurses/pdcurses/outopts.c"
        "../../submodule/PDCurses/pdcurses/overlay.c"
        "../../submodule/PDCurses/pdcurses/pad.c"
        "../../submodule/PDCurses/pdcurses/panel.c"
        "../../submodule/PDCurses/pdcurses/printw.c"
        "../../submodule/PDCurses/pdcurses/refresh.c"
        "../../submodule/PDCurses/pdcurses/scanw.c"
        "../../submodule/PDCurses/pdcurses/scr_dump.c"
        "../../submodule/PDCurses/pdcurses/scroll.c"
        "../../submodule/PDCurses/pdcurses/slk.c"
        "../../submodule/PDCurses/pdcurses/termattr.c"
        "../../submodule/PDCurses/pdcurses/touch.c"
        "../../submodule/PDCurses/pdcurses/util.c"
        "../../submodule/PDCurses/pdcurses/window.c"
        )
source_group("Source Files\\lib" FILES ${Source_Files__lib})

set(Source_Files__win32
        "../../submodule/PDCurses/wincon/pdcclip.c"
        "../../submodule/PDCurses/wincon/pdcdisp.c"
        "../../submodule/PDCurses/wincon/pdcgetsc.c"
        "../../submodule/PDCurses/wincon/pdckbd.c"
        "../../submodule/PDCurses/wincon/pdcscrn.c"
        "../../submodule/PDCurses/wincon/pdcsetsc.c"
        "../../submodule/PDCurses/wincon/pdcutil.c"
        )
source_group("Source Files\\win32" FILES ${Source_Files__win32})

set(ALL_FILES
        ${Header_Files}
        ${Header_Files__win32}
        ${Source_Files__lib}
        ${Source_Files__win32}
        )


################################################################################
# Target
################################################################################

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

set(SHARED_VERSION "-3.9")
add_library(${PROJECT_NAME}${SHARED_VERSION} SHARED ${ALL_FILES})
use_props(${PROJECT_NAME}${SHARED_VERSION} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")


################################################################################
# Include directories
################################################################################

include_directories(PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/PDCurses"
        )


################################################################################
# Compile and link options
################################################################################

add_compile_options(PRIVATE
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )

set_property(TARGET ${PROJECT_NAME} PROPERTY
        "$<$<CONFIG:Debug>:MultiThreadedDebugDLL>"
        "$<$<CONFIG:Release>:MultiThreadedDLL>"
        )

set_property(TARGET ${PROJECT_NAME}${SHARED_VERSION} PROPERTY
        "$<$<CONFIG:Debug>:MultiThreadedDebugDLL>"
        "$<$<CONFIG:Release>:MultiThreadedDLL>"
        )

target_compile_definitions(${PROJECT_NAME}${SHARED_VERSION} PRIVATE
        "PDC_DLL_BUILD"
        )

add_compile_definitions(PRIVATE
        "_DEBUG;"
        "_WINDOWS;"
        "_MBCS;"
        )

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        add_compile_definitions(PRIVATE
                "WIN64;"
                "WIN32;"
                )
        add_link_options(PRIVATE
                /MACHINE:X64;
                /SUBSYSTEM:WINDOWS
        )

elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        add_compile_definitions(PRIVATE
                "WIN32;"
                )
        add_link_options(PRIVATE
                /MACHINE:X86;
                /SUBSYSTEM:WINDOWS
        )
endif()

add_link_options(PRIVATE
        $<$<CONFIG:Debug>:/DEBUG:FULL>
        )

##end
