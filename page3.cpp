#include "page3.h"
#include "mainwindow.h"
#include "ui_page3.h"

Page3::Page3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page3)
{
    ui->setupUi(this);
}

Page3::~Page3()
{
    delete ui;
}

void Page3::on_YesButton_clicked()
{
    close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void Page3::on_NoButton_clicked()
{
    close();
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);
    digitalWrite(4, LOW);
}

