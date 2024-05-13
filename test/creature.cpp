#include "creature.h"
#include<network.h>
creature::creature(int x,int y,QWidget *parent)
    : QWidget{parent}
{
    age=0;
    hp=5;
    labelx=x;
    labely=y; //初始坐标
}
creature::creature(const creature &a,QWidget *parent)
{
    type=a.type;
    labelx=a.labelx+2;
    labely=a.labely+2;
    orgx=a.orgx;
    orgy=a.orgy;
    age=0;
    hp=5;
    nn=new network(50);
    nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    label = new QLabel(parent);
    //label->setGeometry(QRect(labelx, labely, labelx+50, labely+25)); //初始位置
    label->resize(orgx,orgy);
    if(type==1)movie =new QMovie("://image/fish.gif");
    if(type==2)movie =new QMovie("://image/shark.gif");
    label->setScaledContents(true);
    label->setMovie(movie);
    label->move(labelx,labely);
    label->show();
    movie->start();
}
void creature::foraging(){
    for(int i=-3;i<=3;i++){
        for(int j=-3;j<=3;j++){
            if(labelx+i<1||labely+j<1)continue;

        }
    }
}
fish::fish(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    type=1;
    nn=new network(50);
    nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+50, y+25)); //初始位置

    label->resize(50,25);
    orgx=50;
    orgy=25;
    /*
    movie = new QMovie("://image/fish.gif"); // 替换为你的GIF文件路径
    label->setScaledContents(true);
    label->setMovie(movie);
    label->show();
    movie->start();
    */
    QPixmap pixmap("://image/fish.png"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}

shark::shark(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    type=2;
    nn=new network(50);
    nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+40, y+40)); //初始位置
    label->resize(40,40);
    orgx=40;
    orgy=40;
    /*
    movie = new QMovie("://image/shark.gif"); // 替换为你的GIF文件路径
    label->setScaledContents(true);
    label->setMovie(movie);
    label->show();
    movie->start();
*/
    QPixmap pixmap("://image/shark.png"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}

whale::whale(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    type=2;
    nn=new network(50);
    nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+40, y+40)); //初始位置
    label->resize(40,40);
    orgx=40;
    orgy=40;
    /*
    movie = new QMovie("://image/whale.gif"); // 替换为你的GIF文件路径
    label->setScaledContents(true);
    label->setMovie(movie);
    label->show();
    movie->start();
    */

    QPixmap pixmap("://image/whale.jpg"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}
grass::grass(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    type=0;
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+40, y+40)); //初始位置
    label->resize(20,20);
    /*movie = new QMovie("://image/grass.gif"); // 替换为你的GIF文件路径
    label->setScaledContents(true);
    label->setMovie(movie);
    label->show();
    movie->start();
    */
    QPixmap pixmap("://image/grass.jpg"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}
