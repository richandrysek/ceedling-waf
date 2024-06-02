This demo shows how to use the ceedling togehter with a waf build framework.

# Usage

```powershell
$env:PATH +=';C:\Ruby30-x64\msys64\mingw64\bin'
python waf/waf configure --ceedling-project-file .\conf\project.yml
python waf/waf build
```