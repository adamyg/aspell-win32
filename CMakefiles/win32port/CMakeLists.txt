#
# libaspell: 0.60.x - win32port
#
# Adam Young, 2021 - 2025.
#
# This file is part of the aspell-win32.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

set(PROJECT_NAME win32port)
set(ROOT_NAMESPACE aspell-win32)

################################################################################
# Source groups
################################################################################

set(Header_Files_win32port
        "../../win32port/dirent.h"
        "../../win32port/settings.h"
        )
source_group("Header Files\\win32port" FILES ${Header_Files_win32port})

set(Source_Files_win32port
        "../../win32port/dirent.c"
        "../../win32port/dirs.cpp"
        "../../win32port/dirs.h"
        )
source_group("Source Files\\win32port" FILES ${Source_Files_win32port})

###
set(Header_Files_iconv
        "../../win32port/libiconv/iconv.h"
        )
source_group("Header Files\\iconv" FILES ${Header_Files_iconv})

set(Source_Files_iconv
        "../../win32port/libiconv/win_iconv.c"
        )
source_group("Source Files\\iconv" FILES ${Source_Files_iconv})

###
set(Source_Files_intl
        "../../win32port/libintl/gettext.c"
        "../../win32port/libintl/gettext_iconv.c"
        "../../win32port/libintl/gettext_dummy.c"
        "../../win32port/libintl/plural_parser.c"
        "../../win32port/libintl/strhash.c"
        "../../win32port/libintl/sysdep.c"
        "../../win32port/libintl/textdomain.c"
        "../../win32port/libintl/tfind.c"
        "../../win32port/libintl/tsearch.c"
        "../../win32port/libintl/compat_strsep.c"
        "../../win32port/libintl/compat_strlcat.c"
        "../../win32port/libintl/compat_strlcpy.c"
        "../../win32port/libintl/compat_mman.c"
        "../../win32port/libintl/compat_langinfo.c"
        )
source_group("Source Files\\intl" FILES ${Source_Files_intl})

###
set(Source_Files_citrus
        "../../win32port/libcitrus/citrus_bcs.c"
        "../../win32port/libcitrus/citrus_memstream.c"
        )
source_group("Source Files\\citrus" FILES ${Source_Files_citrus})

###
set(ALL_FILES
        ${Header_Files_win32port}
        ${Source_Files_win32port}
        ${Header_Files_iconv}
        ${Source_Files_iconv}
        ${Header_Files_intl}
        ${Source_Files_intl}
        ${Header_Files_citrus}
        ${Source_Files_citrus}
        )


################################################################################
# Target
################################################################################

include_directories(${CMAKE_BINARY_DIR})
configure_file(
        "../../win32port/BuildInfo.h.in"
        "${CMAKE_BINARY_DIR}/BuildInfo.h" @ONLY
        )

add_library(${PROJECT_NAME}_MD STATIC ${ALL_FILES})
use_props(${PROJECT_NAME}_MD "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

add_library(${PROJECT_NAME}_MT STATIC ${ALL_FILES})
use_props(${PROJECT_NAME}_MT "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")


################################################################################
# Include directories
################################################################################

include_directories(PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port/libintl"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port/libiconv"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port/libcitrus"
        )


################################################################################
# Compile and link options
################################################################################

target_compile_options(${PROJECT_NAME}_MT PRIVATE
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )

target_compile_options(${PROJECT_NAME}_MD PRIVATE
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )

set_property(TARGET ${PROJECT_NAME}_MD PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL" ## -MD[d]
        )

set_property(TARGET ${PROJECT_NAME}_MT PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" ## -MT[d]
        )

add_compile_definitions(
        "$<$<CONFIG:Debug>:_DEBUG;>"
        "$<$<CONFIG:Release>:NDEBUG;>"
        "_WINDOWS;"
        "_MBCS;"
        )

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        add_compile_definitions(
                "WIN64;"
                "WIN32;"
        )
        add_link_options(
                /MACHINE:X64;
                /SUBSYSTEM:WINDOWS
        )

elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        add_compile_definitions(
                "WIN32;"
        )
        add_link_options(
                /MACHINE:X86;
                /SUBSYSTEM:WINDOWS
        )
endif()

add_link_options(
            $<$<CONFIG:Debug>:/DEBUG:FULL>
            )

##end
