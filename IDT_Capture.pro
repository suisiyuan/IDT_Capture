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
            CaptureWidget.cpp

HEADERS  += CaptureWidget.h \
    app.h \
    network.h

FORMS    += desktop.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/VLC-Qt_1.1.0_win32_msvc2015/lib/ -lVLCQtCore -lVLCQtWidgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/VLC-Qt_1.1.0_win32_msvc2015/lib/ -lVLCQtCored -lVLCQtWidgetsd

INCLUDEPATH += $$PWD/VLC-Qt_1.1.0_win32_msvc2015/include
DEPENDPATH += $$PWD/VLC-Qt_1.1.0_win32_msvc2015/include
