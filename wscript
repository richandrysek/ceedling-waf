#!/usr/bin/env python

__author__      = "Richard Andrysek"
__copyright__   = "Copyright 2024, Renu Electronics GmbH"

import os
from waflib.Build import BuildContext


WAF_TOOL_DIR = os.path.join('.', 'waf_tools')


def find_waf_projects(rootpath = "."):
    found_dirs = []
    for root, dirs, files in os.walk(rootpath):
        for filename in files:
            if "wscript" == filename:
                #print('Found', root, filename)
                found_dirs.append(root)
    return found_dirs


def recurse(ctx):
    dirs = find_waf_projects(rootpath = "components")
    return ctx.recurse(dirs = dirs)


def options(opt):
    opt.load("compiler_c compiler_cxx")
    opt.load('ceedling', tooldir=WAF_TOOL_DIR)
    recurse(opt)


def configure(cnf):
    print("configure")
    #cnf.setenv('gcc_oo')
    cnf.load('compiler_c compiler_cxx')
    cnf.load('ceedling', tooldir=WAF_TOOL_DIR)
    recurse(cnf)


def build(bld):
    if bld.cmd == 'ceedling':
        bld(features="ceedling")
    else:
        recurse(bld)


class ceedling(BuildContext):
	cmd = 'ceedling'