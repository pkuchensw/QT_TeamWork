#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include<QButtonGroup>
#include <QDialog>
#include <QPropertyAnimation>
#include<QThread>
#include <QVBoxLayout>
#include<QMovie>
#include"mainwindow.h"
#include"home.h"
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
class mymove:public QObject{
    public:
        QWidget* label;
        mymove(QWidget* label_){
            label=label_;
        }
    public slots:
        void moves(){
        QPropertyAnimation *m_animation=new(QPropertyAnimation);
        m_animation->setTargetObject(label);    //设置使用动画的控件
        m_animation->setEasingCurve(QEasingCurve::Linear); //设置动画效果
        m_animation->setPropertyName("pos");    //指定动画属性名
        m_animation->setDuration(3000);    //设置动画时间（单位：毫秒）
        m_animation->setStartValue(label->pos());  //设置动画起始位置在label控件当前的pos
        m_animation->setEndValue(label->pos() + QPoint(200, 100)); //设置动画结束位置
        m_animation->start();
        return;
    }
};
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow ma;
    ma.show();

    QWidget window;
    window.resize(450, 550);
    window.setWindowTitle("显示GIF动画");
    QLabel *label = new QLabel(&window);
    label->setGeometry(QRect(10, 10, 180, 180));

    QMovie *movie = new QMovie("C:\\Users\\86135\\Desktop\\QT\\test\\resources\\rabbit.gif"); // 替换为你的GIF文件路径
    label->setMovie(movie);
    movie->start();
    window.show();


    QThread::msleep(1000);
    QPushButton *p = new QPushButton(&window);
    p->move(0,0);
    p->show();
    mymove *m=new mymove(label);
    QObject::connect(p,&QPushButton::clicked,m,&mymove::moves);

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
