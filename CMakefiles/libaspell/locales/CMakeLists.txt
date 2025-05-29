#
# libaspell: locale generation
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

set(PROJECT_NAME aspell-locales)
set(ROOT_NAMESPACE libaspell)

################################################################################
# Source groups
################################################################################

file(GLOB Locale_Pots
        "../../../submodule/aspell/po/*.po")

source_group("Po Files" FILES ${Locale_Pots})

set(ASPELL_POTS
        ${Locale_Pots}
)


################################################################################
# Target
################################################################################

add_custom_target(locales)


# destination
if (NOT DEFINED ${MSVC_OUTPUT_DIRECTORY})
        set(MSVC_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../output.vs${MSVC_TOOLSET_VERSION}")
endif()
set(POT_OUTPUT_DIRECTORY "${MSVC_OUTPUT_DIRECTORY}/locale")
file(MAKE_DIRECTORY "${POT_OUTPUT_DIRECTORY}")


# toolchain
find_path(MSGFMT_PATH msgfmt msgfmt.exe HINTS "c:/Cygwin64/bin" "d:/Cygwin64/bin") #cygwin
if (MSGFMT_PATH STREQUAL "MSGFMT_PATH-NOTFOUND")
        find_path(MSGFMT_PATH msgfmt msgfmt.exe HINTS "c:/msys64/mingw64/bin" "d:/msys64/mingw64/bin" ENV PATH) #mingw64
endif()
if (MSGFMT_PATH STREQUAL "MSGFMT_PATH-NOTFOUND")
        find_path(MSGFMT_PATH msgfmt msgfmt.exe HINTS "c:/tools/cygwin" "c:/msys64/usr/bin" "d:/msys64/usr/bin" ENV PATH) #githb-ci: cygwin/msys
endif()
message("msgfmt: ${MSGFMT_PATH}/msgfmt")


# targets
foreach(po_file ${ASPELL_POTS})

        # Get the filename from the full path.
        get_filename_component(po_file_name ${po_file} NAME_WLE)
        message("build: po_file ${po_file_name} [${POT_OUTPUT_DIRECTORY}/${po_file_name}]")
        file(MAKE_DIRECTORY "${POT_OUTPUT_DIRECTORY}/${po_file_name}/LC_MESSAGES/")

        # Add a new custom target for the current header.
        add_custom_target(
                po_file_${po_file_name} ALL
                COMMENT "building: po_file [${po_file_name}.texi]"
                COMMAND ${MSGFMT_PATH}/msgfmt --check --output=${POT_OUTPUT_DIRECTORY}/${po_file_name}/LC_MESSAGES/aspell.mo ${po_file}
                VERBATIM
                )
        add_dependencies(locales po_file_${po_file_name})

endforeach()

#end

