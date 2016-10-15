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

set CURRENT_DATE=%date:~0,4%-%date:~5,2%-%date:~8,2%
echo --CURRENT_DATE set to %CURRENT_DATE%

mkdir build
cd build
mkdir %CURRENT_DATE%
cd %CURRENT_DATE%

mkdir src
mkdir release

cd src
set GIT_DIR="C:\Program Files\Git\bin"
%GIT_DIR%\git.exe clone git@github.com:suisiyuan/IDT_Capture.git -b qt
set SRC="%cd%\IDT_Capture"
echo --SRC set to %SRC%
cd ..

cd release
%QTDIR%\bin\qmake %SRC%\IDT_Capture.pro
nmake release /nologo
cd ..

