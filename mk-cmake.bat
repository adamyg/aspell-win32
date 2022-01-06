@echo off

set CMAKE="C:/Program Files/cmake/bin/cmake"
set CONFIG=release
set TOOLCHAIN="Visual Studio 14 2015"
set MSVC=vs140
set PRIME=yes
set BUILD=yes
set PACKAGE=no
set INTERACTIVE=OFF
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

        echo mk-cmake: invalid argument, %1

:Help
        echo #
        echo #  mk-cmake [--release or --debug] [targets] [--cmake {path}] [--vsxxx]
        echo #
        echo #  Prime Options:
        echo #    -i, --interactive     enable interactive package creation.
        echo #
        echo #  Targets:
        echo #    --prime               prime only
        echo #    --build               build only
        echo #    --package             package only
        echo #
        echo #    --also-package        also package
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

        if "%PRIME%"=="yes" %CMAKE% -G %TOOLCHAIN% -A Win32 -S CMakefiles -B "build_win32_%CONFIG%.%MSVC%" -DPACKAGE_INTERACTIVE=%INTERACTIVE%
        if "%BUILD%"=="yes" %CMAKE% --build build_win32_%CONFIG%.%MSVC% --config %CONFIG%
        if "%PACKAGE%"=="yes" (
                %CMAKE% --build build_win32_%CONFIG%.%MSVC% --config %CONFIG% --target package
        )

        if "%X64%"=="yes" (
                if "%PRIME%"=="yes" %CMAKE% -G %TOOLCHAIN% -A x64 -S CMakefiles -B "build_x64_%CONFIG%.%MSVC%" -DPACKAGE_INTERACTIVE=%INTERACTIVE%
                if "%BUILD%"=="yes" %CMAKE% --build build_x64_%CONFIG%.%MSVC% --config %CONFIG%
        )
        goto Exit

:Exit
taskkill /IM vctip.exe /f >nul 2>&1

