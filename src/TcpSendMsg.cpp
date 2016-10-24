#include "TcpSendMsg.h"

#include <QDebug>

TcpSendMsg::TcpSendMsg(TcpMsg::TCP_CMD type, QByteArray dataArray) :
    TcpMsg()
{
    length = dataArray.length();
    cmd = type;

    if (TcpMsg::LED == type)
        data = dataArray;
    else
        data = QByteArray();

    generateCrc();
}


TcpSendMsg::~TcpSendMsg()
{

}


QByteArray TcpSendMsg::getSentData()
{
    QByteArray allMsg = QByteArray((char *)&start, sizeof(start)) + QByteArray((char *)&length, sizeof(length)) +
                        QByteArray((char *)&cmd, sizeof(cmd)) + data + QByteArray((char *)crc, sizeof(crc));
    return allMsg;
}
