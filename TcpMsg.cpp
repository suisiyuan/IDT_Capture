#include "TcpMsg.h"
#include "crc.h"


TcpMsg::TcpMsg() :
    start(0x7E)
{

}


TcpMsg::~TcpMsg()
{

}



void TcpMsg::generateCrc()
{
    QByteArray crcMsg = QByteArray((char *)&cmd, sizeof(cmd)).append(data);
    *(quint16 *)crc = crcSlow((uchar *)crcMsg.data(), crcMsg.length());
}


bool TcpMsg::checkCrc()
{
    QByteArray crcMsg = QByteArray((char *)&cmd, sizeof(cmd)).append(data);
    return (*(quint16 *)crc == crcSlow((uchar *)crcMsg.data(), crcMsg.length()));
}



