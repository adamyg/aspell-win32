#
# libpspell: 0.60.x
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
        )


################################################################################
# Target
################################################################################

add_library(${PROJECT_NAME}${ASPELL_SHARED_VERSION} SHARED ${ALL_FILES} "../../win32port/libaspell.def")
use_props(${PROJECT_NAME}${ASPELL_SHARED_VERSION} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
target_link_libraries(${PROJECT_NAME}${ASPELL_SHARED_VERSION} libaspell${ASPELL_SHARED_VERSION})


################################################################################
# Compile and link options
################################################################################

target_compile_options(${PROJECT_NAME}${ASPELL_SHARED_VERSION} PRIVATE
       ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
       ${DEFAULT_CXX_EXCEPTION_HANDLING}
       )

set_property(TARGET ${PROJECT_NAME}${ASPELL_SHARED_VERSION} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"    ## -MT[d]
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
##      "$<$<CONFIG:Release>:NDEBUG;>"  ## libaspell requirement.
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
