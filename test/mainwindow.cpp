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
#include<QPainter>
#include <QVBoxLayout>
#include <QMovie>
#include<ctime>
#include<cstdlib>
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
    for(int i=1;i<=100;i+=10){
        for(int j=1;j<=100;j+=10){
            food[i][j]=1;
            qfood[i][j].setParent(this);
            qfood[i][j].move(i,j);
            qfood[i][j].setText("*");
            qfood[i][j].show();
        }
    }
    for(int i=1;i<=s->initial_num;i++){
        srand(i*i+8*i-7);
        creature* an=new fish(rand()%500,rand()%500,this);
        c.push_back(an);
        mymove *m=new mymove(an);
        mv.push_back(m);
        //QObject::connect(ui->movebutton,&QPushButton::clicked,m,&mymove::continuemoves);
    }

}

MainWindow::~MainWindow()
{
    this->close();

}
void MainWindow::new_start(){

}

void MainWindow::on_pushButton_clicked()
{
    creature* an=new shark(rand()%700,rand()%700,this);
    c.push_back(an);

    mymove *m=new mymove(an);
    mv.push_back(m);
    //QObject::connect(ui->movebutton,&QPushButton::clicked,m,&mymove::continuemoves);

}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}


void MainWindow::on_movebutton_clicked()
{
    for(int i=0;i<mv.size();i++){
        mv[i]->continuemoves();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    s->show();
}


void MainWindow::on_test_clicked()
{
    std::vector<creature* >::iterator it=c.begin();
    while(!c.empty()){
    (*it)->label->close();
    c.erase(it);
    }
}

