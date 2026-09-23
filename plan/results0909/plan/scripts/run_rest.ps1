# Remaining experiment steps (RQ2, experiments A-E, metrics); RQ1/RQ3/RQ4 logs already final.
param([string]$Backend = "eager", [int]$SmallBudget = 12)
Set-Location (Split-Path $PSScriptRoot -Parent)
function Step($name, $cmd) {
    Write-Output "==== $name : $cmd"
    $t0 = Get-Date
    cmd /c "$cmd > results\$name.log 2>&1"
    Write-Output ("     done in {0:N0}s (exit {1})" -f ((Get-Date) - $t0).TotalSeconds, $LASTEXITCODE)
}
Step "rq2_baselines" "python -u run.py baselines --backend $Backend --budget $SmallBudget"
Step "experiments"   "python -u run.py experiments --backend $Backend --budget $SmallBudget"
Step "metrics"       "python -u run.py metrics"
Write-Output "==== rest finished"
