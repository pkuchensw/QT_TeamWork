#include "mymove.h"
#include<creature.h>
mymove::mymove(creature* movec_,QObject *parent)
    : QObject{parent}
{
    movec=movec_;
}
#include "move.h"
#include<QPropertyAnimation>
#include<QTimer>
#include<QWidget>
#include<QPoint>
#include<mainwindow.h>
void mymove::moves(){
    QPropertyAnimation *m_animation=new(QPropertyAnimation);
    m_animation->setTargetObject(movec->label);    //设置使用动画的控件
    m_animation->setEasingCurve(QEasingCurve::Linear); //设置动画效果
    m_animation->setPropertyName("pos");    //指定动画属性名
    m_animation->setDuration(1000);    //设置动画时间（单位：毫秒）
    m_animation->setStartValue(movec->label->pos());  //设置动画起始位置在label控件当前的pos
    double* v=new double[4]{rand()%200,10,rand()%100,100};
    movec->nn->cal(v);
    m_animation->setEndValue(movec->label->pos() + QPoint(movec->nn->get_ans().front()*10,movec->nn->get_ans().front()*10)); //设置动画结束位置
    //m_animation->setEndValue(movec->label->pos() + QPoint(rand()%30,rand()%30));
    movec->labelx+=(movec->nn->get_ans().front()*10);
    movec->labely+=(movec->nn->get_ans().front()*10);
    //movec->foraging();
    m_animation->start();
    return;
}
void mymove::forage(){
    //movec->foraging();
    for(int i=-20;i<=20;i++){
        for(int j=-20;j<=20;j++){
            if(movec->labelx+i<=0||movec->labely+j<=0)continue;
            //if(movec->labelx+i%10==1&&movec->labely%10==1)q[movec->labelx+i][movec->labely+j].close();
        }
    }

}
void mymove::continuemoves(){
    int n=10;
    while(n--){
        QTimer::singleShot(n*1100,this, SLOT(moves()));
        QTimer::singleShot(n*1100+100,this, SLOT(forage()));
    }
}
void mymove::move(){

}
