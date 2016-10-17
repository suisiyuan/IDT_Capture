#include "ConfigWidget.h"

ConfigWidget::ConfigWidget(QWidget *parent) :
	QWidget(parent),
    optionDialog(new OptionDialog(this)),
    settings(new QSettings()),
    savePath(DEFAULT_FOLDER),
    isLocked(true)
{
	ui.setupUi(this);

    QObject::connect(parent, SIGNAL(emitBattery(quint8)), this, SLOT(setBatteryBar(quint8)));
}

// 配置属性
void ConfigWidget::on_optionButton_clicked()
{
    qint8 result = optionDialog->exec();
    if (result)
    {
        savePath = optionDialog->getSavePath();
        if (optionDialog->getSetDefalt())
            settings->setValue("savePath", QVariant(savePath));
    }
}


// 锁定 解锁
void ConfigWidget::on_lockButton_clicked()
{
	if (isLocked)
	{
		isLocked = false;

        ui.lockButton->setText("锁定");
		ui.upButton->setEnabled(true);
		ui.downButton->setEnabled(true);
		ui.leftButton->setEnabled(true);
		ui.rightButton->setEnabled(true);
	}
	else
	{
		isLocked = true;

        ui.lockButton->setText("解锁");
        ui.upButton->setEnabled(false);
		ui.downButton->setEnabled(false);
		ui.leftButton->setEnabled(false);
		ui.rightButton->setEnabled(false);
	}
}


// 上
void ConfigWidget::on_upButton_clicked()
{

}

// 下
void ConfigWidget::on_downButton_clicked()
{

}

// 左
void ConfigWidget::on_leftButton_clicked()
{

}

// 右
void ConfigWidget::on_rightButton_clicked()
{

}

// 设置电量
void ConfigWidget::setBatteryBar(quint8 battery)
{
    qDebug() << "Set battery";
    ui.batteryBar->setValue(battery);
}
