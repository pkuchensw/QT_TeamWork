#include "readme.h"
#include "ui_readme.h"

readme::readme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::readme)
{
    ui->setupUi(this);
}

readme::~readme()
{
    delete ui;
}


