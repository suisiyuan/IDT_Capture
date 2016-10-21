#include "StitchWidget.h"

StitchWidget::StitchWidget(VideoOutput *videoOutput, ConfigParams params, QWidget *parent) :
	QWidget(parent),
	dir(QDir(params.savePath)),
	isRecording(false),
    video(videoOutput)
{
	ui.setupUi(this);

	// 检查工程文件保存路径是否存在
	if (!dir.exists())
	{
		dir.mkpath(params.savePath);
	}
	// 创建工程文件夹
	QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss");
	dir.mkdir(currentTime);
	dir.cd(currentTime);

    params.savePath = dir.path();
    instance = new StitchInstance(params);

	// 高度
    QObject::connect(parent, SIGNAL(emitHeight(qint32)), instance, SLOT(getHeight(qint32)));
}


StitchWidget::~StitchWidget()
{
	if (video->isRecording())
		video->stopRecord();
    delete instance;
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
	if (!isRecording)
	{
		isRecording = true;
        ui.recordButton->setText("停止录像");

		QString filename = dir.filePath(QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss").append(".mp4"));
		if (video->isRecording())
			video->stopRecord();
		video->startRecord(filename);
	}
	else
	{
		isRecording = false;
        ui.recordButton->setText("录像");

		video->stopRecord();
	}
}

// 截屏
void StitchWidget::on_snapshotButton_clicked()
{
	QString filename = dir.filePath(QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss").append(".png"));
	if (!video->takeSnapshot(filename))
		qDebug() << "Save snapshot to disk failed!";
}

// 更新展示照片
void StitchWidget::updateImage(QPixmap pixmap)
{

}
