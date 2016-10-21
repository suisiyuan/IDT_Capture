#include "ConfigWidget.h"

ConfigWidget::ConfigWidget(QWidget *parent) :
	QWidget(parent),
    isLocked(true)
{
	ui.setupUi(this);

	if (!settings.contains("savePath"))
		settings.setValue("savePath", QVariant(DEFAULT_FOLDER));
	savePath = settings.value("savePath", QVariant(DEFAULT_FOLDER)).toString();

    QObject::connect(parent, SIGNAL(emitBattery(quint8)), this, SLOT(setBatteryBar(quint8)));
	QObject::connect(&timer, SIGNAL(timeout()), parent, SLOT(queryBattery()));

	timer.start(QUERY_INTERVAL);
}

ConfigWidget::~ConfigWidget()
{

}

// 配置属性
void ConfigWidget::on_optionButton_clicked()
{
    qint8 result = optionDialog.exec();
    if (result)
    {
        savePath = optionDialog.getSavePath();
        if (optionDialog.getSetDefalt())
            settings.setValue("savePath", QVariant(savePath));
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


// 获取参数
ConfigParams ConfigWidget::getParams()
{
	ConfigParams params;
	params.backEnabled = ui.backCheck->isChecked();
	params.fastEnabled = ui.fastCheck->isChecked();
	params.isUp2Down = (0 == ui.directionCombo->currentIndex());
	params.savePath = savePath;
	return params;
}