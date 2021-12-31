#
# libaspell: manual generation
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
set(DOC_OUTPUT_DIRECTORY "${MSVC_OUTPUT_DIRECTORY}/doc")
file(MAKE_DIRECTORY "${DOC_OUTPUT_DIRECTORY}")

foreach(man_page ${MANUAL_PAGES})

        # Get the filename from the full path.
        get_filename_component(man_page_name ${man_page} NAME_WLE)
     ## message("build: man_page ${man_page_name} [${DOC_OUTPUT_DIRECTORY}/${man_page_name}.txt]")

        # Add a new custom target for the current header.
        add_custom_target(
                man_page_${man_page_name} ALL
                COMMENT "build: man_page [${man_page_name}.txt]"
                COMMAND ../../../win32port/mandoc/mandoc -T ascii -O width=98 ${man_page} > ${DOC_OUTPUT_DIRECTORY}/${man_page_name}.txt
                VERBATIM #note: spaces around redirection operator ">"
                )
        add_dependencies(man-pages man_page_${man_page_name})

endforeach()

#end
