# Runs every experiment of the plan in order and logs each to results/.
# Usage:  powershell -File scripts\run_experiments.ps1 [-Backend eager] [-Budget 16]
param(
    [string]$Backend = "eager",
    [int]$Budget = 16,
    [int]$SmallBudget = 12
)
$ErrorActionPreference = "Continue"
Set-Location (Split-Path $PSScriptRoot -Parent)
New-Item -ItemType Directory -Force results | Out-Null

function Step($name, $cmd) {
    Write-Output "==== $name : $cmd"
    $t0 = Get-Date
    cmd /c "$cmd > results\$name.log 2>&1"
    $dt = ((Get-Date) - $t0).TotalSeconds
    Write-Output ("     done in {0:N0}s (exit {1})" -f $dt, $LASTEXITCODE)
}

Step "rq1_bench"     "python -u run.py bench --backend $Backend --budget $Budget"
Step "rq3_ablation"  "python -u run.py ablate --backend $Backend --budget $SmallBudget"
Step "rq4_cache"     "python -u run.py cache --backend $Backend --budget $SmallBudget"
Step "rq2_baselines" "python -u run.py baselines --backend $Backend --budget $SmallBudget"
Step "experiments"   "python -u run.py experiments --backend $Backend --budget $SmallBudget"
Step "metrics"       "python -u run.py metrics"
Write-Output "==== all experiments finished"
