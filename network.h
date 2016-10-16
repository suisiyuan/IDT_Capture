#ifndef NETWORK_H
#define NETWORK_H

//// Hisi
//#define HISI_IP				settings->value(HISI_IP_REG).toString()
//#define HISI_TCP_PORT		settings->value(HISI_TCP_REG).toInt()
//#define HISI_UDP_PORT		settings->value(HISI_UDP_REG).toInt()
//#define HISI_VIDEO_PORT		settings->value(HISI_VIDEO_REG).toInt()
//#define HISI_VIDEO_NAME     settings->value(HISI_VIDEO_NAME_REG).toString()
//#define HISI_VIDEO_URL		QString("rtsp://") + HISI_IP + ":" + QString::number(HISI_VIDEO_PORT) + "/" + HISI_VIDEO_NAME
//
//// Encoder
//#define ENCODER_IP			settings->value(ENCODER_IP_REG).toString()
//#define ENCODER_TCP_PORT	settings->value(ENCODER_TCP_REG).toInt()


// Hisi
#define HISI_IP				"192.168.1.10"
#define HISI_TCP_PORT		20108
#define HISI_UDP_PORT		8888
#define HISI_VIDEO_URL		"rtsp://192.168.1.10:6880/test.264"

// Encoder
#define ENCODER_IP			"192.168.1.7"
#define ENCODER_TCP_PORT	20108


// Waiting time
#define WAITING_TIME		1000

// battery query interval
#define QUERY_INTERVAL    10000


#endif // NETWORK_H
