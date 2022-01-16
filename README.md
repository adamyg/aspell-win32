# aspell-win32

GNU Aspell [http://aspell.net] is a Free and Open Source spell checker designed to
eventually replace Ispell. It can either be used as a library or as an independent
spell checker. Its main feature is that it does a superior job of suggesting possible
replacements for a misspelled word than just about any other spell checker out there
for the English language.

The following tools need to be installed to build this package, based on aspell 0.60.8:

  * cmake
  * cygwin or msys
  * perl
  * Visual studio 2008+
  * Innosetup 5

Build and package

```

  git clone https://github.com/adamyg/aspell-win32.git

  cd aspell-win32
  git submodule init
  git submodule update
  mk-cmake

```

Package

```

  mk-cmake --package

```

Dictionary Package(s)

```

  mk-cmake --lang ALL
  mk-cmake --lang <LANG>

```

Current mk-cmake usage:

```

  mk-cmake [--release or --debug] [targets] [--cmake {path}] [--vsxxx]

  Prime Options:
    -i, --interactive     enable interactive package creation.

  Targets:
    --prime               prime only.
    --build               build only.
    --also-package        also package, with prime or build.
    --package             package only.
    --lang LANG           buid dictionary for language.

    --lang_list           list dictionaries.

  Toolchains:
    --vs90   Visual Studio 9 2008
    --vs100  Visual Studio 10 2010
    --vs110  Visual Studio 11 2012
    --vs120  Visual Studio 12 2013
    --vs140  Visual Studio 14 2015 (default)
    --vs141  Visual Studio 15 2017
    --vs142  Visual Studio 16 2019
    --vs143  Visual Studio 17 2022

```

You will then need to install a dictionary package for the new Aspell.

