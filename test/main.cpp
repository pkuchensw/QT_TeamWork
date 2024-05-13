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

int main(int argc, char *argv[]) {
    srand(time(0));
    QApplication app(argc, argv);



    home Home;
    //Home.show();
    Home.showFullScreen();

    return app.exec();
}
