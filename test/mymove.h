#ifndef MYMOVE_H
#define MYMOVE_H

#include <QObject>

class mymove : public QObject
{
    Q_OBJECT
public:
    explicit mymove(QWidget* label_,QObject *parent = nullptr);
public:
    QWidget* label;

public slots:
    void moves();
    void continuemoves();
    void move();
signals:
};

#endif // MYMOVE_H
