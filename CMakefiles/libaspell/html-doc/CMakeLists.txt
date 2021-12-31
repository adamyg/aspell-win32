#
# libaspell: manual generation
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
find_path(MAKEINFO_PATH makeinfo HINTS "c:/Cygwin64/bin" "d:/Cygwin64/bin" "C:/tools/cygwin" ENV PATH)
if (MAKEINFO_PATH STREQUAL "UNKNOWN")
        find_path(MAKEINFO_PATH makeinfo HINTS "c:/msys64/usr/bin" "d:/msys64/usr/bin" ENV PATH)
endif()
message("makeinfo: ${MAKEINFO_PATH}")

# targets
foreach(html_doc ${MANUAL_PAGES})

        # Get the filename from the full path.
        get_filename_component(html_doc_name ${html_doc} NAME_WLE)
        message("build: html_doc ${html_doc_name} [${HTML_OUTPUT_DIRECTORY}/${html_doc_name}]")

        # Add a new custom target for the current header.
        add_custom_target(
                html_doc_${html_doc_name} ALL
                COMMENT "building: html_doc [${html_doc_name}.texi]"
                COMMAND echo "@set VERSION aspell-0.60.8" > version.texi
                COMMAND ${MAKEINFO_PATH}/perl ${MAKEINFO_PATH}/makeinfo --html --enable-encoding --css-include=../../../submodule/aspell/manual/custom.css --output=${HTML_OUTPUT_DIRECTORY}/${html_doc_name} ${html_doc}
                VERBATIM
                )
        add_dependencies(html-doc html_doc_${html_doc_name})

endforeach()

#end

