#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QPropertyAnimation>
#include<QThread>
#include<cstring>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_animation = new QPropertyAnimation();
    ui->q=new QLabel[10];
    ui->q[0].setText("qlabel");
    ui->q[0].setParent(this);

}

MainWindow::~MainWindow()
{
    this->close();

}

void MainWindow::on_pushButton_clicked()
{
    flag=1;
    qDebug()<<"clicked";
    this->setWindowTitle("hello world");


}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_3_clicked()
{
    m_animation->setTargetObject(ui->label);    //设置使用动画的控件
    m_animation->setEasingCurve(QEasingCurve::Custom); //设置动画效果
    m_animation->setPropertyName("pos");    //指定动画属性名
    m_animation->setDuration(3000);    //设置动画时间（单位：毫秒）
    m_animation->setStartValue(ui->label->pos());  //设置动画起始位置在label控件当前的pos
    m_animation->setEndValue(ui->label->pos() + QPoint(200, 100)); //设置动画结束位置
    anima->addAnimation(m_animation);

    //QThread::msleep(3000);
    /*
    QPropertyAnimation* m=new QPropertyAnimation();
    m->setTargetObject(&(this->ui->q[0]));
    m->setPropertyName("pos");    //指定动画属性名
    m->setDuration(1000);    //设置动画时间（单位：毫秒）
    m->setStartValue(ui->q[0].pos());  //设置动画起始位置在label控件当前的pos
    m->setEndValue(ui->q[0].pos() + QPoint(200, 100)); //设置动画结束位置
    anima->addAnimation(m);
    */
    anima->start();
}

