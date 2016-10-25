@echo off

echo Setting up a Qt environment...

set QMAKESPEC=win32-msvc2015
echo -- QMAKESPEC set to "win32-msvc2015"

set QTDIR=C:\Qt\Qt5.7.0\5.7\msvc2015
echo -- QTDIR set to %QTDIR%

set OPENCV_DIR=C:\Sources\opencv-3.1.0
echo -- OPENCV_DIR set to %OPENCV_DIR%

set VLC_DIR=C:\Sources\vlc-2.2.4
echo -- VLC_DIR set to %VLC_DIR%

set PATH=%QTDIR%\bin;%PATH%
echo -- Added %QTDIR%\bin to PATH

set VS_DIR="C:\Program Files (x86)\Microsoft Visual Studio 14.0"
call %VS_DIR%\VC\vcvarsall.bat x86

set CURRENT_TIME="%date:~0,4%-%date:~5,2%-%date:~8,2% %time:~0,2%.%time:~3,2%.%time:~6,2%"
echo --CURRENT_TIME set to %CURRENT_TIME%


rem mkdir build
rem cd build
rem mkdir %CURRENT_TIME%
rem cd %CURRENT_TIME%


rem set GIT_DIR="C:\Program Files\Git\bin"
rem %GIT_DIR%\git.exe clone git@github.com:suisiyuan/IDT_Capture.git -b qt
rem cd IDT_Capture
rem %QTDIR%\bin\qmake .\IDT_Capture.pro
rem nmake release /nologo

