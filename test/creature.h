#ifndef CREATURE_H
#define CREATURE_H
#include<random>
#include<QObject>
#include<QMovie>
#include<QLabel>
#include<qdebug.h>
#include<network.h>
class creature : public QWidget
{
    Q_OBJECT
public:
    explicit creature(int x,int y,QWidget *parent = nullptr);

signals:
public:
    network* nn;
    int type;
    int age,orgx,orgy,hp;
    int labelx,labely;
    int eyesight;
    int distance;
    QLabel *label;
    QMovie *movie;

public:
    void foraging();
    creature(const creature& a,QWidget *parent=nullptr);
    //virtual predation()=0;
    //virtual reproduction()=0;

};

class fish:public creature{
public:
    explicit fish(int x,int y,QWidget *parent = nullptr);
};

class shark:public creature{
public:
    explicit shark(int x,int y,QWidget *parent = nullptr);
};
class grass:public creature{
public:
   explicit grass(int x,int y,QWidget *parent = nullptr);
};

class whale:public creature{
public:
    explicit whale(int x,int y,QWidget *parent = nullptr);
};

#endif // CREATURE_H
