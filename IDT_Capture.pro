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
            OptionDialog.cpp

HEADERS  += MainWidget.h \
            ConfigWidget.h \
            StitchWidget.h \
            app.h \
            network.h \
            TcpMsg.h \
            TcpSendMsg.h \
            TcpReceiveMsg.h \
            UdpMsg.h \
            OptionDialog.h

FORMS    += main.ui \
            config.ui \
            stitch.ui \
            option.ui


win32 {
#vlc-qt
    INCLUDEPATH += ./3rd/vlc-qt/include
    CONFIG(release, debug|release): LIBS += -L./3rd/vlc-qt/lib/ -lVLCQtCore -lVLCQtWidgets -llibvlc -llibvlccore
    else:CONFIG(debug, debug|release): LIBS += -L./3rd/vlc-qt/lib/ -lVLCQtCored -lVLCQtWidgetsd -llibvlc -llibvlccore

#crc16
    INCLUDEPATH += ./3rd/crc16/include
    CONFIG(release, debug|release): LIBS += -L./3rd/crc16/lib/ -lcrc
    else:CONFIG(debug, debug|release): LIBS += -L./3rd/crc16/lib/ -lcrcd

#opencv3
    INCLUDEPATH += $$(OPENCV3_DIR)/include \
                   $$(OPENCV3_DIR)/include/opencv \
                   $$(OPENCV3_DIR)/include/opencv2
    CONFIG(release, debug|release): LIBS += -L$$(OPENCV3_DIR)/x86/vc14/lib/ -lopencv_core310 -lopencv_highgui310 -lopencv_imgcodecs310
    else:CONFIG(debug, debug|release): LIBS += -L$$(OPENCV3_DIR)/x86/vc14/lib/ -lopencv_core310d -lopencv_highgui310d -lopencv_imgcodecs310d
}



