#include "StitchWidget.h"

StitchWidget::StitchWidget(VideoOutput *videoOutput, ConfigParams params, QWidget *parent) :
	QWidget(parent),
	dir(QDir(params.savePath)),
	isRecording(false),
    instance(new StitchInstance(params, videoOutput)),
    scene(new QGraphicsScene()),
    pixmapItem(new QGraphicsPixmapItem()),
    video(videoOutput)
{
	ui.setupUi(this);

	// 检查工程文件保存路径是否存在
	if (!dir.exists())
		dir.mkpath(params.savePath);

    qDebug() << ui.stitchView->width() << ui.stitchView->height();

    // 新建图片
    QPixmap pixmap(200, 200);
    pixmap.fill(Qt::black);
    pixmapItem->setPixmap(pixmap);

    // 添加QGraphicsScene
    scene->setSceneRect(0, 0, 1000, 1000);
    scene->addItem(pixmapItem);

    ui.stitchView->setScene(scene);

    qDebug() << ui.stitchView->width() << ui.stitchView->height();

	// 高度
    QObject::connect(parent, SIGNAL(emitHeight(qint32)), instance, SLOT(getHeight(qint32)));
    // 更新显示照片
    QObject::connect(instance, SIGNAL(updateImage(QPixmap,uint16,uint16)), this, SLOT(updateImage(QPixmap,uint16,uint16)));
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
void StitchWidget::updateImage(QPixmap pixmap, quint16 currentIndex, quint16 count)
{
    scene->addPixmap(pixmap.scaledToWidth(ui.stitchView->width()));

    if (currentIndex < count)
        ui.nextButton->setEnabled(true);
    else if (currentIndex == count)
        ui.nextButton->setEnabled(false);

    if (0 < currentIndex)
        ui.lastButton->setEnabled(true);
    else if (0 == currentIndex)
        ui.lastButton->setEnabled(false);

}
