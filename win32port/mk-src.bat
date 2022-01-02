@echo off
set AUTODIR=..\submodule\aspell\auto
pushd %AUTODIR%
if "%PERL%"=="" set PERL=perl
%PERL% -I . ./mk-src.pl
popd
