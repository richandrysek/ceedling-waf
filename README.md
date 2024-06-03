This demo shows how to use the ceedling together with a waf build framework.

# Installation

---
**NOTE**

The ceedling runs with Ruby 3.0, newer versions are not yet ported.

---

## Windows 11

```powershell
winget install RubyInstallerTeam.RubyWithDevKit.3.0
$env:Path +=';C:\Ruby30-x64\bin\'
$env:PATH +=';C:\Ruby30-x64\msys64\mingw64\bin'
gem install ceedling
```

# Usage

```powershell
python waf/waf configure --ceedling-project-file .\conf\project.yml
python waf/waf build ceedling
```