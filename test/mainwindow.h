#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QParallelAnimationGroup>
#include<QPropertyAnimation>
#include<creature.h>
#include"setting.h"
#include<vector>
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
    int flag;
    int initial_num;
    std::vector<creature* > c;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_movebutton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
