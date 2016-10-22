#pragma once

#include <QLabel>
#include <QMutex>
#include <QDebug>
#include <QDir>
#include <QDateTime>
#include <QString>
#include <QStringList>

#include "vlc/vlc.h"
#include "opencv2/opencv.hpp"

using namespace cv;

#define VIDEO_WIDTH     1280
#define VIDEO_HEIGHT    720
#define VIDEO_RATIO     ((float)VIDEO_HEIGHT / VIDEO_WIDTH)


typedef struct TCallbackParam
{
    QLabel *video;
    QMutex mutex;
    Mat image;

    TCallbackParam()
    {
        video = Q_NULLPTR;
        image = Mat(VIDEO_HEIGHT, VIDEO_WIDTH, CV_8UC4);
    }

    TCallbackParam(QLabel *label)
    {
        video = label;
        image = Mat(VIDEO_HEIGHT, VIDEO_WIDTH, CV_8UC4);
    }
}TCallbackParam;


static void *lock(void *op, void **plane);
static void unlock(void *op, void *pic, void *const *plane);




class VideoOutput : public QLabel
{    
    Q_OBJECT

public:
    VideoOutput(QWidget *parent);
    ~VideoOutput();

	bool isRecording();

public slots:
	Mat takeSnapshot();
	bool takeSnapshot(QString);
	void startRecord(QString);
	void stopRecord();

private:
    libvlc_instance_t *instance;
    libvlc_media_player_t *player;
    libvlc_media_t *media, *recordMedia;

    TCallbackParam *param;

	bool recording;

private slots:
	

	void startPlayer();
	void stopPlayer();

};




