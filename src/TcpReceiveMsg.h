#ifndef TCPRECEIVEMSG_H
#define TCPRECEIVEMSG_H

#include "TcpMsg.h"

class TcpReceiveMsg : public TcpMsg
{
public:
    TcpReceiveMsg(QByteArray packet);
    ~TcpReceiveMsg();

    QByteArray getReceivedData();
    TcpMsg::TCP_CMD type();
    bool isValid();


private:
    bool validation;

};

#endif // TCPRECEIVEMSG_H
