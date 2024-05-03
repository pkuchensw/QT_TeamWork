#ifndef MYMOVE_H
#define MYMOVE_H

#include <QObject>
#include<creature.h>
class mymove : public QObject
{
    Q_OBJECT
public:
    explicit mymove(creature* movec_ ,QObject *parent = nullptr);
public:
    //QWidget* label;
    creature* movec;

public slots:
    void moves();
    void continuemoves();
    void move();
    void forage();
signals:
};

#endif // MYMOVE_H
