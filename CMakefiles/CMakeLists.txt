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

cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

set(CMAKE_SYSTEM_VERSION 8.1 CACHE STRING "" FORCE)

project(msvc C CXX)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
        set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32" OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
        message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
        "Debug"
        "Release"
        CACHE STRING "" FORCE
)

################################################################################
# Global compiler options
################################################################################
if(MSVC)
        # remove default flags provided with CMake for MSVC
        set(CMAKE_C_FLAGS "")
        set(CMAKE_C_FLAGS_DEBUG "")
        set(CMAKE_C_FLAGS_DEBUGSHARED "")
        set(CMAKE_C_FLAGS_RELEASE "")
        set(CMAKE_C_FLAGS_RELEASESHARED "")
        set(CMAKE_CXX_FLAGS "")
        set(CMAKE_CXX_FLAGS_DEBUG "")
        set(CMAKE_CXX_FLAGS_DEBUGSHARED "")
        set(CMAKE_CXX_FLAGS_RELEASE "")
        set(CMAKE_CXX_FLAGS_RELEASESHARED "")
endif()

################################################################################
# Global linker options
################################################################################
if(MSVC)
        # remove default flags provided with CMake for MSVC
        set(CMAKE_EXE_LINKER_FLAGS "")
        set(CMAKE_MODULE_LINKER_FLAGS "")
        set(CMAKE_SHARED_LINKER_FLAGS "")
        set(CMAKE_STATIC_LINKER_FLAGS "")
        set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
        set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
        set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
        set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
        set(CMAKE_EXE_LINKER_FLAGS_DEBUGSHARED "${CMAKE_EXE_LINKER_FLAGS}")
        set(CMAKE_MODULE_LINKER_FLAGS_DEBUGSHARED "${CMAKE_MODULE_LINKER_FLAGS}")
        set(CMAKE_SHARED_LINKER_FLAGS_DEBUGSHARED "${CMAKE_SHARED_LINKER_FLAGS}")
        set(CMAKE_STATIC_LINKER_FLAGS_DEBUGSHARED "${CMAKE_STATIC_LINKER_FLAGS}")
        set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
        set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
        set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
        set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
        set(CMAKE_EXE_LINKER_FLAGS_RELEASESHARED "${CMAKE_EXE_LINKER_FLAGS}")
        set(CMAKE_MODULE_LINKER_FLAGS_RELEASESHARED "${CMAKE_MODULE_LINKER_FLAGS}")
        set(CMAKE_SHARED_LINKER_FLAGS_RELEASESHARED "${CMAKE_SHARED_LINKER_FLAGS}")
        set(CMAKE_STATIC_LINKER_FLAGS_RELEASESHARED "${CMAKE_STATIC_LINKER_FLAGS}")
endif()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
        message(WARNING "No implementation of use_package. Create yours. "
                        "Package \"${PACKAGE}\" with version \"${VERSION}\" "
                        "for target \"${TARGET}\" is ignored!")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################

set(ASPELL_BUILD "2")
set(ASPELL_APPNAME "Aspell-0.60")
set(ASPELL_VERSION "0.60.8.1-build${ASPELL_BUILD}")
set(ASPELL_SHARED_VERSION "-0.60")
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set(SHARED_ARCH "-x64")
else()
        set(SHARED_ARCH "")
endif()

setup_package_version_variables(ASPELL)
add_definitions(-DENABLE_NLS=1)

add_subdirectory(win32port)

add_subdirectory(libaspell)
add_subdirectory(libaspell/man-pages)
add_subdirectory(libaspell/html-doc)
add_subdirectory(libaspell/example)
add_subdirectory(libaspell/list-dicts)
add_subdirectory(libaspell/make-dicts)
add_subdirectory(libaspell/locales)
add_subdirectory(libpspell)

add_subdirectory(PDCurses)
add_subdirectory(PDCurses/firework)
add_subdirectory(PDCurses/ozdemo)
add_subdirectory(PDCurses/tuidemo)
add_subdirectory(PDCurses/worm)

add_subdirectory(aspell)
add_subdirectory(word-list-compress)
add_subdirectory(prezip)

#end
