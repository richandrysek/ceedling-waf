@REM Example of usage :
@REM     .\ceedling.cmd gcov:all utils:gcov
@REM
@REM  Parameters:
@REM     -c configfile  ceedling configuration file (default: .\conf\project.yml)
@REM     nargs          ceedling arguments (default: gcov:all utils:gcov)
@REM

@REM set python path
@set "PATH=%LOCALAPPDATA%\Programs\Python\Python312;%LOCALAPPDATA%\Programs\Python\Python312\Scripts;%PATH%;C:\Ruby30-x64\msys64\mingw64\bin"

@REM set default value(s)
set NARGS=gcov:all 
set CEEDLING_MAIN_PROJECT_FILE=.\project.yml

@REM Parse arguments
:parse
@IF "%~1"=="" GOTO endparse
IF "%~1"=="-p" (
    @set TARGET_BOARD=%2
    @SHIFT
) ELSE (
    IF "%~1"=="-c" (
        @set CEEDLING_MAIN_PROJECT_FILE=%2
        @SHIFT
    ) ELSE (
        @set "REST=%REST% %1"
    )
)
@SHIFT
@GOTO parse
:endparse

IF NOT "%REST%"=="" set NARGS=%REST%
echo "NARGS=%NARGS%"
echo "CEEDLING_MAIN_PROJECT_FILE=%CEEDLING_MAIN_PROJECT_FILE%"
:CallCeedling
C:\Ruby30-x64\bin\ceedling.bat %NARGS%
