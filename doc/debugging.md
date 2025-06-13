## Debugging
### Introduction

If some test failed/not failed and you do not know exactly why, than the debugging should help.

### Installation

#### gdb
Start msys64

```powershell
> C:\Ruby30-x64\msys64\mingw64.exe
```

Update the msys package database, please do it twice. After that install the gdb.
It may take a while and could ask to restart msys64 again.


```shell
$ pacman -Syu
$ pacman -Syu
$ pacman -S mingw-w64-x86_64-gdb
```

#### vscode-ceedling-test-adapter

Offical extension in the Visual Studio is not compatible with ceedling >1.0.0. Thereof
own buidl and VSIX File installation is needed.

1. Install build toolchain
   1. ```winget install Node.js```
   2. ```Set-ExecutionPolicy -ExecutionPolicy RemoteSigned```
   3. ```npm install -g @vscode/vsce```
2. Clone a fork of an official repository :
   ```git clone https://github.com/simeon-s1/vscode-ceedling-test-adapter.git```
3. Build the VSIX File
   1. ```npm install```
   2. ```npm audit fix```
   3. ```vsce package  # Generates a .vsix file```
4. Install VSIX File in the Visual Studio
   ```code --install-extension vscode-ceedling-test-adapter-multi-2.0.0.vsix```

### Run all tests

1. Open Visual Code IDE with the directory "ceedling-waf"
2. In Menu click on "View->Command Pallete"
3. Type "Run all tests"

### References

[how to install gdb from superuser.com](https://superuser.com/questions/1747118/how-to-download-gdb-from-mingw-correctly)

[Howto debug Ceedling Unit-Tests from medtech-ingenieur.de](https://medtech-ingenieur.de/howto-debug-ceedling-unit-tests/)

[Visual code settings](https://gist.github.com/bd2357/b2d69ab18849c1e2f70959eef426ff09)

[Visual code ceedling test adapter](https://marketplace.visualstudio.com/items?itemName=numaru.vscode-ceedling-test-adapter)