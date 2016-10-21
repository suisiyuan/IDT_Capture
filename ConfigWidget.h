#pragma once

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QSettings>
#include <QTimer>

#include "ui_config.h"
#include "OptionDialog.h"
#include "app.h"
#include "config.h"
#include "network.h"



class ConfigWidget : public QWidget
{
	Q_OBJECT

public:
	ConfigWidget(QWidget *parent = Q_NULLPTR);
	~ConfigWidget();

    QString savePath;
	ConfigParams getParams();

private:
	Ui::ConfigWidget ui;

    OptionDialog optionDialog;
    QSettings settings;
	QTimer timer;

	bool isLocked;
	

private slots:
	void on_optionButton_clicked();

	void on_lockButton_clicked();
	void on_upButton_clicked();
	void on_downButton_clicked();
	void on_leftButton_clicked();
	void on_rightButton_clicked();

    void setBatteryBar(quint8 battery);
};
