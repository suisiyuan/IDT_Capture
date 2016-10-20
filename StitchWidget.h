#pragma once

#include <QWidget>
#include <QDebug>
#include <QImage>

#include "ui_stitch.h"
#include "opencv2/opencv.hpp"

using namespace cv;

class StitchWidget : public QWidget
{
	Q_OBJECT

public:
	StitchWidget(QWidget *parent = Q_NULLPTR);
    ~StitchWidget();

private:
	Ui::StitchWidget ui;

	bool isRecording;


private slots:
	void on_lastButton_clicked();
	void on_nextButton_clicked();
	void on_recordButton_clicked();

    void getHeight(qint32);

signals:
    void startRecord();
    void stopRecord();
    void takeSnapshot();
};
