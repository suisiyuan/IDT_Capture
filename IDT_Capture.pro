#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T14:09:04
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IDT_Capture
TEMPLATE = app

INCLUDEPATH += src

SOURCES +=  src/main.cpp\
            src/MainWidget.cpp \
            src/ConfigWidget.cpp \
            src/StitchWidget.cpp \
            src/TcpMsg.cpp \
            src/TcpSendMsg.cpp \
            src/TcpReceiveMsg.cpp \
            src/OptionDialog.cpp \
            src/VideoOutput.cpp \
            src/crc.cpp \
            src/DataHandler.cpp \
            src/imageProc.cpp


HEADERS  += src/MainWidget.h \
            src/ConfigWidget.h \
            src/StitchWidget.h \
            src/app.h \
            src/network.h \
            src/config.h \
            src/TcpMsg.h \
            src/TcpSendMsg.h \
            src/TcpReceiveMsg.h \
            src/UdpMsg.h \
            src/OptionDialog.h \
            src/VideoOutput.h \
            src/crc.h \
            src/DataHandler.h \
            src/imageProc.h


FORMS    += ui/main.ui \
            ui/config.ui \
            ui/stitch.ui \
            ui/option.ui

win32 {
#opencv3
    INCLUDEPATH += $$(OPENCV3_DIR)/include
    CONFIG(release, debug|release): LIBS += -L$$(OPENCV3_DIR)/x86/vc14/lib -lopencv_core310 -lopencv_highgui310 -lopencv_imgcodecs310 -lopencv_imgproc310 -lopencv_stitching310
    else:CONFIG(debug, debug|release): LIBS += -L$$(OPENCV3_DIR)/x86/vc14/lib -lopencv_core310d -lopencv_highgui310d -lopencv_imgcodecs310d -lopencv_imgproc310d -lopencv_stitching310d

#vlc
    INCLUDEPATH += $$(VLC_DIR)/include
    LIBS += -L$$(VLC_DIR)/x86/lib -llibvlc -llibvlccore
}

RESOURCES += res.qrc
RC_FILE = res.rc

