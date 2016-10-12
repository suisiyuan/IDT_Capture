#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T14:09:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IDT_Capture
TEMPLATE = app


SOURCES +=  main.cpp\
            CaptureWidget.cpp \
    TcpMsg.cpp \
    TcpSendMsg.cpp \
    TcpReceiveMsg.cpp

HEADERS  += CaptureWidget.h \
    app.h \
    network.h \
    TcpMsg.h \
    TcpSendMsg.h \
    TcpReceiveMsg.h \
    UdpMsg.h

FORMS    += desktop.ui

#vlc-qt win32 msvc2015
win32:INCLUDEPATH += ./3rd/VLC-Qt_1.1.0_win32_msvc2015/include
win32:CONFIG(release, debug|release): LIBS += -L./3rd/VLC-Qt_1.1.0_win32_msvc2015/lib/ -lVLCQtCore -lVLCQtWidgets
else:win32:CONFIG(debug, debug|release): LIBS += -L./3rd/VLC-Qt_1.1.0_win32_msvc2015/lib/ -lVLCQtCored -lVLCQtWidgetsd


#crc win32 msvc2015
win32:INCLUDEPATH += ./3rd/CRC16_win32_msvc2015/include
win32:CONFIG(release, debug|release): LIBS += -L./3rd/CRC16_win32_msvc2015/lib/ -lcrc
else:win32:CONFIG(debug, debug|release): LIBS += -L./3rd/CRC16_win32_msvc2015/lib/ -lcrcd


