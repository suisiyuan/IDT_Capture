#pragma once

#include <QWidget>
#include <QDebug>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QList>
#include <QLabel>

#include "ui_stitch.h"

#include "VideoOutput.h"

#include "config.h"
#include "opencv2/opencv.hpp"
 
using namespace cv;

#define HEIGHT_RATIO		((double)400 / 4096)

class StitchWidget : public QWidget
{
	Q_OBJECT

public:
	StitchWidget(VideoOutput *videoOutput, ConfigParams params, QWidget *parent = Q_NULLPTR);
    ~StitchWidget();

private:
	Ui::StitchWidget ui;

	QDir dir;
	bool isRecording;
	VideoOutput *video;

	bool backEnabled, fastEnabled, isUp2Down;
	qint32 lastHeight;
	QList<quint32> saveHeightList;
	quint16 currentIndex, count;

	Mat stitchingImage;

private slots:
	void on_lastButton_clicked();
	void on_nextButton_clicked();
	void on_recordButton_clicked();
	void on_snapshotButton_clicked();

	void getHeight(qint32);
};
