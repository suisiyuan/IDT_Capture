#pragma once

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QSettings>
#include <QTimer>
#include <QDateTime>
#include <QDir>

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


	ConfigParams getParams();

private:
	Ui::ConfigWidget ui;

    OptionDialog optionDialog;
    QSettings settings;
    QTimer timer, tempTimer;

	bool isLocked;
    QString savePath;
    quint8 led;

    void setLedButton(quint8);

private slots:
	void on_optionButton_clicked();

	void on_lockButton_clicked();
	void on_upButton_clicked();
	void on_downButton_clicked();
	void on_leftButton_clicked();
	void on_rightButton_clicked();

    void setBatteryBar(quint8 battery);
    void on_decButton_clicked();
    void on_incButton_clicked();

    void on_focusButton_clicked();
    void setFocusButton();

signals:
    void setLed(quint8);

};
