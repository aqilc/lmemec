@echo off

rem The libs we'll use
set libs=User32.lib Kernel32.lib Gdi32.lib

rem Compiles with MSVC
cl /MD /EHsc /std:c11 %libs% main.c .\utils\*.c /link /out:main.exe

rem Deletes the object files
del *.obj