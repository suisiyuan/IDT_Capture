#ifndef TCPMSG_H
#define TCPMSG_H

#include <QByteArray>



#define ACK_MASK (1 << 7)

class TcpMsg
{

public:
    TcpMsg();
    ~TcpMsg();

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


protected:
    quint8 start;
    quint8 length;
    quint8 cmd;
    QByteArray data;
    quint8 crc[2];

    void generateCrc();
    bool checkCrc();
};



#endif // TCPMSG_H
