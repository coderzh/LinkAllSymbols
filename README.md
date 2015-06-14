When linking a static library against an executable, unreferenced symbols are normally discarded. Under Unix where we use gcc, we can pass the flag **--whole-archive** to the linker ld, which makes ld not discard any objects.

When under Windows Visual Studio, there is no equivalent to GNU ld option --whole-archive.  The linker option /OPT:NOREF also doesn't work.

There are two ways to force link specify symbols from static library。

* Linker Option use /INCLUDE xxx
* Add code : #pragma comment(linker, "/include:xxx")

Use #pragma is more flexible. So we can use **dumpbin** tool to list all symbols, then generate Header File use  #pragma comment(linker, "/inculde:xxx") to inlude all symbols.

*Make sure **dumpbin.exe** be executed in Developer Command Prompt*

Or write a batch command file, with the code(if installed Visual Studio 2013): 

```
@echo off
if defined VS120COMNTOOLS (
    call "%VS120COMNTOOLS%\vsvars32.bat")
```

The main **GenSymbolsHeader.py** execute dumpbin.exe, use regex expression to match all symbols, then generate Header File.

To automated generate LinkAllSymbols.h, in static library Post-Build Event, add this:

```
python ..\GenSymbolsHeader.py $(OutDir)$(TargetName)$(TargetExt) ..\Include\LinkAllSymbols.h
```

