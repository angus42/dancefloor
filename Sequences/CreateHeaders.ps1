ForEach ($file in Get-ChildItem -Filter "*.dfs")
{
    ..\SequencePalletizer\bin\Debug\SequencePalletizer.exe $file.name
}
Move-Item -Path ".\*.h" -Destination ".." -Force

Write-Host "Done - press any key"
$HOST.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown") | OUT-NULL
$HOST.UI.RawUI.Flushinputbuffer()