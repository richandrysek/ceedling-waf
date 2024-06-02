import os

# C:\Ruby30-x64\msys64\mingw64\bin

def find_waf_projects(rootpath = "."):
    found_dirs = []
    for root, dirs, files in os.walk(rootpath):
        for filename in files:
            if "wscript" == filename:
                #print('Found', root, filename)
                found_dirs.append(root)
    return found_dirs

def options(opt):
    dirs = find_waf_projects(rootpath = "components")
    opt.load("compiler_c compiler_cxx")
    opt.recurse(dirs = dirs)

def configure(cnf):
    print("configure")
    

    dirs = find_waf_projects(rootpath = "components")
    #cnf.setenv('gcc_oo')
    #cnf.env.CC = ['C:/Ruby30-x64/msys64/mingw64/bin/gcc.exe']
    cnf.load('compiler_c compiler_cxx')
    cnf.recurse(dirs = dirs)

def build(bld):
    print("build!")
    dirs = find_waf_projects(rootpath = "components")
    bld.recurse(dirs = dirs)