#ifndef MYMOVE_H
#define MYMOVE_H

#include <QObject>

class mymove : public QObject
{
    Q_OBJECT
public:
    explicit mymove(QObject *parent = nullptr);
public:
    QWidget* label;
    mymove(QWidget* label_){
        label=label_;
    }
public slots:
    void moves();
    void continuemoves();
    void move();
signals:
};

#endif // MYMOVE_H
