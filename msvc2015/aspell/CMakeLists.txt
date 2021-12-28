set(PROJECT_NAME aspell)

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
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE libaspell)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG         "${PROJECT_NAME}$ENV{TargetExt}"
        TARGET_NAME_DEBUGSHARED   "${TARGET_NAME}$ENV{TargetExt}"
        TARGET_NAME_RELEASE       "${TARGET_NAME}$ENV{TargetExt}"
        TARGET_NAME_RELEASESHARED "${TARGET_NAME}$ENV{TargetExt}"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG         "${CMAKE_SOURCE_DIR}/$<CONFIG>"
        OUTPUT_DIRECTORY_DEBUGSHARED   "${CMAKE_SOURCE_DIR}/$<CONFIG>"
        OUTPUT_DIRECTORY_RELEASE       "${CMAKE_SOURCE_DIR}/$<CONFIG>"
        OUTPUT_DIRECTORY_RELEASESHARED "${CMAKE_SOURCE_DIR}/$<CONFIG>"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE       "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_RELEASESHARED "TRUE"
    )
endif()
################################################################################
# MSVC runtime library
################################################################################
get_property(MSVC_RUNTIME_LIBRARY_DEFAULT TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY)
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
        $<$<CONFIG:Debug>:
            MultiThreadedDebugDLL
        >
        $<$<CONFIG:DebugShared>:
            MultiThreadedDebugDLL
        >
        $<$<CONFIG:Release>:
            MultiThreadedDLL
        >
        $<$<CONFIG:ReleaseShared>:
            MultiThreadedDLL
        >
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:DebugShared>,$<CONFIG:Release>,$<CONFIG:ReleaseShared>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY_STR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/PDCurses;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/interfaces/cc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/common;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/modules/speller/default"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/PDCurses;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/interfaces/cc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/common;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/modules/speller/default"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:DebugShared>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "_NDEBUG;"
            "HAVE_CONFIG_H"
        ">"
        "$<$<CONFIG:ReleaseShared>:"
            "_NDEBUG;"
            "HAVE_CONFIG_H"
        ">"
        "WIN32;"
        "_WINDOWS;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /D_CRT_SECURE_NO_WARNINGS=1
            >
            $<$<CONFIG:Release>:
                /D_CRT_SECURE_NO_WARNINGS=1
            >
            $<$<CONFIG:ReleaseShared>:
                /D_CRT_SECURE_NO_WARNINGS=1
            >
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Gm;
                /Od;
                /RTC1;
                /ZI
            >
            $<$<CONFIG:DebugShared>:
                /Gm;
                /Od;
                /RTC1;
                /ZI;
                /DPDC_DLL_BUILD=1;
                /Y-
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy;
                /Zi
            >
            $<$<CONFIG:ReleaseShared>:
                /O2;
                /Oi;
                /Gy;
                /Zi;
                /Y-
            >
            /W3;
            /D_CRT_SECURE_NO_WARNINGS=1;
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            /DEBUG:FULL
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG:FULL
            >
            $<$<CONFIG:DebugShared>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Release>:
                /DEBUG;
                /MACHINE:X86;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:ReleaseShared>:
                /DEBUG;
                /MACHINE:X86;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    PDCurses
    libaspell
)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "$(OutDir)libaspell;"
            "$(OutDir)PDCurses"
        ">"
        "$<$<CONFIG:Release>:"
            "$(OutDir)libaspell;"
            "$(OutDir)PDCurses"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "$(OutDir)libaspell;"
            "$(OutDir)PDCurses"
        ">"
        "$<$<CONFIG:DebugShared>:"
            "$(OutDir)PDCurses;"
            "$(OutDir)libaspell"
        ">"
        "$<$<CONFIG:Release>:"
            "$(OutDir)libaspell;"
            "$(OutDir)PDCurses"
        ">"
    )
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

