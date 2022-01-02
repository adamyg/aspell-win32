# aspell-win32

The following packages need to be installed to build this packaget:

  * cmake
  * perl
  * Visual studio 2008+
  * Innosetup

Build and package

```

  git clone https://github.com/adamyg/aspell-win32.git

  cd aspell-win32
  git submodule init
  git submodule update
  mk-cmake

```

Current mk-cmake usage:

```

  mk-cmake [--release or --debug] [targets] [--cmake {path}] [--vsxxx]

  Options:
    --package             package
    -i, --interactive     enable interactive package creation (during builds)

  Targets:
    --prime               prime only
    --build               build only
    --package-only        package only

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

You will then need to install a dictionary package for the new Aspell. You can find them at http://aspell.net.
