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
            MainWidget.cpp \
            ConfigWidget.cpp \
            StitchWidget.cpp \
            TcpMsg.cpp \
            TcpSendMsg.cpp \
            TcpReceiveMsg.cpp \
            OptionDialog.cpp \
            VideoOutput.cpp \
            crc16/crc.cpp

HEADERS  += MainWidget.h \
            ConfigWidget.h \
            StitchWidget.h \
            app.h \
            network.h \
            TcpMsg.h \
            TcpSendMsg.h \
            TcpReceiveMsg.h \
            UdpMsg.h \
            OptionDialog.h \
            VideoOutput.h \
            crc16/crc.h

FORMS    += main.ui \
            config.ui \
            stitch.ui \
            option.ui

win32 {
#opencv3
    INCLUDEPATH += $$(OPENCV3_DIR)/include
    CONFIG(release, debug|release): LIBS += -L$$(OPENCV3_DIR)/x86/vc14/lib -lopencv_core310 -lopencv_highgui310 -lopencv_imgcodecs310 -lopencv_imgproc310
    else:CONFIG(debug, debug|release): LIBS += -L$$(OPENCV3_DIR)/x86/vc14/lib -lopencv_core310d -lopencv_highgui310d -lopencv_imgcodecs310d -lopencv_imgproc310d

#vlc
    INCLUDEPATH += $$(VLC_DIR)/include
    LIBS += -L$$(VLC_DIR)/lib -llibvlc -llibvlccore
}



