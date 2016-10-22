#include "ConfigWidget.h"

ConfigWidget::ConfigWidget(QWidget *parent) :
	QWidget(parent),
    isLocked(true)
{
	ui.setupUi(this);

	if (!settings.contains("savePath"))
		settings.setValue("savePath", QVariant(DEFAULT_FOLDER));
	savePath = settings.value("savePath", QVariant(DEFAULT_FOLDER)).toString();

    if (!settings.contains("led"))
        settings.setValue("led", QVariant(DEFAULT_LED));
    led = settings.value("led", QVariant(DEFAULT_LED)).toInt();
    setLedButton(led);


    QObject::connect(parent, SIGNAL(emitBattery(quint8)), this, SLOT(setBatteryBar(quint8)));
	QObject::connect(&timer, SIGNAL(timeout()), parent, SLOT(queryBattery()));
    QObject::connect(this, SIGNAL(setLed(quint8)), parent, SLOT(setLed(quint8)));
    QObject::connect(ui.focusButton, SIGNAL(clicked()), parent, SLOT(focusCamera()));
    QObject::connect(&tempTimer, SIGNAL(timeout()), this, SLOT(setFocusButton()));

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
    params.savePath = QDir(savePath).filePath(QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss"));
	return params;
}

// 降低亮度
void ConfigWidget::on_decButton_clicked()
{
    led--;
    setLedButton(led);
    emit setLed(led);
}

// 提高亮度
void ConfigWidget::on_incButton_clicked()
{
    led++;
    setLedButton(led);
    emit setLed(led);
}

void ConfigWidget::setLedButton(quint8)
{
    if (MAX_LED == led)
    {
        ui.decButton->setEnabled(true);
        ui.incButton->setEnabled(false);
    }
    else if (MIN_LED == led)
    {
        ui.decButton->setEnabled(false);
        ui.incButton->setEnabled(true);
    }
    else
    {
        ui.decButton->setEnabled(true);
        ui.incButton->setEnabled(true);
    }
}


void ConfigWidget::on_focusButton_clicked()
{
    ui.focusButton->setEnabled(false);
    tempTimer.start(5000);
}


void ConfigWidget::setFocusButton()
{
    ui.focusButton->setEnabled(true);
}
