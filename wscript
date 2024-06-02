import os

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
    opt.load('ceedling', tooldir=os.path.join('.', 'waf_tools'))
    opt.recurse(dirs = dirs)
 
def configure(cnf):
    print("configure")
    

    dirs = find_waf_projects(rootpath = "components")
    #cnf.setenv('gcc_oo')
    #cnf.env.CC = ['C:/Ruby30-x64/msys64/mingw64/bin/gcc.exe']
    cnf.load('compiler_c compiler_cxx')

    cnf.load('ceedling', tooldir=os.path.join('.', 'waf_tools'))
    cnf.recurse(dirs = dirs)

def build(bld):
    print("build!")
    dirs = find_waf_projects(rootpath = "components")
    #bld.load('ceedling', tooldir=os.path.join('.', 'waf_tools'))
    bld.recurse(dirs = dirs)

    bld(features="ceedling")