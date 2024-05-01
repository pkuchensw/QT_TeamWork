#include "creature.h"

creature::creature(int x,int y,QWidget *parent)
    : QWidget{parent}
{
    labely=x;
    labelx=y;
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+30, y+30));
    movie = new QMovie("://image/shark.gif"); // 替换为你的GIF文件路径
    label->resize(20,20);
    label->setScaledContents(true);
    label->setMovie(movie);
    label->show();
    movie->start();
    qDebug()<<"creature established";
}
