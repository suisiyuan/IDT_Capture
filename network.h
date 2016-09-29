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


#define ACK_MASK (1 << 7)


enum TCP_CMD {
    START = 0x01,
    STOP,
    LED,
    FOCUS,
    HEIGHT,
    BATTERY,
    ALARM,
    UPDATE_FIRMWARE,
    UPDATE_FILE_LENGTH,
    UPDATE_FILE_DATA,

    START_ACK = START | ACK_MASK,
    STOP_ACK = STOP | ACK_MASK,
    BATTERY_RSP = BATTERY | ACK_MASK,
    UPDATE_FIRMWARE_ACK = UPDATE_FIRMWARE | ACK_MASK,
    UPDATE_FILE_LENGTH_ACK = UPDATE_FILE_LENGTH | ACK_MASK,
    UPDATE_FILE_DATA_ACK = UPDATE_FILE_DATA | ACK_MASK
};


enum UDP_CMD {
    COMPASS = 1,
};



typedef struct
{
    quint8 cmd;
    quint8 resv[3];
    float yam;
    float pitch;
    float roll;
}UDP_DATA;



// tcp package class
class TcpMsg {

enum PackgeType {
    START_CMD = 0x01,
    STOP_CMD,
    LED_CMD,
    FOCUS_CMD,
    HEIGHT_DATA,
    BATTERY_CMD,
    BATTERY_DATA
};

public:
    explicit TcpMsg()
    {

    }

    ~TcpMsg()
    {

    }


private:
    quint8 length;
    quint8 cmd;
    quint8 crc[2];
};

#endif // NETWORK_H
