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

## Windows 11

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
