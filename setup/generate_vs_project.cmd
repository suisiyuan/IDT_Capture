@echo off

echo Setting up a Qt environment...

set QMAKESPEC=win32-msvc2015
echo -- QMAKESPEC set to "win32-msvc2015"

set QTDIR=C:\Qt\Qt5.6.2\5.6\msvc2015
echo -- QTDIR set to %QTDIR%

set PATH=%QTDIR%\bin;%PATH%
echo -- Added %QTDIR%\bin to PATH

set VS_DIR="C:\Program Files (x86)\Microsoft Visual Studio 14.0"
call %VS_DIR%\VC\vcvarsall.bat x86

echo --generate DCTA VS project
cd ..
qmake -t vcapp