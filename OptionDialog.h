#pragma once

#include <QDir>
#include <QDialog>
#include <QSettings>
#include <QFileDialog>

#include "ui_option.h"
#include "app.h"


class OptionDialog : public QDialog
{
	Q_OBJECT

public:
	OptionDialog(QWidget *parent = Q_NULLPTR);
	~OptionDialog();

    QString getSavePath() {return ui.savePathLabel->text();}
    bool getSetDefalt() {return ui.defaultCheck->isChecked();}

private:
    Ui::OptionDialog ui;

    QSettings settings;

private slots:
	void on_toolButton_clicked();
};

