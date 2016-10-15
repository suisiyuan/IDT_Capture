#include "StitchWidget.h"

StitchWidget::StitchWidget(QWidget *parent) :
	QWidget(parent),
	isRecording(false)
{
	ui.setupUi(this);
}



void StitchWidget::on_lastButton_clicked()
{
	qDebug() << "Last";
}

void StitchWidget::on_nextButton_clicked()
{
	qDebug() << "Next";
}


void StitchWidget::on_recordButton_clicked()
{
	if (isRecording)
	{
		isRecording = false;
        ui.recordButton->setText("录像");
	}
	else
	{
		isRecording = true;
        ui.recordButton->setText("停止录像");
	}
}
