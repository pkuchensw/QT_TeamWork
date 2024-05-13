#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setting)
{
    ui->setupUi(this);
    initial[0]=50;
    initial[1]=30;
    initial[2]=10;
}

setting::~setting()
{

    delete ui;
}

void setting::on_initial_num_valueChanged(int arg1)
{
    initial[1]=arg1;
}



void setting::on_initial_num_2_valueChanged(int arg1)
{
    initial[2]=arg1;
}


void setting::on_initial_num_3_valueChanged(int arg1)
{
    initial[0]=arg1;
}

