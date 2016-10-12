#include "TcpReceiveMsg.h"


TcpReceiveMsg::TcpReceiveMsg(QByteArray data) :
    TcpMsg()
{

}


TcpReceiveMsg::~TcpReceiveMsg()
{

}





// 获取收到的数据
QByteArray TcpReceiveMsg::getReceivedData()
{
    return QByteArray();
}


// 获取数据包的类型
TcpMsg::TCP_CMD TcpReceiveMsg::type()
{
    return TcpMsg::START;
}
