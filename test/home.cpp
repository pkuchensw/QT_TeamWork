#include "home.h"
#include "ui_home.h"
#include <QLabel>
#include<QInputDialog>
#include<cstring>
home::home(QWidget *parent)
    : QDialog(parent),ui(new Ui::home)
{
    ui->setupUi(this);
}

home::~home()
{
    delete ui;
}

void home::on_a_clicked()
{
    QLabel *label=new(QLabel);
    label->setParent(this);
    label->setText("hello");

    label->move(100,this->num*10+100);
    this->num++;
    label->show();
    if(num==2){
        int val=QInputDialog::getInt(this,tr("input"),tr("1000"));
        num=val;
    }

}


void home::on_quit_clicked()
{
    ui->~home();

}


void home::on_pushButton_2_clicked()
{

    QString tmp=QString::fromStdString(std::to_string(num));
    if(1)ui->label->setText(tmp);
}

