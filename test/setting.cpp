#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setting)
{
    ui->setupUi(this);
    initial_num=30;
}

setting::~setting()
{
    delete ui;
}

void setting::on_initial_num_valueChanged(int arg1)
{
    initial_num=arg1;
}

