#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) : 
	QWidget(parent),
    configWidget(new ConfigWidget(this)),
	stitchWidget(Q_NULLPTR),
	udpHisi(new QUdpSocket()),
	tcpHisi(new QTcpSocket()),
	tcpEncoder(new QTcpSocket()),
	settings(new QSettings()),
    queryTimer(new QTimer()),
    currentDir(Q_NULLPTR),
    recordMedia(Q_NULLPTR)
{
	ui.setupUi(this);
	
    // 配置界面
    ui.mainLayout->addWidget(configWidget, 1, 2);
    configWidget->hide();

	// 注册变量
	qRegisterMetaType<QAbstractSocket::SocketState>();

	// 信号与槽
	QObject::connect(udpHisi, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(handleHisiUdpState(QAbstractSocket::SocketState)));
	QObject::connect(tcpHisi, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(handleHisiTcpState(QAbstractSocket::SocketState)));
	QObject::connect(tcpEncoder, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(handleEncoderTcpState(QAbstractSocket::SocketState)));

	QObject::connect(udpHisi, SIGNAL(readyRead()), this, SLOT(handleHisiUdpData()));
	QObject::connect(tcpHisi, SIGNAL(readyRead()), this, SLOT(handleHisiTcpData()));
	QObject::connect(tcpEncoder, SIGNAL(readyRead()), this, SLOT(handleEncoderTcpData()));

	QObject::connect(queryTimer, SIGNAL(timeout()), this, SLOT(queryBattery()));



	// 视频播放器
	_instance = new VlcInstance(VlcCommon::args(), this);
	_media = new VlcMedia(HISI_VIDEO_URL, _instance);
    recordMedia = new VlcMedia(HISI_VIDEO_URL, _instance);
	_player = new VlcMediaPlayer(_instance);
	_player->setVideoWidget(ui.video);
	ui.video->setMediaPlayer(_player);

    QObject::connect(_player, SIGNAL(snapshotTaken(QString)), this, SIGNAL(snapshotTaken(QString)));
}


// 判断套接字是否已连接
bool MainWidget::isConnected(QAbstractSocket *socket)
{
	return (QAbstractSocket::ConnectedState == socket->state());
}

// 判断套接字是否未连接
bool MainWidget::isDisconnected(QAbstractSocket *socket)
{
	return (QAbstractSocket::UnconnectedState == socket->state());
}



// 连接
void MainWidget::on_connectButton_clicked()
{
	tcpHisi->connectToHost(HISI_IP, HISI_TCP_PORT, QIODevice::ReadWrite, QAbstractSocket::IPv4Protocol);
	tcpEncoder->connectToHost(ENCODER_IP, ENCODER_TCP_PORT, QIODevice::ReadWrite, QAbstractSocket::IPv4Protocol);

	if (tcpHisi->waitForConnected(WAITING_TIME) && tcpEncoder->waitForConnected(WAITING_TIME))
	{
		udpHisi->bind(QHostAddress::AnyIPv4, HISI_UDP_PORT);
		
		_player->open(_media);
		

		ui.connectButton->setEnabled(false);
		ui.disconnectButton->setEnabled(true);
		ui.startButton->setEnabled(true);

        configWidget->show();

		queryTimer->start(QUERY_INTERVAL);
		queryBattery();

        qDebug() << "track:" << _player->video()->trackCount();

	}
	else
	{
		if (!isConnected(tcpHisi))
		{
			tcpHisi->close();
			QMessageBox::critical(this, tr("Connection failed"), tr("Cannot connect to Hisi board!"));
		}
		else
		{
			tcpHisi->close();
			tcpEncoder->close();
			QMessageBox::critical(this, tr("Connection failed"), tr("Connot connect to Encoder!"));
		}
	}
}

// 断开连接
void MainWidget::on_disconnectButton_clicked()
{
	tcpHisi->close();
	tcpEncoder->close();
	udpHisi->close();
	_player->stop();

	isDisconnected(tcpHisi) || tcpHisi->waitForDisconnected(WAITING_TIME);
	isDisconnected(tcpEncoder) || tcpEncoder->waitForDisconnected(WAITING_TIME);

	ui.connectButton->setEnabled(true);
	ui.disconnectButton->setEnabled(false);
	ui.startButton->setEnabled(false);
	ui.stopButton->setEnabled(false);

    configWidget->hide();
		
    if (stitchWidget != Q_NULLPTR) {
        delete stitchWidget;
        stitchWidget = Q_NULLPTR;
    }
		

	queryTimer->stop();
}

// 开始
void MainWidget::on_startButton_clicked()
{
	TcpSendMsg startMsg(TcpMsg::START);
	tcpEncoder->write(startMsg.getSentData().data(), startMsg.getSentData().length());  

    // 设置控制按钮
	ui.startButton->setEnabled(false);
	ui.stopButton->setEnabled(true);
    ui.disconnectButton->setEnabled(false);

    // 切换界面
    configWidget->hide();
    stitchWidget = new StitchWidget(this);
    ui.mainLayout->addWidget(stitchWidget, 1, 2);

    // 创建工程文件夹
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss");
    QDir dir(configWidget->savePath);
    dir.mkdir(currentTime);
    currentDir = new QDir(dir.filePath(currentTime));
}

// 停止
void MainWidget::on_stopButton_clicked()
{
	TcpSendMsg stopMsg(TcpMsg::STOP);
	tcpEncoder->write(stopMsg.getSentData().data(), stopMsg.getSentData().length());

	ui.startButton->setEnabled(true);
	ui.stopButton->setEnabled(false);
    ui.disconnectButton->setEnabled(true);
	
    if (stitchWidget != Q_NULLPTR) {
        delete stitchWidget;
        stitchWidget = Q_NULLPTR;
    }

    configWidget->show();

    // 销毁工程文件夹指针
    if (currentDir != Q_NULLPTR)
    {
        delete currentDir;
        currentDir = Q_NULLPTR;
    }
}


// 退出
void MainWidget::on_exitButton_clicked()
{
	this->close();
}



void MainWidget::handleHisiUdpState(QAbstractSocket::SocketState state)
{
	switch (state)
	{
	case QAbstractSocket::ConnectedState:
		break;
	case QAbstractSocket::UnconnectedState:
		break;
	default:
		break;
	}
}

void MainWidget::handleHisiTcpState(QAbstractSocket::SocketState state)
{
	switch (state)
	{
	case QAbstractSocket::ConnectedState:
		break;
	case QAbstractSocket::UnconnectedState:
		break;
	default:
		break;
	}
}

void MainWidget::handleEncoderTcpState(QAbstractSocket::SocketState state)
{
	switch (state)
	{
	case QAbstractSocket::ConnectedState:
		break;
	case QAbstractSocket::UnconnectedState:
		break;
	default:
		break;
	}
}


// 接收来自Hisi板的UDP数据
void MainWidget::handleHisiUdpData()
{
	while (udpHisi->hasPendingDatagrams())
	{
		QHostAddress sender;
		quint16 senderPort;
		UDP_DATA data = {0, { 0 }, 0.0, 0.0, 0.0};

		udpHisi->readDatagram((char *)&data, sizeof(data), &sender, &senderPort);

		switch (data.cmd)
		{
			case COMPASS:
			{
				//qDebug() << "Compass data:" << data.yam << data.pitch << data.roll;
				break;
			}	
			default:
				break;
		}
	}
}


// 接收到来自Hisi板的TCP数据
void MainWidget::handleHisiTcpData()
{
	QByteArray data = tcpHisi->readAll();
	TcpReceiveMsg msg(data);
	//    switch(msg.type())
	//    {
	//        default:
	//            break;
	//    }
}



// 接收到来自编码器的TCP数据
void MainWidget::handleEncoderTcpData()
{
	QByteArray data = tcpEncoder->readAll();
	TcpReceiveMsg msg(data);
	switch (msg.type())
	{
		case TcpMsg::START_ACK:
			qDebug() << "start ack";
			break;
		case TcpMsg::STOP_ACK:
			qDebug() << "stop ack";
			break;
		case TcpMsg::HEIGHT:
		{
            qint32 height = qFromBigEndian<qint32>((uchar *)msg.getReceivedData().data());
			//qDebug() << "Height" << height;
            emit emitHeight(height);
			break;
		}
			
		case TcpMsg::BATTERY_RSP:
		{
			quint8 battery = *msg.getReceivedData().data();
            emit emitBattery(battery);
            break;
		}

		default:
			break;
	}
}


// 查询电量
void MainWidget::queryBattery()
{
	TcpSendMsg queryMsg(TcpMsg::BATTERY);
	tcpEncoder->write(queryMsg.getSentData().data(), queryMsg.getSentData().length());
}


// 开始录制视频
void MainWidget::startRecord()
{
    qDebug() << "start record";
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss");
    recordMedia->record(currentTime, currentDir->path(), Vlc::Mux::MP4, true);
    _player->open(recordMedia);
}


// 停止录制视频
void MainWidget::stopRecord()
{
    qDebug() << "stop record";
    _player->open(_media);
}


// 截图
void MainWidget::takeSnapshot()
{
    _player->video()->takeSnapshot(currentDir->filePath(QDateTime::currentDateTime().toString("截图_yyyy-MM-dd_HH.mm.ss.png")));
}

