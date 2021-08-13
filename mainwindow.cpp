#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unistd.h"
#include <QRandomGenerator>
#include <QtGlobal>
#include "random"
#include "chrono"
#include "page2.h"
#include "commonvars.h"
#include "settings.h"
#include "page2easy.h"
#include "enemychoice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    wiringPiSetupGpio();
    pinMode(18, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(22, OUTPUT);
    ui->outcomeLabel->setText("");
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);
    digitalWrite(4, LOW);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlayButton_clicked()
{
    close();
    EnemyChoice dialog;
    dialog.setModal(true);
    dialog.exec();
    }


void MainWindow::on_CloseButton_clicked()
{
    close();
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);
    digitalWrite(4, LOW);
}

void MainWindow::on_SettingsButton_clicked()
{
    close();
    Settings dialog;
    dialog.setModal(true);
    dialog.exec();
}
