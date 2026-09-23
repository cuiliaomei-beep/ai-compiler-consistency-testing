# Build main.pdf into build/ (MiKTeX: pdflatex + bibtex). Usage:  powershell -File build.ps1
$ErrorActionPreference = "Continue"
$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$bin = "$env:LOCALAPPDATA\Programs\MiKTeX\miktex\bin\x64"
if (Test-Path $bin) { $env:PATH = "$bin;$env:PATH" }
Set-Location $root
New-Item -ItemType Directory -Force build | Out-Null
$args1 = @("-interaction=nonstopmode", "-halt-on-error", "-output-directory=build", "main.tex")
pdflatex @args1 | Out-Null
if ($LASTEXITCODE -ne 0) { Select-String -Path build\main.log -Pattern "^!" -Context 0,6 | Select-Object -First 5; exit 1 }
$env:BIBINPUTS = "$root;"; $env:BSTINPUTS = "$root;"
Push-Location build; bibtex main | Select-String "Warning|Error|error" | Select-Object -First 20; Pop-Location
pdflatex @args1 | Out-Null
pdflatex @args1 | Out-Null
Select-String -Path build\main.log -Pattern "Output written|undefined|Overfull \\hbox \((\d\d\d|[3-9]\d)" | Select-Object -First 25
