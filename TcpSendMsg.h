#ifndef TCPSENDMSG_H
#define TCPSENDMSG_H

#include "TcpMsg.h"

class TcpSendMsg : public TcpMsg
{
public:
    TcpSendMsg(TcpMsg::TCP_CMD type, QByteArray dataArray = QByteArray());
    ~TcpSendMsg();

    QByteArray getSentData();


};

#endif // TCPSENDMSG_H
