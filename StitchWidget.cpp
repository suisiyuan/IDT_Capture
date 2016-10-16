#include "StitchWidget.h"

StitchWidget::StitchWidget(QWidget *parent) :
	QWidget(parent),
	isRecording(false)
{
	ui.setupUi(this);

    QObject::connect(this, SIGNAL(startRecord()), parent, SLOT(startRecord()));
    QObject::connect(this, SIGNAL(stopRecord()), parent, SLOT(stopRecord()));
}

StitchWidget::~StitchWidget()
{
    emit stopRecord();
}

// 上一页
void StitchWidget::on_lastButton_clicked()
{
	qDebug() << "Last";
}

// 下一页
void StitchWidget::on_nextButton_clicked()
{
	qDebug() << "Next";
}

// 录像
void StitchWidget::on_recordButton_clicked()
{
	if (isRecording)
	{
		isRecording = false;
        ui.recordButton->setText("录像");

        emit stopRecord();
	}
	else
	{
		isRecording = true;
        ui.recordButton->setText("停止录像");

        emit startRecord();
	}
}


