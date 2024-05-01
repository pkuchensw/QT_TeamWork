#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <random>
#include <QButtonGroup>
#include <QDialog>
#include <QThread>
#include <QPropertyAnimation>
#include <QTimer>
#include <QVBoxLayout>
#include <QMovie>
#include"mainwindow.h"
#include"home.h"
#include"mymove.h"
#include<creature.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Population Evolution Simulator");
    s= new setting;
    for(int i=1;i<=s->initial_num;i++){
        creature* fish=new creature(rand()%700,rand()%700,this);
        c.push_back(fish);
        mymove *m=new mymove(fish->label);
        QObject::connect(ui->movebutton,&QPushButton::clicked,m,&mymove::continuemoves);
    }

}

MainWindow::~MainWindow()
{
    this->close();

}

void MainWindow::on_pushButton_clicked()
{
    creature* fish=new creature(rand()%700,rand()%700,this);
    c.push_back(fish);
    mymove *m=new mymove(fish->label);
    QObject::connect(ui->movebutton,&QPushButton::clicked,m,&mymove::continuemoves);

}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}


void MainWindow::on_movebutton_clicked()
{
}

