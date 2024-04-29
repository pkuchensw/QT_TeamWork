#ifndef HOME_H
#define HOME_H

#include <QDialog>

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
    void on_a_clicked();
    void on_quit_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::home *ui;
};

#endif // HOME_H
