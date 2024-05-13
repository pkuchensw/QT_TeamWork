#ifndef HOME_H
#define HOME_H

#include <QDialog>
#include<Qpainter>
namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    int num=0;
    explicit home(QWidget *parent = nullptr);
    ~home();

private slots:
    void on_individual_clicked();
    void on_quit_clicked();
    void on_readme_clicked();
    void on_group_clicked();

    void on_individual_pressed();
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        QPixmap pixmap("://image/home.png"); // 替换为你的图片路径
        pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);
        painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);
    }
private:
    Ui::home *ui;
};

#endif // HOME_H
