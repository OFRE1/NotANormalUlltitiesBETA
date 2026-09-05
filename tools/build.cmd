@echo off
echo Highly recommend to execute this in source code directory. By do it, in Windows 11 right click and
echo click Open in Terminal, then type cmd, execute tools\build.cmd. If you are using Windows 10, open a 
echo cmd and type 'cd /d C:\path\to\NANM\source' no single quote then type tools\build.cmd
pause
echo Starting ...
timeout /t 5 /nobreak > nul

cls

echo Make binaries output folder
rmdir binaries
mkdir binaries
echo Building ...
call c++ main/EXAMPLEMAIN.cpp module/download/download.cpp module/system/systeminfo.cpp -o binaries\NANM.exe -ladvapi32

if %errorlevel% equ 0 (
    :: In successfully case
    cmd /c "echo [92m===================================================[0m"
    cmd /c "echo [92m   [SUCCESS] Done! NANM.exe is ready to use ^^  	[0m"
    cmd /c "echo [92m===================================================[0m"
) else (
    :: In error case
    cmd /c "echo [91m===================================================[0m"
    cmd /c "echo [91m   [ERROR] Fail to compile                         [0m"
    cmd /c "echo [91m===================================================[0m"
)

pause
exit