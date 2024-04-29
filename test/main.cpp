#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include<QObject>
#include <random>
#include<QButtonGroup>
#include <QDialog>
#include<QThread>
#include <QPropertyAnimation>
#include<QTimer>
#include <QVBoxLayout>
#include<QMovie>
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
    //MainWindow ma;
    //ma.show();

    QWidget window;
    window.resize(450, 550);
    window.setWindowTitle("显示GIF动画");
    QLabel *label = new QLabel(&window);
    label->setGeometry(QRect(10, 10, 180, 180));

    //QMovie *movie = new QMovie("C:\\Users\\86135\\Desktop\\QT\\test\\image\\rabbit.gif"); // 替换为你的GIF文件路径
    QMovie *movie = new QMovie(":/new/prefix1/image/rabbit.gif"); // 替换为你的GIF文件路径

    label->setMovie(movie);
    movie->start();
    window.show();
    QPushButton *p = new QPushButton(&window);
    p->move(0,0);
    p->show();

    int flag=5;
    mymove *m=new mymove(label);
    QObject::connect(p,&QPushButton::clicked,m,&mymove::move);


    /*
    home a;
    a.show();

    MyButton b;
    b.show();

    QDialog w;
    w.setWindowTitle("hello");
    w.resize(300,300);
    //w.setModal(true);
    //w.show();

    MainWindow window;
    window.resize(550, 450);
    window.setWindowTitle("QPushButton");
    //window.show();


    QLabel *label = new QLabel("Hello, World!", &w); // 创建一个包含文本的QLabel
    label->setText("hello"); // 设置文本内容
    //label->setPixmap(QPixmap(":/images/image.png")); // 设置图像内容
    //label->setWindowTile(QObject::tr("hello"));
    label->setText("success");
    label->show();
*/


    return app.exec();
}
