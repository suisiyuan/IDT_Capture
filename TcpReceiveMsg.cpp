#include "TcpReceiveMsg.h"


TcpReceiveMsg::TcpReceiveMsg(QByteArray packet) :
    TcpMsg(),
    validation(false)
{
    start = (quint8)packet.at(0);
    length = (quint8)packet.at(1);
    cmd = (quint8)packet.at(2);
    data = packet.mid(3, length);
    crc[0] = packet.right(2).data()[0];
    crc[1] = packet.right(2).data()[1];
    if (0x7E == start && checkCrc())
    {
        validation = true;
    }
    else
    {
        validation = false;
        data = QByteArray();
    }

}


TcpReceiveMsg::~TcpReceiveMsg()
{

}




QByteArray TcpReceiveMsg::getReceivedData()
{
    return data;
}



TcpMsg::TCP_CMD TcpReceiveMsg::type()
{
    return (TcpMsg::TCP_CMD)cmd;
}


bool TcpReceiveMsg::isValid()
{
    return validation;
}

