@echo off
set AUTODIR=..\submodule\aspell\auto
pushd %AUTODIR%
perl -I . ./mk-src.pl
popd
