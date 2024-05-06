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
#include<cmath>
#include<cstdlib>
#include"mainwindow.h"
#include"home.h"
#include"mymove.h"
#include<creature.h>
typedef std::vector<creature* >::iterator itc;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Population Evolution Simulator");
    s= new setting;
    for(int i=1;i<=s->initial_num;i++){
        creature* an=new grass(rand()%700,rand()%700,this);
        c.push_back(an);
    }
    for(int i=1;i<=s->initial_num;i++){
        creature* an=new fish(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an);
        mv.push_back(m);
    }
    for(int i=1;i<=s->initial_num;i++){
        creature* an=new shark(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an);
        mv.push_back(m);
    }

}

MainWindow::~MainWindow()
{
    this->close();

}
void MainWindow::new_start(){
    std::vector<creature* >::iterator it=c.begin();
    std::vector<mymove* >::iterator it_=mv.begin();

    while(!c.empty()){
        (*it)->label->close();
        c.erase(it);
    }
    while(!mv.empty()){
        mv.erase(it_);
    }
    for(int i=1;i<=s->initial_num;i++){
        creature* an=new fish(rand()%500,rand()%500,this);
        c.push_back(an);
        mymove *m=new mymove(an);
        mv.push_back(m);
    }
}

void MainWindow::on_pushButton_clicked()
{    
    creature* an=new shark(rand()%700,rand()%700,this);
    c.push_back(an);
    mymove *m=new mymove(an);
    mv.push_back(m);

}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::destruct(){
    int tmp[100],num=c.size();
    for(itc i=c.begin();i<c.end();i++){
        for(itc j=i+1;j<c.end();j++){
            if(abs((*i)->labelx - (*j)->labelx)+abs((*i)->labely - (*j)->labely)<=20){
                tmp[(i-c.begin())]=-1;
            }
        }
    }
    for(itc i=c.end()-1;i>=c.begin();i--){
        if(tmp[(i-c.begin())]==-1){
            (*i)->label->close();
            i=c.erase(i);
        }
    }
}

void MainWindow::forage(){
    int num=c.size();
    for(int i=0;i<num;i++){
        if(c[i]->age>=2 && rand()%10>=8){
            creature *tmp=new creature(*c[i],this);
            c.push_back(tmp);
            mymove *m=new mymove(tmp);
            mv.push_back(m);
        }
    }
}
void MainWindow::on_movebutton_clicked()
{
    for(int i=0;i<mv.size();i++){
        mv[i]->moves();
    }
    QTimer::singleShot(1150,this,SLOT(destruct()));
    QTimer::singleShot(1200,this,SLOT(forage()));
}


void MainWindow::on_pushButton_3_clicked()
{
    s->show();
}


void MainWindow::on_test_clicked()
{
    creature *tmp=new creature(*c[0],this);
    c.push_back(tmp);
    mymove *m=new mymove(tmp);
    mv.push_back(m);
}


void MainWindow::on_start_clicked()
{
    new_start();
}

