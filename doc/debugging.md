## Debugging
### Introduction

If some test failed/not failed and you do not know exactly why, than the debugging should help.

### Installation

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

### Run all tests

1. Open Visual Code IDE with the directory "ceedling-waf"
2. In Menu click on "View->Command Pallete"
3. Type "Run all tests"

### References

[how to install gdb from superuser.com](https://superuser.com/questions/1747118/how-to-download-gdb-from-mingw-correctly)

[Howto debug Ceedling Unit-Tests from medtech-ingenieur.de](https://medtech-ingenieur.de/howto-debug-ceedling-unit-tests/)

[Visual code settings](https://gist.github.com/bd2357/b2d69ab18849c1e2f70959eef426ff09)

[Visual code ceedling test adapter](https://marketplace.visualstudio.com/items?itemName=numaru.vscode-ceedling-test-adapter)