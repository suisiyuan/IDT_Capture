#pragma once

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QSettings>

#include "ui_config.h"
#include "OptionDialog.h"
#include "app.h"

class ConfigWidget : public QWidget
{
	Q_OBJECT

public:
	ConfigWidget(QWidget *parent = Q_NULLPTR);

	bool enableBack;
    bool enableFast;
    QString savePath;

    void setBatteryBar(quint8 battery) {ui.batteryBar->setValue(battery);}

private:
	Ui::ConfigWidget ui;

    OptionDialog *optionDialog;
    QSettings *settings;

	bool isLocked;
	

private slots:
	void on_optionButton_clicked();

	void on_lockButton_clicked();
	void on_upButton_clicked();
	void on_downButton_clicked();
	void on_leftButton_clicked();
	void on_rightButton_clicked();

};
