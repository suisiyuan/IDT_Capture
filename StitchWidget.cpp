#include "StitchWidget.h"

StitchWidget::StitchWidget(QWidget *parent) :
	QWidget(parent),
	isRecording(false)
{
	ui.setupUi(this);

    QObject::connect(this, SIGNAL(startRecord()), parent, SLOT(startRecord()));
    QObject::connect(this, SIGNAL(stopRecord()), parent, SLOT(stopRecord()));

    // 截图
    QObject::connect(ui.snapshotButton, SIGNAL(clicked()), parent, SLOT(takeSnapshot()));
    QObject::connect(parent, SIGNAL(snapshotTaken(QString)), this, SLOT(on_snapshot_taken(QString)));

    // 高度
    QObject::connect(parent, SIGNAL(emitHeight(qint32)), this, SLOT(getHeight(qint32)));
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

// 截图完成后
void StitchWidget::on_snapshot_taken(QString filename)
{
    qDebug() << "snapshot:" << filename;
    QImage img(filename, "PNG");
    qDebug() << img.width() << img.height();
}

// 接收高度
void StitchWidget::getHeight(qint32 height)
{
    qDebug() << "height:" << height;
}
