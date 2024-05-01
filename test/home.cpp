#include "home.h"
#include "ui_home.h"
#include"readme.h"
#include <QLabel>
#include<QInputDialog>
#include<cstring>
#include"mainwindow.h"
home::home(QWidget *parent)
    : QDialog(parent),ui(new Ui::home)
{
    ui->setupUi(this);
}

home::~home()
{
    delete ui;
}

void home::on_individual_clicked()
{
    MainWindow*m=new MainWindow(this);
    m->show();
}


void home::on_quit_clicked()
{
    this->close();

}


void home::on_group_clicked()
{


}


void home::on_readme_clicked()
{
    readme* r=new readme;
    r->show();
}

