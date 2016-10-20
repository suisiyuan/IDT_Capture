#include "OptionDialog.h"

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    settings(new QSettings())
{
	ui.setupUi(this);

    // 检查注册表是否有默认保存路径 如果没有就默认在C盘下应用名称文件夹下存储
    ui.savePathLabel->setText(settings->value("savePath", QVariant(DEFAULT_FOLDER)).toString());
}

OptionDialog::~OptionDialog()
{
	delete settings;
}


// 浏览并设置保存路径
void OptionDialog::on_toolButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "获取工程文件保存路径", settings->value("savePath", QVariant(DEFAULT_FOLDER)).toString(), QFileDialog::ShowDirsOnly);
    if (!dir.isEmpty())
        ui.savePathLabel->setText(dir);
}
