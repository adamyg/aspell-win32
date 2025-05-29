#
# libaspell: manual generation
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

set(PROJECT_NAME aspell-man-pages)
set(ROOT_NAMESPACE libaspell)

################################################################################
# Source groups
################################################################################

set(Manual_Pages
        "../../../submodule/aspell/manual/aspell-import.1"
        "../../../submodule/aspell/manual/aspell.1"
        "../../../submodule/aspell/manual/prezip-bin.1"
        "../../../submodule/aspell/manual/pspell-config.1"
        "../../../submodule/aspell/manual/run-with-aspell.1"
        "../../../submodule/aspell/manual/word-list-compress.1"
)
source_group("Manual Files" FILES ${Manual_Files})

set(MANUAL_PAGES
        ${Manual_Pages}
)

################################################################################
# Target
################################################################################

add_custom_target(man-pages)

if (NOT DEFINED ${MSVC_OUTPUT_DIRECTORY})
        set(MSVC_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../output.vs${MSVC_TOOLSET_VERSION}")
endif()
set(MAN_OUTPUT_DIRECTORY "${MSVC_OUTPUT_DIRECTORY}/man")
file(MAKE_DIRECTORY "${MAN_OUTPUT_DIRECTORY}")

foreach(man_page ${MANUAL_PAGES})

        # Get the filename from the full path.
        get_filename_component(man_page_name ${man_page} NAME_WLE)
        message("build: man_page ${man_page_name} [${MAN_OUTPUT_DIRECTORY}/${man_page_name}.txt]")

        # Add a new custom target for the current header.
        add_custom_target(
                man_page_${man_page_name} ALL
                COMMENT "building: man_page [${man_page_name}.txt]"
                COMMAND ../../../win32port/mandoc/mandoc -T ascii -O width=98 ${man_page} > ${MAN_OUTPUT_DIRECTORY}/${man_page_name}.txt
                VERBATIM #note: spaces around redirection operator ">"
                )
        add_dependencies(man-pages man_page_${man_page_name})

endforeach()

#end
