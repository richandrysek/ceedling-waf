## Slow start
### Introduction

Developer should verify a behavior and functionality of a written code. The smallest portion of a code - unit - can 
be tested isolated and independently from the rest of a code - unit test. To help with it to be faster a developer
can use some of available frameworks. In this project will be used a framework ceedling, which simplifies a whole
process from creating a unit test skeleton for a given c module till generating a report in several formats. 
To achieve that it uses:

- cmock - tool to generate mocks for a given header file
- gcc-toolchain - toolchain to build and run tests on a developer system
- gcovr - tool to generate a code coverage reports
- unity - library to simplify a writing of unit tests

All these tools are configured in one yaml file, in this case in a subfolder `./conf/project.yml`.

**NOTE** You may use this toolchain also on a goal target or for integration tests.

The gcc-toolchain expects a description how to build artifacts, like e.g. Makefile, CMakeLists.txt etc.
In this repository is used a Python based 'wscript' files. But it should be difficult to port to an another one.

### Project structure

The project is structured as described below:

```
+- /builds
|
+- /components
|     +---------/app
|     |           +------/src
|     |           |        +------main.c
|     |           +------wscript   
|     +---------/mcal
|                 +------/inc
|                 |        +------gpio.h
|                 |        +------led.h
|                 |        +------mcux_reg.h
|                 +------/src
|                 |        +------gpio.c
|                 |        +------led.c
|                 +------wscript
|
+- /conf
|     +---------/project.yml
| 
+- /doc
|     +---------/imgs
|     |           +------...
|    ...
|
+-/test
|     +---------/support
|     |           +------...
|     |
|     +---------help_mcu_reg.c
|     +---------test_gpio.c
|     +---------test_led.c
|
+-/waf
|     +---------....
|
+-/waf_tools
|     +---------ceedling.py
|     +---------__init__.py
|
+-CHANGELOG
+-LICENSE
+-README.md
+-SECURITY
+-SUPPORT
+-wsxript
```

#### build

Build artifacts, the ceedling artifcats are in the subdirectory ```ceedling``` .

#### MCAL

It consists of two components *app* and *mcal*. In the "app" is an application's main function. The mcal is
an microcontroller abstarction layer, in our case with GPIO and LED modules. These will be tested with 
a ceedling.

**NOTE** For testing on a host system were needed to modify the mcu_reg.h with this code part 
        '''#ifdef TEST''' , to emulate registers.

Each component has its own wscript file.

#### conf

The whole ceedling configuration can be found in the file ```conf/projects.yml``` .

#### doc

Additional documentation files can be found here

#### test

In the subdirectory ```support``` are help files automatically add by ceedling. The tests for the
led.c are in the file ```test_led.c```, similar for the gpio.c.

*** NOTE *** No wscript file is here.

#### waf

The waf build framework as a git submodule

#### waf_tools

Contains an extension ```ceedling.py``` to easy integrate calls for unit testing and test reports in wscripts.

#### top dir

The top directory contains common github project files (e.g. CHANGELOG) and the main wscript file. 
In this file is set a custom ceedling target using an extension from a subdirectory ```waf_tools```.

### Unit tests for the file gpio.c

The ```#ifdef TEST``` construct is used to exclude analyzing the code for non ceedling target,
followed by including an include file with the unit test API. On the line 5 is included a c module
under a test. The gpio.c calls internally mcu_reg.h macros to access registers. For this and several
other modules is used a shared file ```help_mcux_reg.c```. On the line 11-18 are functions called
before and after each test functions to initialize and clear some variables. On the line 20-38
is written a first test for a function ```GPIO_Config```. We call the function followed
by several TEST_ASSERTs, repeated to cover all branches in the tested function. Similar on the line
40-51 is done for the function ```GPIO_SetPin``` .

This module does not use other c modules. Such case is shown in the following chapter for the file ```led.c``` 

```
1 #ifdef TEST
2
3 #include "unity.h"
4
5 #include "gpio.h"
6 #include "mcux_reg.h"
7
8 #include "help_mcux_reg.c"
9
10
11 void setUp(void)
12 {
13    GPIO_Init();
14 }
15
16 void tearDown(void)
17 {
18 }
19
20 void test_gpio_config(void)
21 {
22    int32_t res;
23
24    res = GPIO_Config(GPIOA, GPIO_PIN0, GPIO_MODE_DO);
25
26    TEST_ASSERT(GPIOA->mode == 0x00u);
27    TEST_ASSERT(res == 0);
28
29    res = GPIO_Config(GPIOA, GPIO_PIN0, GPIO_MODE_DI);
30
31    TEST_ASSERT(GPIOA->mode == 0x01u);
32    TEST_ASSERT(res == 0);
33
34    res = GPIO_Config(NULL, GPIO_PIN0, GPIO_MODE_DI);
35    TEST_ASSERT(GPIOA->mode == 0x01u);
37    TEST_ASSERT(res == -1);
38 }
39
40 void test_gpio_set_pin(void)
41 {
42    int32_t res;
43
44    res = GPIO_SetPin(GPIOA, GPIO_PIN0, true);
45
46    TEST_ASSERT(GPIOA->state == 0x01u);
47    TEST_ASSERT(res == 0);
48
49    res = GPIO_SetPin(GPIOA, GPIO_PIN0, false);
50
51    TEST_ASSERT(GPIOA->state == 0x00u);
52    TEST_ASSERT(res == 0);
53
54    res = GPIO_SetPin(NULL, GPIO_PIN0, true);
55    TEST_ASSERT(GPIOA->state == 0x00u);
56    TEST_ASSERT(res == -1);
57 }
58
59 #endif // TEST
``` 

### Unit tests for the file led.c

The ```#ifdef TEST``` construct is used, as before, to exclude analyzing the code for 
non ceedling target, followed by including an include file with the unit test API.
On the line 5 is included a c module under a test. Again is reused a file with a
register emulation for a host target.

led.c uses internally the gpio.c API. This we want to isolate and test it in the file above.
To do so we need to create wrappers with an additional functionality for unit testing - mocks.
This is done on the line 7 "#include mock_gpio.h", the ceedling framework detects this line
and generate a mock automatically and integrates into the build scripts.

Internal GPIO_XXX calls are checked (line 23) or ignored (line 13) though a mocked functions.

```
1 #ifdef TEST
2 
3 #include "unity.h"
4 
5 #include "led.h" 
6 #include "mcux_reg.h"
7 #include "mock_gpio.h"
8
9 #include "help_mcux_reg.c"
10
11 void setUp(void)
12 {
13    GPIO_SetPin_IgnoreAndReturn(0);
14    LED_Init();
15 }
16
17 void tearDown(void)
18 {
19 }
20
21 void test_led_set(void)
22 {
23    GPIO_SetPin_ExpectAndReturn(GPIOA, GPIO_PIN2, true, 0);
24
25    int32_t res = LED_Set(LED_ID_ORANGE, true);
26
27    TEST_ASSERT(res == 0);
28
29    res = LED_Set((LED_Id)-5, true);
30
31    TEST_ASSERT(res == -1);
32 }
33
34 #endif // TEST
```

### Ceedling configuration ```conf/project.yml```

In this file are all settings for the ceedling. Here will be described the most important
parts, for the rest please see a ceedling documentation.


```
36 :paths:
37   :test:
38     - +:test/**
39     - -:test/support
40   :source:
41     - components/mcal/src/**
42   :include:
43     - components/mcal/inc/**
44   :support:
45     - test/support
46   :libraries: []
```

On the line 37-39 is configured where to find test files and support ceedling files, see the marks
'+' and '-', where minus means to ignore. On the line 40-43 where are source files to test 
and their include files. If some library is used, than it may be add on the line 46.

Following lines are needed to get gcov code coverage reports : 75-89 to configure the gcov
and 114 to include a gcov plugin. On the line 89 is configured which files shall be
excluded form a coverage report.

```
75 # Add -gcov to the plugins list to make sure of the gcov plugin
76 # You will need to have gcov and gcovr both installed to make it work.
77 # For more information on these options, see docs in plugins/gcov
78 :gcov:
79   :utilities:
80     - gcovr           # Use gcovr to create the specified reports (default).
81     #- ReportGenerator # Use ReportGenerator to create the specified reports.
82   :reports:
83     - HtmlDetailed
84   :gcovr:
85     #:report_include: "^../components/mcal/src.*"
86     :html_medium_threshold: 75
87     :html_high_threshold: 90
88     # Exclude source files that match this filter. (gcovr --exclude).
89     :report_exclude: "^vendor.*|^build.*|^test.*|^lib.*"
```

```
108 :plugins:
109   :load_paths:
110     - "#{Ceedling.load_path}"
111   :enabled:
112     #- stdout_pretty_tests_report
113     - module_generator
114     - gcov
```

### Main script file - setup for ceedling

Ceedling is a standalone command line tool. To make it more comfortable the main
```wscript``` has been extended to do not remember/type all options each time.

We setup a gcc for IA64 architecture on the line 37-40. In this part we load
also the plugin "ceedling" in the "WAF_TOOL_DIR". On the line 42-45 is set
a compiler for a target.

*** NOTE *** You can try to run a binary "helloworld.exe". In a real embedded project
             it will be a firmware for a given target.

On the line 57-59 is created a custom command "ceedling" and on the line 51-52 is add
plugin "ceedling" for this command. The command call and needed options are done
in the file ```./waf-tools/ceedling.py```.

```
34 def configure(cnf):
35    print("configure")
36    
37    # set ceedling tool chain
38    cnf.setenv('gcc_ia64')
39    cnf.load('compiler_c compiler_cxx')
40    cnf.load('ceedling', tooldir=WAF_TOOL_DIR)
41
42    # set default toolchain
43    cnf.setenv("")
44    cnf.load('compiler_c compiler_cxx')
45    cnf.env.append_value('CCFLAGS', '-std=c11 -Wall -pedantic')
46
47    recurse(cnf)
48
49
50 def build(bld):
51    if bld.cmd == 'ceedling':
52        bld(features="ceedling")
53    else:
54        recurse(bld)
55
56
57 class ceedling(BuildContext):
58    cmd = 'ceedling'
59    variant = "gcc_ia64"
```

### Summary

That's it no extra wscripts, no extra main.c for unit tests. All is done by ceedling tool.
How to use it is described in a quick start on the main page.