<# 
.SYNOPSIS
    Simple PowerShell wrapper for Ceedling.
.EXAMPLE
    .\unit-test.ps1 gcov:all
.PARAMETER -c
    Specify a Ceedling configuration file (default: .\project.yml)
.PARAMETER nargs
    Ceedling arguments (default: )
#>

# Default values
$NARGS = ""
$CEEDLING_MAIN_PROJECT_FILE = ".\project.yml"
$rest = @()

# Parse arguments
for ($i = 0; $i -lt $args.Length; $i++) {
    switch ($args[$i]) {
        '-c' {
            if ($i + 1 -lt $args.Length) {
                $CEEDLING_MAIN_PROJECT_FILE = $args[$i + 1]
                $i++
            }
        }
        default {
            $rest += $args[$i]
        }
    }
}

if ($rest.Count -gt 0) {
    $NARGS = $rest -join " "
}

Write-Host "NARGS=$NARGS"
Write-Host "CEEDLING_MAIN_PROJECT_FILE=$CEEDLING_MAIN_PROJECT_FILE"

# If you want the config file passed as an env variable, uncomment next line:
# $env:CEEDLING_MAIN_PROJECT_FILE = $CEEDLING_MAIN_PROJECT_FILE

# Call ceedling
& 'ceedling.bat' $NARGS