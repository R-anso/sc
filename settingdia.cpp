#include "settingdia.h"
#include "ui_settingdia.h"

SettingDia::SettingDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDia)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("设置"));
    this->setWindowFlags(Qt::SubWindow);
}

SettingDia::SettingDia(QWidget *parent, double pacity):
    QDialog(parent),ui(new Ui::SettingDia),_pacity(pacity)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("设置"));
    this->setWindowFlags(Qt::SubWindow);
    this->setWindowOpacity(pacity);
    int value = pacity*100 - 1;
    ui->horizontalSlider->setValue(value);
}

SettingDia::~SettingDia()
{
    delete ui;
}

double SettingDia::getPacity()
{
    return _pacity;
}

void SettingDia::on_backBtn_clicked()
{
    this->close();
}

void SettingDia::on_horizontalSlider_valueChanged(int value)
{
    _pacity = double(value+1)/100.0;
    setWindowOpacity(_pacity);
    emit this->pacityChanged();
}
