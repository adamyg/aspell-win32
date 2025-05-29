#
# aspell: 0.60.x
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

set(PROJECT_NAME aspell)
set(ROOT_NAMESPACE libaspell)

################################################################################
# Source groups
################################################################################

set(Header_Files
        "../../submodule/aspell/prog/check_funs.hpp"
        "../../submodule/aspell/prog/checker_string.hpp"
        )
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
        "../../submodule/aspell/prog/aspell.cpp"
        "../../submodule/aspell/prog/check_funs.cpp"
        "../../submodule/aspell/prog/checker_string.cpp"
        )
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
        ${Header_Files}
        ${Source_Files}
        "Aspell.rc"
        )

string(TIMESTAMP RC_BUILD_DATE "%Y%m%d")
set(RC_FILEDESCRIPTION "aspell - command line utility")
set(RC_ORIGINALNAME "aspell.exe")
configure_file(
        "../../win32port/Aspell.rc.in"
        "Aspell.rc" @ONLY
        )


################################################################################
# Target
################################################################################

add_executable(${PROJECT_NAME} ${ALL_FILES})
use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")


################################################################################
# Include directories
################################################################################

include_directories(${CMAKE_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/PDCurses"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port/libintl"
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/interfaces/cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/common"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/modules/speller/default"
        )


################################################################################
# Dependencies
################################################################################

target_link_libraries(${PROJECT_NAME} PDCurses libaspell win32port_MD)


################################################################################
# Compile and link options
################################################################################

target_compile_options(${PROJECT_NAME} PRIVATE
        /FI../../win32port/msvcpatch.h;
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )

set_property(TARGET ${PROJECT_NAME} PROPERTY
        "$<$<CONFIG:Debug>:MultiThreadedDebugDLL>"
        "$<$<CONFIG:Release>:MultiThreadedDLL>"
        )

target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:_DEBUG;>"
     ## "$<$<CONFIG:Release>:NDEBUG;>"  ## libaspell requirement.
        "_WINDOWS;"
        "_MBCS;"
        )

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_definitions(${PROJECT_NAME} PRIVATE
                "WIN64;"
                "WIN32;"
                )
        target_link_options(${PROJECT_NAME} PRIVATE
                /MACHINE:X64;
                /SUBSYSTEM:CONSOLE
                )

elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_definitions(${PROJECT_NAME} PRIVATE
                "WIN32;"
                )
        target_link_options(${PROJECT_NAME} PRIVATE
                /MACHINE:X86;
                /SUBSYSTEM:CONSOLE
                )
endif()

target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:/DEBUG:FULL>
        )


###############################################################################
# Package
###############################################################################

option(PACKAGE_INTERACTIVE "Interactive packaging creation" ON)
if (PACKAGE_INTERACTIVE)
        set(ISS_COMPILER "C:/Program Files (x86)/Inno Setup 5/Compil32")
        set(ISS_COMPILER_OPTIONS "")
else()
        set(ISS_COMPILER "C:/Program Files (x86)/Inno Setup 5/iscc")
        set(ISS_COMPILER_OPTIONS "/Qp")
endif()

set(ISS_SETUP_DIRECTORY "${CMAKE_SOURCE_DIR}/../installer.vs${MSVC_TOOLSET_VERSION}") ##FIXME: target
set(ISS_SOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/../submodule/aspell/")
set(ISS_BUILD_DIRECTORY ${MSVC_OUTPUT_DIRECTORY})
set(ISS_ARCHITECTURE ${CMAKE_VS_PLATFORM_NAME})

configure_file(
        "../../win32port/Aspell.iss.in"
        ${CMAKE_BINARY_DIR}/Aspell.iss @ONLY
        )

add_custom_target(package
        COMMENT "Packaging: aspell-${ASPELL_VERSION} [${ISS_COMPILER} Aspell.iss]"
        DEPENDS ${CMAKE_BINARY_DIR}/Aspell.iss
        COMMAND ${ISS_COMPILER} ${ISS_COMPILER_OPTIONS} ${CMAKE_BINARY_DIR}/Aspell.iss
        )

#end

