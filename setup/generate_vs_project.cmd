@echo off

echo Setting up a Qt environment...

set QMAKESPEC=win32-msvc2015
echo -- QMAKESPEC set to "win32-msvc2015"

set QTDIR=C:\Qt\Qt5.6.2\5.6\msvc2015
echo -- QTDIR set to %QTDIR%

set VLC_DIR=C:\libvlc
echo -- VLC_DIR set to %VLC_DIR%

set OPENCV3_DIR=C:\opencv3
echo -- OPENCV3_DIR set to %OPENCV3_DIR%

set PATH=%QTDIR%\bin;%VLC_DIR%\bin;%OPENCV3_DIR%\x86\vc14\bin;%PATH%
echo -- Added %QTDIR%\bin;%VLC_DIR%\bin;%OPENCV3_DIR%\bin to PATH

set VS_DIR="C:\Program Files (x86)\Microsoft Visual Studio 14.0"
call %VS_DIR%\VC\vcvarsall.bat x86

echo --generate DCTA VS project
cd ..
qmake -t vcapp