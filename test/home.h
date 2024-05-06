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
    void on_individual_clicked();
    void on_quit_clicked();
    void on_readme_clicked();
    void on_group_clicked();

    void on_individual_pressed();

private:
    Ui::home *ui;
};

#endif // HOME_H
