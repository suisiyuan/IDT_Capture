#ifndef NETWORK_H
#define NETWORK_H

// Hisi
#define HISI_IP				settings->value(HISI_IP_REG).toString()
#define HISI_TCP_PORT		settings->value(HISI_TCP_REG).toInt()
#define HISI_UDP_PORT		settings->value(HISI_UDP_REG).toInt()
#define HISI_VIDEO_PORT		settings->value(HISI_VIDEO_REG).toInt()
#define HISI_VIDEO_NAME     settings->value(HISI_VIDEO_NAME_REG).toString()
#define HISI_VIDEO_URL		QString("rtsp://") + HISI_IP + ":" + QString::number(HISI_VIDEO_PORT) + "/" + HISI_VIDEO_NAME

// Encoder
#define ENCODER_IP			settings->value(ENCODER_IP_REG).toString()
#define ENCODER_TCP_PORT	settings->value(ENCODER_TCP_REG).toInt()


#define WAITING_TIME		1000


#endif // NETWORK_H
