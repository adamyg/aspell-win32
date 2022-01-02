#
# PDCurses: demo program
#

set(PROJECT_NAME ozdemo)
set(ROOT_NAMESPACE PDCurses)

################################################################################
# Source groups
################################################################################
set(Source_Files
        "../../../submodule/PDCurses/demos/ozdemo.c"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
        ${Source_Files}
)

################################################################################
# Target
################################################################################

add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

################################################################################
# Include directories
################################################################################

target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../submodule/PDCurses;"
        )

################################################################################
# Dependencies
################################################################################

target_link_libraries(${PROJECT_NAME} PDCurses)
add_dependencies(${PROJECT_NAME}
        PDCurses
        )

################################################################################
# Compile and link options
################################################################################

target_compile_options(${PROJECT_NAME} PRIVATE
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY
        "$<$<CONFIG:Debug>:MultiThreadedDebugDLL>"
        "$<$<CONFIG:Release>:MultiThreadedDLL>"
        )

target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:_DEBUG;>"
        "$<$<CONFIG:Release>:NDEBUG;>"
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

#end
