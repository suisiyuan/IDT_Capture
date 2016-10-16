#pragma once

#include <QWidget>
#include <QDebug>

#include "ui_stitch.h"

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

signals:
    void startRecord();
    void stopRecord();
};
