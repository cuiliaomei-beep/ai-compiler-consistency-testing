# Pack plan/ for upload. Delegates to pack.py so zip entries use forward slashes
# (Windows PowerShell's Compress-Archive writes backslashes, which Kaggle rejects).
python (Join-Path $PSScriptRoot "pack.py")
