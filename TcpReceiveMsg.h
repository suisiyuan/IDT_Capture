#ifndef TCPRECEIVEMSG_H
#define TCPRECEIVEMSG_H

#include "TcpMsg.h"

class TcpReceiveMsg : public TcpMsg
{
public:
    TcpReceiveMsg(QByteArray data);
    ~TcpReceiveMsg();

    QByteArray getReceivedData();
    TcpMsg::TCP_CMD type();
};

#endif // TCPRECEIVEMSG_H
