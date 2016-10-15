@echo off

echo Setting up a Qt environment...

set QMAKESPEC=win32-msvc2015
echo -- QMAKESPEC set to "win32-msvc2015"

set QTDIR=C:\Qt\Qt5.7.0\5.7\msvc2015
echo -- QTDIR set to %QTDIR%

set PATH=%QTDIR%\bin;%PATH%
echo -- Added %QTDIR%\bin to PATH

set VS_DIR="C:\Program Files (x86)\Microsoft Visual Studio 14.0"
call %VS_DIR%\VC\vcvarsall.bat x86

set CURRENT_TIME="%date:~0,4%-%date:~5,2%-%date:~8,2% %time:~0,2%.%time:~3,2%.%time:~6,2%"
echo --CURRENT_TIME set to %CURRENT_TIME%

mkdir build
cd build
mkdir %CURRENT_TIME%
cd %CURRENT_TIME%


set GIT_DIR="C:\Program Files\Git\bin"
%GIT_DIR%\git.exe clone git@github.com:suisiyuan/IDT_Capture.git -b qt
cd IDT_Capture
%QTDIR%\bin\qmake .\IDT_Capture.pro
nmake release /nologo
