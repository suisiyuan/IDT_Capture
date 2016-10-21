#include "OptionDialog.h"

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    settings(new QSettings())
{
	ui.setupUi(this);

    ui.savePathLabel->setText(settings.value("savePath", QVariant(DEFAULT_FOLDER)).toString());
}

OptionDialog::~OptionDialog()
{
	
}


// 浏览并设置保存路径
void OptionDialog::on_toolButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "获取工程文件保存路径", settings.value("savePath", QVariant(DEFAULT_FOLDER)).toString(), QFileDialog::ShowDirsOnly);
    if (!dir.isEmpty())
        ui.savePathLabel->setText(dir);
}
