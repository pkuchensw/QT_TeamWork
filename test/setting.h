#ifndef SETTING_H
#define SETTING_H

#include <QDialog>

namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    int initial_num;
    explicit setting(QWidget *parent = nullptr);
    ~setting();

private slots:
    void on_initial_num_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::setting *ui;
};

#endif // SETTING_H
