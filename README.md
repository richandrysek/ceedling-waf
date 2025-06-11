# ceedling-waf

[![CI](https://github.com/richandrysek/ceedling-waf/actions/workflows/build.yml/badge.svg)](https://github.com/richandrysek/ceedling-waf/actions/workflows/build.yml)

[andrysek](https://andrysek.de/)

This demo shows how to use the ceedling together with a waf build framework on a very simple embedded c project.

## System requirements

|SW Component                                                                                                   |Version                |
|---------------------------------------------------------------------------------------------------------------|-----------------------|
|[Ruby](https://www.ruby-lang.org/)                                                                             | ruby 3.0.4p208        |
|[Ceedling](https://github.com/ThrowTheSwitch/Ceedling)                                                         | 1.0.1-fb1ce6c         |
|[Python3](https://www.python.org/downloads/)                                                                   | 3.12.10               |
|[pip](https://pypi.org/project/pip/)                                                                           | 25.1.1                |
|[gcc](https://gcc.gnu.org/) - part of Ruby installation                                                        | 11.2.0                |
|[gcovr](https://pypi.org/project/gcovr/)                                                                       | 8.3                   |
|[git](https://git-scm.com/)                                                                                    | 2.49.0.windows.1      |


## Installation

---
**NOTE**

The ceedling runs with Ruby 3.0, newer versions are not yet ported.

---

## Windows 11 installation

To install the toolchain using exact versions, follow these steps in the PowerShell command line:

```powershell
winget install Python.Python.3.12
winget install Git.Git
winget install RubyInstallerTeam.RubyWithDevKit.3.0
$env:Path +=';C:\Ruby30-x64\bin\'
$env:PATH +=';C:\Ruby30-x64\msys64\mingw64\bin'
$env:PATH +=";C:\Users\$env:USERNAME\AppData\Local\Programs\Python\Python312\Scripts\"
python.exe -m pip install --upgrade pip
pip install gcovr==8.3
gem install ceedling -v 1.0.1
```

### Verify installation

Open a new PowerShell command line to verify the toolchain installation and set variables:

```powershell
> python --version
Python 3.12.10
> git --version
git version 2.49.0.windows.1
> ruby --version
ruby 3.0.4p208 (2022-04-12 revision 3fa771dded) [x64-mingw32]
> gcc -v
> Using built-in specs.
COLLECT_GCC=C:\Ruby30-x64\msys64\mingw64\bin\gcc.exe
COLLECT_LTO_WRAPPER=C:/Ruby30-x64/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/lto-wrapper.exe
Target: x86_64-w64-mingw32
Configured with: ../gcc-11.2.0/configure --prefix=/mingw64 --with-local-prefix=/mingw64/local --build=x86_64-w64-mingw32 --host=x86_64-w64-mingw32 --target=x86_64-w64-mingw32 --with-native-system-header-dir=/mingw64/include --libexecdir=/mingw64/lib --enable-bootstrap --enable-checking=release --with-arch=x86-64 --with-tune=generic --enable-languages=c,lto,c++,fortran,ada,objc,obj-c++,jit --enable-shared --enable-static --enable-libatomic --enable-threads=posix --enable-graphite --enable-fully-dynamic-string --enable-libstdcxx-filesystem-ts --enable-libstdcxx-time --disable-libstdcxx-pch --disable-libstdcxx-debug --enable-lto --enable-libgomp --disable-multilib --disable-rpath --disable-win32-registry --disable-nls --disable-werror --disable-symvers --with-libiconv --with-system-zlib --with-gmp=/mingw64 --with-mpfr=/mingw64 --with-mpc=/mingw64 --with-isl=/mingw64 --with-pkgversion='Rev10, Built by MSYS2 project' --with-bugurl=https://github.com/msys2/MINGW-packages/issues --with-gnu-as --with-gnu-ld --with-boot-ldflags='-pipe -Wl,--disable-dynamicbase -static-libstdc++ -static-libgcc' LDFLAGS_FOR_TARGET=-pipe --enable-linker-plugin-flags='LDFLAGS=-static-libstdc++\ -static-libgcc\ -pipe\ -Wl,--stack,12582912'
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 11.2.0 (Rev10, Built by MSYS2 project)
> pip --version
pip 25.1.1 from C:\Users\Docker\AppData\Local\Programs\Python\Python312\Lib\site-packages\pip (python 3.12)
> gcov --version
gcov (Rev10, Built by MSYS2 project) 11.2.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
> ceedling --version
Welcome to Ceedling!

  Ceedling => 1.0.1-fb1ce6c
  ----------------------
  C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-1.0.1/

  Build Frameworks
  ----------------------
       CMock => 2.6.0
       Unity => 2.6.1
  CException => 1.3.4
```

## Quick start

### Get project

Clone the repository and build waf tool chain. After that switch back to the main project directory

```powershell
git clone --recurse-submodules https://github.com/richandrysek/ceedling-waf
# for later updates of subrepositories
# git submodule update --init --recursive -v
cd ceedling-waf
cd waf
python ./waf-light configure build
cd ..
```

**NOTE:** The project contains a sub-repository.

### Build and run unit tests

Modify in a file project.yml a line : 'C:\Users\Docker\AppData\Local\Programs\Python\Python312\Scripts\',
exchange an user directory "Docker" with a current username. After that proceed commands below.

```powershell
python waf/waf configure --ceedling-options "gcov:all"  --check-c-compiler gcc --check-cxx-compiler g++
python waf/waf build
python waf/waf ceedling
```
By configuring the waf some ceedling options are used:

* ceedling-options - specify additional ceedling options; in this case a gcov code coverage reports are enabled
* check-c-compiler - specify which c compiler(s) shall be tried to test for an availability
* check-cxx-compiler - specify which c++ compiler(s) shall be tried to test for an availability

The code coverage report can be found in the path ".\build\ceedling\artifacts\gcov\GcovCoverageResults.html" .

![Code coverage overview (gcov)](./doc/imgs/gcov_summary.png)

For further details click on a specific c file.

The command ceedling can be also called separately by typing:

```
.\ceedling.cmd
```
