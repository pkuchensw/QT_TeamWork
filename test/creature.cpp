#include "creature.h"
#include<network.h>
creature::creature(int x,int y,QWidget *parent)
    : QWidget{parent}
{
    labely=x;
    labelx=y; //初始坐标
    nn=new network(50);
    nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
}
int food[1000][1000];
void creature::foraging(){
    for(int i=-3;i<=3;i++){
        for(int j=-3;j<=3;j++){
            if(labelx+i<1||labely+j<1)continue;
            if(food[labelx+i][labely+j]!=0){

                food[labelx+i][labely+j]=0;
                qDebug()<<labelx+i<<" "<<labely+j;
            }
        }
    }
}
fish::fish(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+30, y+15)); //初始位置
    movie = new QMovie("://image/fish.gif"); // 替换为你的GIF文件路径
    label->resize(30,15);
    label->setScaledContents(true);
    label->setMovie(movie);
    label->show();
    movie->start();
}

shark::shark(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+20, y+20)); //初始位置
    movie = new QMovie("://image/shark.gif"); // 替换为你的GIF文件路径
    label->resize(20,20);
    label->setScaledContents(true);
    label->setMovie(movie);
    label->show();
    movie->start();
}
