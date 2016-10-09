#ifndef TCPRECEIVEMSG_H
#define TCPRECEIVEMSG_H

#include "TcpMsg.h"

class TcpReceiveMsg : public TcpMsg
{
public:
    TcpReceiveMsg(QByteArray message);
    ~TcpReceiveMsg();

    QByteArray getReceivedData();
    TcpMsg::TCP_CMD type();
};

#endif // TCPRECEIVEMSG_H
