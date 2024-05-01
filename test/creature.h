#ifndef CREATURE_H
#define CREATURE_H
#include<random>
#include<QObject>
#include<QMovie>
#include<QLabel>
#include<qdebug.h>
class creature : public QWidget
{
    Q_OBJECT
public:
    explicit creature(int x,int y,QWidget *parent = nullptr);

signals:
public:
    int type;
    int labelx,labely;
    int eyesight;
    int distance;
    QLabel *label;
    QMovie *movie;

public:
    //virtual foraging()=0;
    //virtual predation()=0;
    //virtual reproduction()=0;

};

//class fish:public creature{
//};

#endif // CREATURE_H
