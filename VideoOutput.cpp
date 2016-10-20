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
    QLabel(parent)
{
//    this->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//    this->setLineWidth(2);

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
    QObject::connect(parent, SIGNAL(snapshot(QDir)), this, SLOT(takeSnapshot(QDir)));
    QObject::connect(parent, SIGNAL(record(QDir)), this, SLOT(startRecord(QDir)));
	QObject::connect(parent, SIGNAL(endRecord()), this, SLOT(stopRecord()));
}


VideoOutput::~VideoOutput()
{
    libvlc_media_player_release(player);
    libvlc_release(instance);
    delete param;
}



void VideoOutput::startPlayer()
{
    libvlc_media_player_play(player);
}

void VideoOutput::stopPlayer()
{
    libvlc_media_player_stop(player);
}


void VideoOutput::takeSnapshot(QDir dir)
{
    QString name = QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss").append(".png");

    Mat temp;
    param->image.copyTo(temp);
    cvtColor(temp, temp, COLOR_RGBA2BGR);
    imwrite(dir.filePath(name).toStdString(), temp);
}


void VideoOutput::startRecord(QDir dir)
{
    QString filename, parameters, option1, option2;
    filename = dir.filePath(QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss").append(".mp4"));
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

}

void VideoOutput::stopRecord()
{
    libvlc_media_player_set_media(player, media);
    libvlc_media_player_play(player);
}
