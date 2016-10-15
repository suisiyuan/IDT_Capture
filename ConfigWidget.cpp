#include "ConfigWidget.h"

ConfigWidget::ConfigWidget(QWidget *parent) :
	QWidget(parent),
	isLocked(true)
{
	ui.setupUi(this);
}



void ConfigWidget::on_lockButton_clicked()
{
	if (isLocked)
	{
		isLocked = false;

        ui.lockButton->setText("锁定");
	}
	else
	{
		isLocked = true;

        ui.lockButton->setText("解锁");
	}
}
