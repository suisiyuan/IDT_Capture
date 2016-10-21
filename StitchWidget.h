#pragma once

#include <QWidget>
#include <QDebug>
#include <QPixmap>

#include "ui_stitch.h"

#include "VideoOutput.h"
#include "StitchInstance.h"

#include "config.h"

class StitchWidget : public QWidget
{
	Q_OBJECT

public:
	StitchWidget(VideoOutput *videoOutput, ConfigParams params, QWidget *parent = Q_NULLPTR);
    ~StitchWidget();

public slots:
    void updateImage(QPixmap);


private:
	Ui::StitchWidget ui;

	QDir dir;

	bool isRecording;
	VideoOutput *video;
    StitchInstance *instance;



private slots:
	void on_lastButton_clicked();
	void on_nextButton_clicked();
	void on_recordButton_clicked();
	void on_snapshotButton_clicked();

};
