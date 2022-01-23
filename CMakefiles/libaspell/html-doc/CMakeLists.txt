#
# libaspell: manual generation
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

set(PROJECT_NAME aspell-html-doc)
set(ROOT_NAMESPACE libaspell)

################################################################################
# Source groups
################################################################################

set(Manual_Pages
        "../../../submodule/aspell/manual/aspell.texi"
        "../../../submodule/aspell/manual/aspell-dev.texi"
)
source_group("Manual Files" FILES ${Manual_Files})

set(MANUAL_PAGES
        ${Manual_Pages}
)

################################################################################
# Target
################################################################################

add_custom_target(html-doc)

# destination
if (NOT DEFINED ${MSVC_OUTPUT_DIRECTORY})
        set(MSVC_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../output.vs${MSVC_TOOLSET_VERSION}")
endif()
set(HTML_OUTPUT_DIRECTORY "${MSVC_OUTPUT_DIRECTORY}/html")
file(MAKE_DIRECTORY "${HTML_OUTPUT_DIRECTORY}")

# toolchain
find_path(MAKEINFO_PATH makeinfo HINTS "c:/Cygwin64/bin" "d:/Cygwin64/bin" ENV PATH) #cygwin
if (MAKEINFO_PATH STREQUAL "MAKEINFO_PATH-NOTFOUND")
        find_path(MAKEINFO_PATH makeinfo HINTS "c:/tools/cygwin" "c:/msys64/usr/bin" "d:/msys64/usr/bin" ENV PATH) #githb-ci: cygwin/msys
endif()
message("makeinfo: ${MAKEINFO_PATH}/makeinfo")

# targets
foreach(html_doc ${MANUAL_PAGES})

        # Get the filename from the full path.
        get_filename_component(html_doc_name ${html_doc} NAME_WLE)
        message("build: html_doc ${html_doc_name} [${HTML_OUTPUT_DIRECTORY}/${html_doc_name}]")

        # Add a new custom target for the current header.
        add_custom_target(
                html_doc_${html_doc_name} ALL
                COMMENT "building: html_doc [${html_doc_name}.texi]"
                COMMAND echo @set VERSION ${ASPELL_VERSION} > version.texi
                COMMAND ${MAKEINFO_PATH}/perl ${MAKEINFO_PATH}/makeinfo --html --enable-encoding --css-include=../../../submodule/aspell/manual/custom.css --output=${HTML_OUTPUT_DIRECTORY}/${html_doc_name} ${html_doc}
                VERBATIM
                )
        add_dependencies(html-doc html_doc_${html_doc_name})

endforeach()

#end

