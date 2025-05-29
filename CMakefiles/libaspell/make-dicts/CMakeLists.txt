#
# libaspell: dictionaries
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

set(PROJECT_NAME dictionaries)
set(ROOT_NAMESPACE libaspell)

################################################################################
# Source groups
################################################################################

## Source: https://ftp.gnu.org/gnu/aspell/dict/0index.html
## URL: https://ftp.gnu.org/gnu/aspell/dict/<ID>/<Latest>

set(DICTIONARIES
        "af             Afrikaans                       aspell-af-0.50-0.tar.bz2                0.50-0"
        "am             Amharic                         aspell6-am-0.03-1.tar.bz2               0.03-1"
        "ar             Arabic                          aspell6-ar-1.2-0.tar.bz2                1.2-0"
        "ast            Asturian                        aspell6-ast-0.01.tar.bz2                0.01"
        "az             Azerbaijani                     aaspell6-az-0.02-0.tar.bz2              0.02-0"
        "be             Belarusian                      aspell5-be-0.01.tar.bz2                 0.01"
        "bg             Bulgarian                       aspell6-bg-4.1-0.tar.bz2                4.1-0"
        "bn             Bengali                         aspell6-bn-0.01.1-1.tar.bz2             0.01.1-1"
        "br             Breton                          aspell-br-0.50-2.tar.bz2                0.50-2"
        "ca             Catalan                         aspell6-ca-2.1.5-1.tar.bz2              2.1.5-1"
        "cs             Czech                           aspell6-cs-20040614-1.tar.bz2           20040614-1"
        "csb            Kashubian                       aspell6-csb-0.02-0.tar.bz2              0.02-0"
        "cy             Welsh                           aspell-cy-0.50-3.tar.bz2                0.50-3"
        "da             Danish                          aspell6-da-1.6.36-11-0.tar.bz2          1.6.36-11-0"
        "de             German                          aspell6-de-20161207-7-0.tar.bz2         20161207-7-0"
        "de-alt         \"German - Old Spelling\"       aspell6-de-alt-2.1-1.tar.bz2            2.1-1"
        "el             Greek                           aspell6-el-0.08-0.tar.bz2               0.08-0"
        "en             English                         aspell6-en-2020.12.07-0.tar.bz2         2020.12.07-0"
        "eo             Esperanto                       aspell6-eo-2.1.20000225a-2.tar.bz2      2.1.20000225a-2"
        "es             Spanish                         aspell6-es-1.11-2.tar.bz2               1.11-2"
        "et             Estonian                        aspell6-et-0.1.21-1.tar.bz2             0.1.21-1"
        "fa             Persian                         aspell6-fa-0.11-0.tar.bz2               0.11-0"
        "fi             Finnish                         aspell6-fi-0.7-0.tar.bz2                0.7-0"
        "fo             Faroese                         aspell5-fo-0.2.16-1.tar.bz2             0.2.16-1"
        "fr             French                          aspell-fr-0.50-3.tar.bz2                0.50-3"
        "fy             Frisian                         aspell6-fy-0.12-0.tar.bz2               0.12-0"
        "ga             Irish                           aspell5-ga-4.5-0.tar.bz2                4.5-0"
        "gd             Scottish                        aspell5-gd-0.1.1-1.tar.bz2              0.1.1-1"
        "gl             Galician                        aspell6-gl-0.5a-2.tar.bz2               0.5a-2"
        "grc            \"Ancient Greek\"               aspell6-grc-0.02-0.tar.bz2              0.02-0"
        "gu             Gujarati                        aspell6-gu-0.03-0.tar.bz2               0.03-0"
        "gv             \"Manx Gaelic\"                 aspell-gv-0.50-0.tar.bz2                0.50-0"
        "he             Hebrew                          aspell6-he-1.0-0.tar.bz2                1.0-0"
        "hi             Hindi                           aspell6-hi-0.02-0.tar.bz2               0.02-0"
        "hil            Hiligaynon                      aspell5-hil-0.11-0.tar.bz2              0.11-0"
        "hr             Croatian                        aspell-hr-0.51-0.tar.bz2                0.51-0"
        "hsb            \"Upper Sorbian\"               aspell6-hsb-0.02-0.tar.bz2              0.02-0"
        "hu             Hungarian                       aspell6-hu-0.99.4.2-0.tar.bz2           0.99.4.2-0"
        "hus            Huastec                         aspell6-hus-0.03-1.tar.bz2              0.03-1"
        "hy             Armenian                        aspell6-hy-0.10.0-0.tar.bz2             0.10.0-0"
        "ia             Interlingua                     aspell-ia-0.50-1.tar.bz2                0.50-1"
        "id             Indonesian                      aspell5-id-1.2-0.tar.bz2                1.2-0"
        "is             Icelandic                       aspell-is-0.51.1-0.tar.bz2              0.51.1-0"
        "it             Italian                         aspell6-it-2.2_20050523-0.tar.bz2       2.2_20050523-0"
        "kn             Kannada                         aspell6-kn-0.01-1.tar.bz2               0.01-1"
        "ku             Kurdi                           aspell5-ku-0.20-1.tar.bz2               0.20-1"
        "ky             Kirghiz                         aspell6-ky-0.01-0.tar.bz2               0.01-0"
        "la             Latin                           aspell6-la-20020503-0.tar.bz2           20020503-0"
        "lt             Lithuanian                      aspell6-lt-1.2.1-0.tar.bz2              1.2.1-0"
        "lv             Latvian                         aspell6-lv-0.5.5-1.tar.bz2              0.5.5-1"
        "mg             Malagasy                        aspell5-mg-0.03-0.tar.bz2               0.03-0"
        "mi             Maori                           aspell-mi-0.50-0.tar.bz2                0.50-0"
        "mk             Macedonian                      aspell-mk-0.50-0.tar.bz2                0.50-0"
        "ml             Malayalam                       aspell6-ml-0.03-1.tar.bz2               0.03-1"
        "mn             Mongolian                       aspell6-mn-0.06-2.tar.bz2               0.06-2"
        "mr             Marathi                         aspell6-mr-0.10-0.tar.bz2               0.10-0"
        "ms             Malay                           aspell-ms-0.50-0.tar.bz2                0.50-0"
        "mt             Maltese                         aspell-mt-0.50-0.tar.bz2                0.50-0"
        "nb             \"Norwegian Bokmal\"            aspell-nb-0.50.1-0.tar.bz2              0.50.1-0"
        "nds            \"Low Saxon\"                   aspell6-nds-0.01-0.tar.bz2              0.01-0"
        "nl             Dutch                           aspell-nl-0.50-2.tar.bz2                0.50-2"
        "nn             \"Norwegian Nynorsk\"           aspell-nn-0.50.1-1.tar.bz2              0.50.1-1"
        "ny             Chichewa                        aspell5-ny-0.01-0.tar.bz2               0.01-0"
        "or             Oriya                           aspell6-or-0.03-1.tar.bz2               0.03-1"
        "pa             Punjabi                         aspell6-pa-0.01-1.tar.bz2               0.01-1"
        "pl             Polish                          aspell6-pl-6.0_20061121-0.tar.bz2       6.0_20061121-0"
        "pt_BR          \"Brazilian Portuguese\"        aspell6-pt_BR-20131030-12-0.tar.bz2     20131030-12-0"
        "pt_PT          Portuguese                      aspell6-pt_PT-20190329-1-0.tar.bz2      20190329-1-0"
        "qu             Quechua                         aspell6-qu-0.02-0.tar.bz2               0.02-0"
        "ro             Romanian                        aspell5-ro-3.3-2.tar.bz2                3.3-2"
        "ru             Russian                         aspell6-ru-0.99f7-1.tar.bz2             0.99f7-1"
        "rw             Kinyarwanda                     aspell-rw-0.50-0.tar.bz2                0.50-0"
        "sc             Sardinian                       aspell5-sc-1.0.tar.bz2                  1.0"
        "sk             Slovak                          aspell6-sk-2.01-2.tar.bz2               2.01-2"
        "sl             Slovenian                       aspell-sl-0.50-0.tar.bz2                0.50-0"
        "sr             Serbian                         aspell6-sr-0.02.tar.bz2                 0.02"
        "sv             Swedish                         aspell-sv-0.51-0.tar.bz2                0.51-0"
        "sw             Swahili                         aspell-sw-0.50-0.tar.bz2                0.50-0"
        "ta             Tamil                           aspell6-ta-20040424-1.tar.bz2           20040424-1"
        "te             Telugu                          aspell6-te-0.01-2.tar.bz2               0.01-2"
        "tet            Tetum                           aspell5-tet-0.1.1.tar.bz2               0.1.1"
        "tk             Turkmen                         aspell5-tk-0.01-0.tar.bz2               0.01-0"
        "tl             Tagalog                         aspell5-tl-0.02-1.tar.bz2               0.02-1"
        "tn             Setswana                        aspell5-tn-1.0.1-0.tar.bz2              1.0.1-0"
        "tr             Turkish                         aspell-tr-0.50-0.tar.bz2                0.50-0"
        "uk             Ukrainian                       aspell6-uk-1.4.0-0.tar.bz2              1.4.0-0"
        "uz             Uzbek                           aspell6-uz-0.6-0.tar.bz2                0.6-0"
        "vi             Vietnamese                      aspell6-vi-0.01.1-1.tar.bz2             0.01.1-1"
        "wa             Walloon                         aspell-wa-0.50-0.tar.bz2                0.50-0"
        "yi             Yiddish                         aspell6-yi-0.01.1-1.tar.bz2             0.01.1-1"
        "zu             Zulu                            aspell-zu-0.50-0.tar.bz2                0.50-0"
        )


################################################################################
# Target
################################################################################

add_custom_target(dictionaries)
use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")


# --- installer
option(PACKAGE_INTERACTIVE "Interactive packaging creation" ON)
if (PACKAGE_INTERACTIVE)
        set(ISS_COMPILER "C:/Program Files (x86)/Inno Setup 5/Compil32")
else()
        set(ISS_COMPILER "C:/Program Files (x86)/Inno Setup 5/iscc")
endif()


# --- destination
set(DICTIONARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../installer.vs${MSVC_TOOLSET_VERSION}") ##FIXME: target
file(MAKE_DIRECTORY "${DICTIONARY_OUTPUT_DIRECTORY}")


# --- toolchain
find_path(BASH_PATH NAMES bash bash.exe HINTS "c:/Cygwin64/bin" "d:/Cygwin64/bin" "c:/tools/cygwin" NO_SYSTEM_ENVIRONMENT_PATH) #cygwin
if (BASH_PATH STREQUAL "BASH_PATH-NOTFOUND")
        find_path(BASH_PATH NAMES bash bash.exe HINTS "c:/msys64/usr/bin" "d:/msys64/usr/bin" ENV PATH) #githb-ci: cygwin/msys
endif()
message("bash: ${BASH_PATH}/bash")

find_path(WGET_PATH wget.exe HINTS "c:/Cygwin64/bin" "d:/Cygwin64/bin" "c:/tools/cygwin" NO_SYSTEM_ENVIRONMENT_PATH) #cygwin
if (WGET_PATH STREQUAL "WGET_PATH-NOTFOUND")
        find_path(WGET_PATH wget.exe HINTS "c:/msys64/usr/bin" "d:/msys64/usr/bin" ENV PATH) #githb-ci: cygwin/msys
endif()
message("wget: ${WGET_PATH}/wget")

find_path(TAR_PATH tar.exe HINTS "c:/Cygwin64/bin" "d:/Cygwin64/bin" "c:/tools/cygwin" NO_SYSTEM_ENVIRONMENT_PATH) #cygwin
if (TAR_PATH STREQUAL "TAR_PATH-NOTFOUND")
        find_path(TAR_PATH tar.exe HINTS "c:/msys64/usr/bin" "d:/msys64/usr/bin" ENV PATH) #githb-ci: cygwin/msys
endif()
message("tar:  ${TAR_PATH}/tar")


# --- targets

add_custom_target(
        dictionary_list
        COMMAND more Dictionaries.txt
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )

file(WRITE ${CMAKE_BINARY_DIR}/Dictionaries.txt "Dictionary List:\n\n")
foreach(dict_spec ${DICTIONARIES})

        # Component
        separate_arguments(dict_parts UNIX_COMMAND ${dict_spec})

        list(GET dict_parts 0 DICTIONARY_LANG) # en
        list(GET dict_parts 1 DICTIONARY_NAME) # English
        list(GET dict_parts 2 DICTIONARY_FILE) # aspell6-en-2020.12.07-0.tar.bz2
        list(GET dict_parts 3 DICTIONARY_VERSION) # 2020.12.07
        file(APPEND ${CMAKE_BINARY_DIR}/Dictionaries.txt "\t${DICTIONARY_LANG}\t${DICTIONARY_NAME}\n")

        setup_package_version_variables(DICTIONARY)
        if (${DICTIONARY_VERSION_BUILD} EQUAL 0)
                set(DICTIONARY_VERSION_BUILD ${ASPELL_BUILD})
        endif()
        set(DICTIONARY_IMPORT_DIRECTORY "${CMAKE_BINARY_DIR}/Dictionaries/${DICTIONARY_LANG}")
        file(MAKE_DIRECTORY "${DICTIONARY_IMPORT_DIRECTORY}")

        get_filename_component(dict_source_name ${DICTIONARY_FILE} NAME_WLE) #bz2
        get_filename_component(dict_source_name ${dict_source_name} NAME_WLE) #tar
        set(DICTIONARY_SOURCE_DIRECTORY "${DICTIONARY_IMPORT_DIRECTORY}/${dict_source_name}")

        configure_file(
                "../../../win32port/Dictionary.iss.in"
                ${CMAKE_BINARY_DIR}/Dictionary_${DICTIONARY_LANG}.iss @ONLY
                )

        # Dictionary custom target
        message("build: dictionary_${DICTIONARY_LANG} [${DICTIONARY_NAME}, ${DICTIONARY_FILE}, ${DICTIONARY_VERSION}]")

        add_custom_target(
                dictionary_${DICTIONARY_LANG}_import
                DEPENDS ${DICTIONARY_IMPORT_DIRECTORY}/${DICTIONARY_FILE}
                COMMENT "importing: ${DICTIONARY_FILE}"
                COMMAND if NOT EXIST \"${DICTIONARY_IMPORT_DIRECTORY}/${DICTIONARY_FILE}\" ${WGET_PATH}/wget -P . -nv https://ftp.gnu.org/gnu/aspell/dict/${DICTIONARY_LANG}/${DICTIONARY_FILE}
                COMMAND if NOT EXIST \"${DICTIONARY_SOURCE_DIRECTORY}\" ${TAR_PATH}/tar -xvjf ${DICTIONARY_FILE}
                WORKING_DIRECTORY ${DICTIONARY_IMPORT_DIRECTORY}
                )

        add_custom_target(
                dictionary_${DICTIONARY_LANG}_build
                DEPENDS dictionary_${DICTIONARY_LANG}_import
                COMMENT "configure: ${DICTIONARY_FILE}"
                COMMAND set "PATH=${MSVC_OUTPUT_DIRECTORY}/Release/bin;${BASH_PATH};%PATH%" ##FIXME: target
                COMMAND set "ASPELL_FLAGS=--data-dir=../../../../submodule/aspell/data"
                COMMAND ${BASH_PATH}/bash "-c" "./configure; make"
                WORKING_DIRECTORY ${DICTIONARY_SOURCE_DIRECTORY}
                )

        add_custom_target(
                dictionary_${DICTIONARY_LANG}
                DEPENDS dictionary_${DICTIONARY_LANG}_build
                COMMENT "building: dictionary_${DICTIONARY_LANG}"
                COMMAND ${ISS_COMPILER} ${CMAKE_BINARY_DIR}/Dictionary_${DICTIONARY_LANG}.iss
                )

        add_dependencies(dictionaries dictionary_${DICTIONARY_LANG})

endforeach()
file(APPEND ${CMAKE_BINARY_DIR}/Dictionaries.txt "\n\n")

#end

