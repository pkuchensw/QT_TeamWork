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
    m_animation->setTargetObject(movec->label);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setPropertyName("pos");
    m_animation->setDuration(1000);
    m_animation->setStartValue(movec->label->pos());
    int dx=rand()%30-15,dy=rand()%30-15;
    m_animation->setEndValue(movec->label->pos() + QPoint(dx,dy));
    (movec->labelx)+=dx;
    (movec->labely)+=dy;
    movec->age++;
    movec->hp--;
    movec->label->resize(movec->orgx+std::min(10,movec->age),movec->orgy+std::min(10,movec->age));
    m_animation->start();
    return;
}
void mymove::continuemoves(){
    int n=10;
    while(n--){
        QTimer::singleShot(n*1100,this, SLOT(moves()));
    }
}
void mymove::move(){

}
