#
# libpspell: 0.60.x
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

set(PROJECT_NAME libpspell)
set(ROOT_NAMESPACE libpspell)

################################################################################
# Source groups
################################################################################

set(Source_Files__win32port
        "../../win32port/libpspell.c"
        )
source_group("Source Files\\win32port" FILES ${Source_Files__win32port})

set(ALL_FILES
        ${Source_Files__win32port}
        "libpspell.rc"
        )

string(TIMESTAMP RC_BUILD_DATE "%Y%m%d")
set(RC_FILEDESCRIPTION "libpspell - pspell dynamic binding for aspell")
set(RC_ORIGINALNAME "libpspell${ASPELL_SHARED_VERSION}.dll")
configure_file(
        "../../win32port/Aspell.rc.in"
        "libpspell.rc" @ONLY
        )


################################################################################
# Target
################################################################################

include_directories(${CMAKE_BINARY_DIR})

add_library(${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} SHARED ${ALL_FILES} "../../win32port/libaspell.def")
use_props(${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

target_link_libraries(${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} libaspell${ASPELL_SHARED_VERSION}${SHARED_ARCH} win32port_MT)


################################################################################
# Compile and link options
################################################################################

target_compile_options(${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} PRIVATE
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )

set_property(TARGET ${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"  ## -MT[d]
        )

        # If Aspell is compiled with WIN32_RELOCATABLE=1, it can be run from any directory:
        # it will set prefix according to its install location (assuming it resides in prefix\\bin).
        #
        # Your personal wordlists will be saved in the prefix directory with their names changed from
        # .aspell.lang.* to lang.* (you can override the path by setting the HOME environment variable).
        #
##add_compile_definitions(
##      "ENABLE_WIN32_RELOCATABLE=1"
##      )

add_compile_definitions(
        "$<$<CONFIG:Debug>:_DEBUG;>"
    ##  "$<$<CONFIG:Release>:NDEBUG;>"  ## libaspell requirement.
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
