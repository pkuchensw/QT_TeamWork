#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <random>
#include <QButtonGroup>
#include <QDialog>
#include <QThread>
#include <QPropertyAnimation>
#include <QTimer>
#include <QVBoxLayout>
#include<QMessageBox>
#include <QMovie>
#include"mainwindow.h"
#include"home.h"
#include"mymove.h"
class MyButton : public QWidget {

public:
    MyButton(QWidget *parent = nullptr);
};

MyButton::MyButton(QWidget *parent)
    : QWidget(parent) {

    auto *quitBtn = new QPushButton("退出", this);
    quitBtn->setGeometry(50, 40, 75, 40);
    /**The qApp is a global pointer to the application object.
    It is defined in the QApplication header file.**/
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit); //信号槽 将pushbutton和quit连接
}
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);


    home Home;
    Home.show();

    return app.exec();
}
