#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QParallelAnimationGroup>
#include<QPropertyAnimation>
#include<creature.h>
#include"setting.h"
#include<mymove.h>
#include<vector>
#include<QPainter>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    setting* s;
    QPropertyAnimation* m_animation;
    QParallelAnimationGroup *anima = new QParallelAnimationGroup(this);
    QLabel qfood[1000][1000];
    int food[1000][1000];
    int flag;
    int initial_num;
    std::vector<creature* > c;
    std::vector<mymove* > mv;
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        QPixmap pixmap("://image/ocean.jpg"); // 替换为你的图片路径
        pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);
        painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);
    }
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void new_start();
public slots:
    void destruct();
    void forage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_movebutton_clicked();

    void on_pushButton_3_clicked();

    void on_test_clicked();

    void on_start_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
