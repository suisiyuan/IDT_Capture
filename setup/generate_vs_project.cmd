@echo off

echo Setting up a Qt environment...

set QMAKESPEC=win32-msvc2015
echo -- QMAKESPEC set to "win32-msvc2015"

set QTDIR=C:\Qt\Qt5.7.7\5.7\msvc2015
echo -- QTDIR set to %QTDIR%

set OPENCV3_DIR=C:\Sources\opencv-3.1.0
echo -- OPENCV3_DIR set to %OPENCV3_DIR%

set VLC_DIR=C:\Sources\vlc-2.2.4
echo -- VLC_DIR set to %VLC_DIR%

set PATH=%QTDIR%\bin;%VLC_DIR%\x86\bin;%OPENCV3_DIR%\x86\vc14\bin;%PATH%
echo -- Added %QTDIR%\bin;%VLC_DIR%\bin;%OPENCV3_DIR%\bin to PATH

set VS_DIR="C:\Program Files (x86)\Microsoft Visual Studio 14.0"
call %VS_DIR%\VC\vcvarsall.bat x86

echo --generate IDT VS project
cd ..
qmake -t vcapp