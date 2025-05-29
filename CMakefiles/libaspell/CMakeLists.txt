#
# libaspell: 0.60.x
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

set(PROJECT_NAME libaspell)
set(ROOT_NAMESPACE libaspell)

################################################################################
# Source groups
################################################################################

set(Header_Files__common
        "../../submodule/aspell/common/asc_ctype.hpp"
        "../../submodule/aspell/common/basic_list.hpp"
        "../../submodule/aspell/common/block_slist-t.hpp"
        "../../submodule/aspell/common/block_slist.hpp"
        "../../submodule/aspell/common/cache-t.hpp"
        "../../submodule/aspell/common/cache.hpp"
        "../../submodule/aspell/common/can_have_error.hpp"
        "../../submodule/aspell/common/char_vector.hpp"
        "../../submodule/aspell/common/clone_ptr-t.hpp"
        "../../submodule/aspell/common/clone_ptr.hpp"
        "../../submodule/aspell/common/config.hpp"
        "../../submodule/aspell/common/convert.hpp"
        "../../submodule/aspell/common/copy_ptr.hpp"
        "../../submodule/aspell/common/document_checker.hpp"
        "../../submodule/aspell/common/enumeration.hpp"
        "../../submodule/aspell/common/error.hpp"
        "../../submodule/aspell/common/errors.hpp"
        "../../submodule/aspell/common/file_data_util.hpp"
        "../../submodule/aspell/common/file_util.hpp"
        "../../submodule/aspell/common/filter.hpp"
        "../../submodule/aspell/common/filter_char.hpp"
        "../../submodule/aspell/common/filter_char_vector.hpp"
        "../../submodule/aspell/common/filter_debug.hpp"
        "../../submodule/aspell/common/fstream.hpp"
        "../../submodule/aspell/common/generic_copy_ptr-t.hpp"
        "../../submodule/aspell/common/generic_copy_ptr.hpp"
        "../../submodule/aspell/common/getdata.hpp"
        "../../submodule/aspell/common/gettext.h"
        "../../submodule/aspell/common/hash-t.hpp"
        "../../submodule/aspell/common/hash.hpp"
        "../../submodule/aspell/common/hash_fun.hpp"
        "../../submodule/aspell/common/indiv_filter.hpp"
        "../../submodule/aspell/common/info.hpp"
        "../../submodule/aspell/common/iostream.hpp"
        "../../submodule/aspell/common/istream.hpp"
        "../../submodule/aspell/common/istream_enumeration.hpp"
        "../../submodule/aspell/common/itemize.hpp"
        "../../submodule/aspell/common/key_info.hpp"
        "../../submodule/aspell/common/lock.hpp"
        "../../submodule/aspell/common/lsort.hpp"
        "../../submodule/aspell/common/mutable_container.hpp"
        "../../submodule/aspell/common/mutable_string.hpp"
        "../../submodule/aspell/common/ndebug.hpp"
        "../../submodule/aspell/common/objstack.hpp"
        "../../submodule/aspell/common/ostream.hpp"
        "../../submodule/aspell/common/parm_string.hpp"
        "../../submodule/aspell/common/posib_err.hpp"
        "../../submodule/aspell/common/simple_string.hpp"
        "../../submodule/aspell/common/speller.hpp"
        "../../submodule/aspell/common/stack_ptr.hpp"
        "../../submodule/aspell/common/string.hpp"
        "../../submodule/aspell/common/string_enumeration.hpp"
        "../../submodule/aspell/common/string_list.hpp"
        "../../submodule/aspell/common/string_map.hpp"
        "../../submodule/aspell/common/string_pair.hpp"
        "../../submodule/aspell/common/string_pair_enumeration.hpp"
        "../../submodule/aspell/common/strtonum.hpp"
        "../../submodule/aspell/common/suggestions.hpp"
        "../../submodule/aspell/common/tokenizer.hpp"
        "../../submodule/aspell/common/type_id.hpp"
        "../../submodule/aspell/common/vararray.hpp"
        "../../submodule/aspell/common/vector.hpp"
        "../../submodule/aspell/common/version.cpp"
        "../../submodule/aspell/common/word_list.hpp"
        )
source_group("Header Files\\common" FILES ${Header_Files__common})

set(Header_Files__lib
        "../../submodule/aspell/lib/filter_entry.hpp"
        )
source_group("Header Files\\lib" FILES ${Header_Files__lib})

set(Header_Files__speller
        "../../submodule/aspell/modules/speller/default/affix.hpp"
        "../../submodule/aspell/modules/speller/default/asuggest.hpp"
        "../../submodule/aspell/modules/speller/default/block_vector.hpp"
        "../../submodule/aspell/modules/speller/default/check_list.hpp"
        "../../submodule/aspell/modules/speller/default/data.hpp"
        "../../submodule/aspell/modules/speller/default/data_id.hpp"
        "../../submodule/aspell/modules/speller/default/data_util.hpp"
        "../../submodule/aspell/modules/speller/default/editdist.hpp"
        "../../submodule/aspell/modules/speller/default/editdist2.hpp"
        "../../submodule/aspell/modules/speller/default/language.hpp"
        "../../submodule/aspell/modules/speller/default/leditdist.hpp"
        "../../submodule/aspell/modules/speller/default/matrix.hpp"
        "../../submodule/aspell/modules/speller/default/phonet.hpp"
        "../../submodule/aspell/modules/speller/default/phonetic.hpp"
        "../../submodule/aspell/modules/speller/default/primes.hpp"
        "../../submodule/aspell/modules/speller/default/speller_impl.hpp"
        "../../submodule/aspell/modules/speller/default/suggest.hpp"
        "../../submodule/aspell/modules/speller/default/typo_editdist.hpp"
        "../../submodule/aspell/modules/speller/default/vector_hash-t.hpp"
        "../../submodule/aspell/modules/speller/default/vector_hash.hpp"
        "../../submodule/aspell/modules/speller/default/weights.hpp"
        "../../submodule/aspell/modules/speller/default/wordinfo.hpp"
        )
source_group("Header Files\\speller" FILES ${Header_Files__speller})

set(Source_Files__common
        "../../submodule/aspell/common/cache.cpp"
        "../../submodule/aspell/common/can_have_error.cpp"
        "../../submodule/aspell/common/config.cpp"
        "../../submodule/aspell/common/convert.cpp"
        "../../submodule/aspell/common/document_checker.cpp"
        "../../submodule/aspell/common/error.cpp"
        "../../submodule/aspell/common/errors.cpp"
        "../../submodule/aspell/common/file_data_util.cpp"
        "../../submodule/aspell/common/file_util.cpp"
        "../../submodule/aspell/common/filter.cpp"
        "../../submodule/aspell/common/fstream.cpp"
        "../../submodule/aspell/common/getdata.cpp"
###     "../../submodule/aspell/common/gettext_init.cpp"
        "../../win32port/gettext_init.cpp"
        "../../submodule/aspell/common/info.cpp"
        "../../submodule/aspell/common/iostream.cpp"
        "../../submodule/aspell/common/itemize.cpp"
        "../../submodule/aspell/common/objstack.cpp"
        "../../submodule/aspell/common/posib_err.cpp"
        "../../submodule/aspell/common/speller.cpp"
        "../../submodule/aspell/common/string.cpp"
        "../../submodule/aspell/common/string_list.cpp"
        "../../submodule/aspell/common/string_map.cpp"
        "../../submodule/aspell/common/strtonum.cpp"
        "../../submodule/aspell/common/tokenizer.cpp"
        )
source_group("Source Files\\common" FILES ${Source_Files__common})

set(Source_Files__filter
        "../../submodule/aspell/modules/filter/context.cpp"
        "../../submodule/aspell/modules/filter/email.cpp"
        "../../submodule/aspell/modules/filter/markdown.cpp"
        "../../submodule/aspell/modules/filter/nroff.cpp"
        "../../submodule/aspell/modules/filter/sgml.cpp"
        "../../submodule/aspell/modules/filter/tex.cpp"
        "../../submodule/aspell/modules/filter/texinfo.cpp"
        "../../submodule/aspell/modules/filter/url.cpp"
        )
source_group("Source Files\\filter" FILES ${Source_Files__filter})

set(Source_Files__lib
        "../../submodule/aspell/lib/can_have_error-c.cpp"
        "../../submodule/aspell/lib/config-c.cpp"
        "../../submodule/aspell/lib/document_checker-c.cpp"
        "../../submodule/aspell/lib/dummy.cpp"
        "../../submodule/aspell/lib/error-c.cpp"
        "../../submodule/aspell/lib/filter-c.cpp"
        "../../submodule/aspell/lib/find_speller.cpp"
        "../../submodule/aspell/lib/info-c.cpp"
        "../../submodule/aspell/lib/mutable_container-c.cpp"
        "../../submodule/aspell/lib/new_checker.cpp"
        "../../submodule/aspell/lib/new_config.cpp"
        "../../submodule/aspell/lib/new_filter.cpp"
        "../../submodule/aspell/lib/new_fmode.cpp"
        "../../submodule/aspell/lib/speller-c.cpp"
        "../../submodule/aspell/lib/string_enumeration-c.cpp"
        "../../submodule/aspell/lib/string_list-c.cpp"
        "../../submodule/aspell/lib/string_map-c.cpp"
        "../../submodule/aspell/lib/string_pair_enumeration-c.cpp"
        "../../submodule/aspell/lib/word_list-c.cpp"
        )
source_group("Source Files\\lib" FILES ${Source_Files__lib})

set(Source_Files__speller
        "../../submodule/aspell/modules/speller/default/affix.cpp"
        "../../submodule/aspell/modules/speller/default/data.cpp"
        "../../submodule/aspell/modules/speller/default/editdist.cpp"
        "../../submodule/aspell/modules/speller/default/language.cpp"
        "../../submodule/aspell/modules/speller/default/leditdist.cpp"
        "../../submodule/aspell/modules/speller/default/multi_ws.cpp"
        "../../submodule/aspell/modules/speller/default/phonet.cpp"
        "../../submodule/aspell/modules/speller/default/phonetic.cpp"
        "../../submodule/aspell/modules/speller/default/primes.cpp"
        "../../submodule/aspell/modules/speller/default/readonly_ws.cpp"
        "../../submodule/aspell/modules/speller/default/speller_impl.cpp"
        "../../submodule/aspell/modules/speller/default/suggest.cpp"
        "../../submodule/aspell/modules/speller/default/typo_editdist.cpp"
        "../../submodule/aspell/modules/speller/default/writable.cpp"
        )
source_group("Source Files\\speller" FILES ${Source_Files__speller})

set(Source_Files__tokenizer
        "../../submodule/aspell/modules/tokenizer/basic.cpp"
        )
source_group("Source Files\\tokenizer" FILES ${Source_Files__tokenizer})

set(ALL_FILES
        ${Header_Files__common}
        ${Header_Files__lib}
        ${Header_Files__speller}
        ${Source_Files__common}
        ${Source_Files__filter}
        ${Source_Files__lib}
        ${Source_Files__speller}
        ${Source_Files__tokenizer}
        "libaspell.rc"
        )

string(TIMESTAMP RC_BUILD_DATE "%Y%m%d")
set(RC_FILEDESCRIPTION "libaspell - aspell dynamic library")
set(RC_ORIGINALNAME "libaspell${ASPELL_SHARED_VERSION}.dll")
configure_file(
        "../../win32port/Aspell.rc.in"
        "libaspell.rc" @ONLY
        )


################################################################################
# Target
################################################################################

include_directories(${CMAKE_BINARY_DIR})

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

add_library(${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} SHARED ${ALL_FILES} "../../win32port/libaspell.def")
use_props(${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

target_link_libraries(${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} win32port_MT)


################################################################################
# Include directories
################################################################################

include_directories(PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port/gen"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port/libintl"
        )

include_directories(PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../../win32port"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../submodule/aspell/common"
        )


################################################################################
# Compile and link options
################################################################################

target_compile_options(${PROJECT_NAME} PRIVATE
        /FI../../win32port/msvcpatch.h;
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )

target_compile_options(${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} PRIVATE
        /FI../../win32port/msvcpatch.h;
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )

set_property(TARGET ${PROJECT_NAME} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"  ## -MD[d]
        )

set_property(TARGET ${PROJECT_NAME}${ASPELL_SHARED_VERSION}${SHARED_ARCH} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"  ## -MT[d]
        )

        # If Aspell is compiled with WIN32_RELOCATABLE=1, it can be run from any directory:
        # it will set prefix according to its install location (assuming it resides in prefix\\bin).
        #
        # Your personal wordlists will be saved in the prefix directory with their names changed from
        # .aspell.lang.* to lang.* (you can override the path by setting the HOME environment variable).

##add_compile_definitions(
##      "ENABLE_WIN32_RELOCATABLE=1"
##      )

add_compile_definitions(
        "$<$<CONFIG:Debug>:_DEBUG;>"
     ## "$<$<CONFIG:Release>:NDEBUG;>"  ## libaspell requirement.
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
