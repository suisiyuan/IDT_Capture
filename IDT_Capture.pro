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



win32:CONFIG(release, debug|release): LIBS += -L$$(VLC_QT)/lib -lVLCQtCore -lVLCQtWidgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$(VLC_QT)/lib -lVLCQtCored -lVLCQtWidgetsd

INCLUDEPATH += $$(VLC_QT)/include
DEPENDPATH += $$(VLC_QT)/include
