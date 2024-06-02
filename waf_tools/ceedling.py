#!/usr/bin/env python
# encoding: utf-8
# Richard Andrysek, 2024
# RENU Eletronics 2024 Copyright

"""
The **ceedling** program is a unit test framework for C or C++ files.
The generated files are in the build directory.
"""

import os
import platform
from waflib import Task, TaskGen


class ceedling(Task.Task):
    """Run ceedling unit test framework"""
    color   = 'GREEN'
    always_run = True
    if platform.system().lower().startswith('win'):
        run_str = 'cmd.exe /c "set CEEDLING_MAIN_PROJECT_FILE=${CEEDLING_MAIN_PROJECT_FILE} && ${CEEDLING} ${CEEDLING_OPTIONS}"'
    else:
        run_str = 'CEEDLING_MAIN_PROJECT_FILE=${CEEDLING_MAIN_PROJECT_FILE} ${CEEDLING} ${CEEDLING_OPTIONS}'


@TaskGen.feature("ceedling")
def add_ceedling_task(self):
    self.create_task("ceedling", cwd=self.path)


def options(opt):
    """Passing options to ceedling"""
    opt.add_option(
        "--ceedling-project-file",
        default="project.yml",
        dest="CEEDLING_MAIN_PROJECT_FILE",
        help="Project file for ceedling")
    opt.add_option(
        "--ceedling-options",
        default=["test:all"],
        action="append",
        dest="CEEDLING_OPTIONS",
        help="Options for ceedling")


def configure(conf):
    """Detect ceedling, related programs and set configuration variables"""

    required_programs = ["ruby", "gcc", "ceedling"]
    for required_program in required_programs: 
        conf.find_program(required_program, mandatory=True)

    conf.env.CEEDLING_MAIN_PROJECT_FILE = os.path.abspath(conf.options.CEEDLING_MAIN_PROJECT_FILE)
    conf.env.CEEDLING_OPTIONS = conf.options.CEEDLING_OPTIONS
