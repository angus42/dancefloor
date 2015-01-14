ForEach ($file in Get-ChildItem -Filter "*.dfs")
{
    ..\SequencePalletizer\bin\Debug\SequencePalletizer.exe $file.name
} 
