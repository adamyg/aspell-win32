@echo off
rem #
rem # Adam Young, 2021 - 2025.
rem #
rem # This file is part of the aspell-win32.
rem #
rem # Permission is hereby granted, free of charge, to any person obtaining a copy
rem # of this software and associated documentation files (the "Software"), to deal
rem # in the Software without restriction, including without limitation the rights
rem # to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
rem # copies of the Software, and to permit persons to whom the Software is
rem # furnished to do so, subject to the following conditions:
rem # The above copyright notice and this permission notice shall be included in all
rem # copies or substantial portions of the Software.
rem #
rem # THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
rem # IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
rem # FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
rem # AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
rem # LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
rem # OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
rem # SOFTWARE.
rem #

set CMAKE="C:/Program Files/cmake/bin/cmake"
set CONFIG=release
set TOOLCHAIN="Visual Studio 14 2015"
set MSVC=vs140
set PRIME=yes
set BUILD=yes
set PACKAGE=no
set DICTIONARY=
set INTERACTIVE=OFF
set X86=yes
set X64=yes

:Arguments
if "%1"=="" goto Continue
if "%1"=="--release" (
        set CONFIG=release
        shift
        goto Arguments
        )
if "%1"=="--debug" (
        set CONFIG=debug
        shift
        goto Arguments
        )

if "%1"=="--prime" (
        set PRIME=yes
        set BUILD=no
        set PACKAGE=no
        shift
        goto Arguments
        )
if "%1"=="--build" (
        set PRIME=no
        set BUILD=yes
        set PACKAGE=no
        shift
        goto Arguments
        )
if "%1"=="--package" (
        set PRIME=no
        set BUILD=no
        set PACKAGE=yes
        shift
        goto Arguments
        )
if "%1"=="--lang_list" (
        set DICTIONARY=dictionary_list
        set PRIME=no
        set BUILD=no
        set PACKAGE=no
        shift
        goto Arguments
        )
if "%1"=="--lang" (
        if "%2"=="" goto Help
        if "%2"=="ALL" (
                set DICTIONARY=dictionaries
        ) else (
                set DICTIONARY=dictionary_%2
        )
        set PRIME=no
        set BUILD=no
        set PACKAGE=no
        shift
        shift
        goto Arguments
        )

if "%1"=="--also-package" (
        set PACKAGE=yes
        shift
        goto Arguments
        )
if "%1"=="--interactive" (
        set INTERACTIVE=ON
        shift
        goto Arguments
        )
if "%1"=="-i" (
        set INTERACTIVE=ON
        shift
        goto Arguments
        )

if "%1"=="--cmake" (
        set CONFIG=Debug
        shift
        if "%1"=="" goto Help
        set CMAKE=%1
        shift
        goto Arguments
        )

if "%1"=="--vs90" (
        set TOOLCHAIN="Visual Studio 9 2008"
        set MSVC=vs90
        set X64=no
        shift
        goto Arguments
        )
if "%1"=="--vs100" (
        set TOOLCHAIN="Visual Studio 10 2010"
        set MSVC=vs100
        set X64=no
        shift
        goto Arguments
        )
if "%1"=="--vs110" (
        set TOOLCHAIN="Visual Studio 11 2012"
        set MSVC=vs110
        shift
        goto Arguments
        )
if "%1"=="--vs120" (
        set TOOLCHAIN="Visual Studio 12 2013"
        set MSVC=vs120
        shift
        goto Arguments
        )
if "%1"=="--vs140" (
        set TOOLCHAIN="Visual Studio 14 2015"
        set MSVC=vs140
        shift
        goto Arguments
        )
if "%1"=="--vs141" (
        set TOOLCHAIN="Visual Studio 15 2017"
        set MSVC=vs141
        shift
        goto Arguments
        )
if "%1"=="--vs142" (
        set TOOLCHAIN="Visual Studio 16 2019"
        set MSVC=vs142
        shift
        goto Arguments
        )
if "%1"=="--vs143" (
        set TOOLCHAIN="Visual Studio 17 2022"
        set MSVC=vs143
        shift
        goto Arguments
        )

if "%1"=="--Win32" (
:Win32
        set X86=yes
        set X64=no
        shift
        goto Arguments
        )
if "%1"=="--x86" goto Win32
if "%1"=="--x64" (
        set X86=no
        set X64=yes
        shift
        goto Arguments
        )

if "%1"=="--help" goto Help
if "%1"=="-h" goto Help
if "%1"=="-?" goto Help

        echo mk-cmake: invalid argument, %1

:Help
        echo #
        echo #  mk-cmake [--release or --debug] [targets] [--cmake {path}] [--vsxxx]
        echo #
        echo #  Prime Options:
        echo #    -i, --interactive     enable interactive package creation.
        echo #
        echo #  Targets:
        echo #    --prime               prime only.
        echo #    --build               build only.
        echo #    --also-package        also package, with prime or build.
        echo #    --package             package only.
        echo #    --lang LANG           build dictionary for language.
        echo #    --lang_list           list dictionaries.
        echo #
        echo #  Architecture:
        echo #    --Win32,x86           32-bit only.
        echo #    --x64                 64-bit only.
        echo #
        echo #  Toolchains:
        echo #    --vs90   Visual Studio 9 2008
        echo #    --vs100  Visual Studio 10 2010
        echo #    --vs110  Visual Studio 11 2012
        echo #    --vs120  Visual Studio 12 2013
        echo #    --vs140  Visual Studio 14 2015 (default)
        echo #    --vs141  Visual Studio 15 2017
        echo #    --vs142  Visual Studio 16 2019
        echo #    --vs143  Visual Studio 17 2022
        echo #
        goto exit

:Continue
        if "%PRIME%"=="yes" (
                if not exist "win32port\gen" (
                        @pushd win32port
                        call ./mk-src
                        call ./mk-static-src
                        @popd
                )
        )

        if "%X86%"=="yes" (
                if "%PRIME%"=="yes" (
                        %CMAKE% -G %TOOLCHAIN% -A Win32 -S CMakefiles -B "build_win32_%CONFIG%.%MSVC%" -DPACKAGE_INTERACTIVE=%INTERACTIVE%
                )
                if "%BUILD%"=="yes" (
                        %CMAKE% --build build_win32_%CONFIG%.%MSVC% --config %CONFIG%
                )
                if "%PACKAGE%"=="yes" (
                        %CMAKE% --build build_win32_%CONFIG%.%MSVC% --config %CONFIG% --target package
                )
        )

        if "%X64%"=="yes" (
                if "%PRIME%"=="yes" (
                        %CMAKE% -G %TOOLCHAIN% -A x64 -S CMakefiles -B "build_x64_%CONFIG%.%MSVC%" -DPACKAGE_INTERACTIVE=%INTERACTIVE%
                )
                if "%BUILD%"=="yes" (
                        %CMAKE% --build build_x64_%CONFIG%.%MSVC% --config %CONFIG%
                )
                if "%PACKAGE%"=="yes" (
                        %CMAKE% --build build_x64_%CONFIG%.%MSVC% --config %CONFIG% --target package
                )
        )

        if NOT "%DICTIONARY%"=="" (
                if "%DICTIONARY%"=="dictionary_list" (
                        %CMAKE% --build build_win32_%CONFIG%.%MSVC% --config %CONFIG% --target %DICTIONARY%
                ) else (
                        echo %CMAKE% --build build_win32_%CONFIG%.%MSVC% --config %CONFIG% --target aspell prezip-bin word-list-compress %DICTIONARY%
                        %CMAKE% --build build_win32_%CONFIG%.%MSVC% --config %CONFIG% --target aspell prezip-bin word-list-compress %DICTIONARY%
                )
        )

        taskkill /IM vctip.exe /f >nul 2>&1
        goto Exit

:Exit

