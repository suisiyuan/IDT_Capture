#include "VideoOutput.h"

static void *lock(void *op, void **plane)
{
    TCallbackParam *p = (TCallbackParam *)op;
    p->mutex.lock();

    *plane = (void *)(p->image.data);
    return NULL;
}

static void unlock(void *op, void *pic, void *const *plane)
{
    TCallbackParam *p = (TCallbackParam *)op;
    uchar *data = (uchar *)*plane;

    if ((float)(p->video->height()) / p->video->width() > VIDEO_RATIO)
        p->video->setPixmap(QPixmap::fromImage(QImage(data, VIDEO_WIDTH, VIDEO_HEIGHT, QImage::Format_RGBA8888)).scaledToWidth(p->video->width()));
    else
        p->video->setPixmap(QPixmap::fromImage(QImage(data, VIDEO_WIDTH, VIDEO_HEIGHT, QImage::Format_RGBA8888)).scaledToHeight(p->video->height()));



    p->mutex.unlock();
}


VideoOutput::VideoOutput(QWidget *parent) :
    QLabel(parent),
	recording(false)
{
    instance = libvlc_new(0, Q_NULLPTR);
    qDebug() << libvlc_get_version() << libvlc_get_compiler();
    media = libvlc_media_new_location(instance, "rtsp://192.168.1.10:6880/test.264");
    player = libvlc_media_player_new_from_media(media);

    param = new TCallbackParam(this);
    libvlc_video_set_callbacks(player, lock, unlock, NULL, param);
    libvlc_video_set_format(player, "RGBA", VIDEO_WIDTH, VIDEO_HEIGHT, VIDEO_WIDTH*4);

    QObject::connect(parent, SIGNAL(play()), this, SLOT(startPlayer()));
    QObject::connect(parent, SIGNAL(stop()), this, SLOT(stopPlayer()));
    QObject::connect(parent, SIGNAL(stop()), this, SLOT(clear()));
}


VideoOutput::~VideoOutput()
{
    libvlc_media_player_release(player);
    libvlc_release(instance);
    delete param;
}


bool VideoOutput::isRecording()
{
	return recording;
}


void VideoOutput::startPlayer()
{
    libvlc_media_player_play(player);
}

void VideoOutput::stopPlayer()
{
    libvlc_media_player_stop(player);
}



Mat VideoOutput::takeSnapshot()
{
	Mat temp;
    param->mutex.lock();
    param->image.copyTo(temp);
    param->mutex.unlock();
	return temp;
}


bool VideoOutput::takeSnapshot(QString filename)
{
    Mat temp;
	param->mutex.lock();
    param->image.copyTo(temp);
	param->mutex.unlock();
    return imwrite(filename.toStdString(), temp);;
}


void VideoOutput::startRecord(QString filename)
{
    QString parameters, option1, option2;
    parameters = "std{access=file,mux=mp4,dst='%1'}";
    parameters = parameters.arg(filename);
    option1 = ":sout-all";
    option2 = ":sout=#duplicate{dst=display,dst=\"%1\"}";
    option2 = option2.arg(parameters);

    recordMedia = libvlc_media_new_location(instance, "rtsp://192.168.1.10:6880/test.264");
    libvlc_media_add_option(recordMedia, option1.toStdString().data());
    libvlc_media_add_option(recordMedia, option2.toStdString().data());

    libvlc_media_player_set_media(player, recordMedia);
    libvlc_media_player_play(player);

    libvlc_media_release(recordMedia);

	recording = true;

}

void VideoOutput::stopRecord()
{
    libvlc_media_player_set_media(player, media);
    libvlc_media_player_play(player);

	recording = false;
}
