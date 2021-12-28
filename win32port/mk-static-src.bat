@echo off
set GENDIR=../submodule/aspell/gen
set INFODIR=../submodule/aspell/modules/filter
mkdir gen
perl %GENDIR%/mk-static-filter.pl %INFODIR%/context-filter.info %INFODIR%/email-filter.info %INFODIR%/html-filter.info %INFODIR%/markdown-filter.info %INFODIR%/sgml-filter.info %INFODIR%/tex-filter.info %INFODIR%/texinfo-filter.info ./url-filter.info

