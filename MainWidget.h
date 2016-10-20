#pragma once

#include <QDebug>
#include <QWidget>
#include <QSettings>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QMessageBox>
#include <QDateTime>
#include <QtEndian>

#include "vlc/libvlc.h"
#include "vlc/libvlc_media.h"
#include "vlc/libvlc_media_player.h"

#include "opencv2/opencv.hpp"

#include "ui_main.h"

#include "ConfigWidget.h"
#include "StitchWidget.h"

#include "app.h"
#include "network.h"
#include "UdpMsg.h"
#include "TcpSendMsg.h"
#include "TcpReceiveMsg.h"

using namespace cv;


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = Q_NULLPTR);


public slots:
    void startRecord();
    void stopRecord();

private:
	Ui::MainWidget ui;

	ConfigWidget *configWidget;
    StitchWidget *stitchWidget;

	QUdpSocket *udpHisi;
	QTcpSocket *tcpHisi, *tcpEncoder;
	QSettings *settings;
    QDir *currentDir;


    // 视频播放器相关
    libvlc_instance_t *inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;
	

    // 判断套接字状态
	bool isConnected(QAbstractSocket *);
	bool isDisconnected(QAbstractSocket *);




private slots:
	void on_connectButton_clicked();
	void on_disconnectButton_clicked();
	void on_startButton_clicked();
	void on_stopButton_clicked();
	void on_exitButton_clicked();
	

	void handleHisiUdpState(QAbstractSocket::SocketState);
	void handleHisiTcpState(QAbstractSocket::SocketState);
	void handleEncoderTcpState(QAbstractSocket::SocketState);

	void handleHisiUdpData();
	void handleHisiTcpData();
	void handleEncoderTcpData();

	void queryBattery();

    void takeSnapshot();

signals:
    void emitBattery(quint8);
    void emitHeight(qint32);

    // 视频相关
    void play();
    void stop();
    void snapshot(QDir);
    void record(QDir);
	void endRecord();
};
