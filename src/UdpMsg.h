#ifndef UDPMSG_H
#define UDPMSG_H

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


#endif // UDPMSG_H
