#ifndef README_H
#define README_H

#include <QMainWindow>

namespace Ui {
class readme;
}

class readme : public QMainWindow
{
    Q_OBJECT

public:
    explicit readme(QWidget *parent = nullptr);
    ~readme();

private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::readme *ui;
};

#endif // README_H
