#pragma once

#include <QWidget>
#include <QDebug>

#include "ui_config.h"

class ConfigWidget : public QWidget
{
	Q_OBJECT

public:
	ConfigWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::ConfigWidget ui;

	bool isLocked;

private slots:
	void on_lockButton_clicked();

};