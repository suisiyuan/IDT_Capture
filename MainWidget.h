#pragma once

#include <QDebug>
#include <QTimer>
#include <QWidget>
#include <QSettings>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QMessageBox>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

#include "ui_main.h"

#include "ConfigWidget.h"
#include "StitchWidget.h"

#include "app.h"
#include "network.h"
#include "UdpMsg.h"
#include "TcpSendMsg.h"
#include "TcpReceiveMsg.h"




class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWidget ui;

	ConfigWidget *configWidget;
	StitchWidget *stitchWidget;


	QUdpSocket *udpHisi;
	QTcpSocket *tcpHisi, *tcpEncoder;
	QSettings *settings;
	QTimer *queryTimer;

	VlcInstance *_instance;
	VlcMedia *_media;
	VlcMediaPlayer *_player;
	

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

};