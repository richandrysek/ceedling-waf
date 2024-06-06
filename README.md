# ceedling-waf

[![CI](https://github.com/richandrysek/ceedling-waf/actions/workflows/build.yml/badge.svg)](https://github.com/richandrysek/ceedling-waf/actions/workflows/build.yml)

[andrysek](https://andrysek.de/)

This demo shows how to use the ceedling together with a waf build framework.

## System requirements

|SW Component                                                                                                   |Version                |
|---------------------------------------------------------------------------------------------------------------|-----------------------|
|[Ruby](https://developer.hashicorp.com/packer/install?product_intent=packer)                                   | ruby 3.0.4p208        |
|[Ceedling](https://developer.hashicorp.com/vagrant/install?product_intent=vagrant)                             | 0.31.1                |
|[Python3](https://developer.hashicorp.com/vagrant/docs/providers/vmware/vagrant-vmware-utility)                | 3.12.3                |

## Quick start

### Get project

```powershell
git clone https://github.com/richandrysek/ceedling-waf
git submodule update --init --recursive
cd waf
python ./waf-light configure build
```

### Build and run unit tests

```powershell
python waf/waf configure --ceedling-project-file .\conf\project.yml
python waf/waf build ceedling
```

## Installation

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
