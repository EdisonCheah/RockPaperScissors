#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unistd.h"
#include <QRandomGenerator>
#include <QtGlobal>
#include "random"
#include "chrono"
#include "page2.h"
#include "commonvars.h"

//int user_number;
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//std::default_random_engine generator(seed);
//std::uniform_int_distribution<int> distributionInteger(1, 3);
//int comp_number = distributionInteger(generator);
//int user_number;
//static int wins = 0;
//QRandomGenerator *generator = QRandomGenerator::global();
//int comp_number = QRandomGenerator::global()->bounded(1, 4);

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
    ui->outcomeLabel->setText("");
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);
    digitalWrite(4, LOW);
    //QRandomGenerator::global()->seed(time(NULL));
    //QString winString = QString("Wins: %1").arg(wins);
    ui->winsLabel->setText("Wins: " + QString::number(wins));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlayButton_clicked()
{
//    ui->stackedWidget->setCurrentIndex(1);
    close();
    Page2 dialog;
    dialog.setModal(true);
    dialog.exec();
}

//void MainWindow::CreateButton() {
//    QPushButton *button = new QPushButton(this);
//    connect(button, SIGNAL(clicked()), this, SLOT(on_button_Clicked()));
//    button->setText("Continue");
//    ui->ContinueLayout->addWidget(button);
//    button->show();

//    //if (ui->stackedWidget->currentIndex() != 1) {
//        //ui->ContinueLayout->removeWidget(button);
//        //ui->outcomeLabel->setText("");
//    //}
//}

//void MainWindow::on_RockButton_clicked()
//{
//    user_number = 1;
//    digitalWrite(18, HIGH);
//    digitalWrite(17, LOW);
//    digitalWrite(4, LOW);

//    if (user_number == 1 and comp_number == 1)
//    {
//        ui->outcomeLabel->setText("You both chose rock. It's a tie");
//    }
//    else if (user_number == 1 and comp_number == 2)
//    {
//        ui->outcomeLabel->setText("Opponent chose paper. You lost");
//    }
//    else if (user_number == 1 and comp_number == 3)
//    {
//        ui->outcomeLabel->setText("Opponent chose scissors. You won!");
//        wins += 1;
//    }

//    CreateButton();
//}

//void MainWindow::on_PaperButton_clicked()
//{
//    user_number = 2;
//    digitalWrite(17, HIGH);
//    digitalWrite(18, LOW);
//    digitalWrite(4, LOW);

//    if (user_number == 2 and comp_number == 1)
//    {
//        ui->outcomeLabel->setText("Opponent chose rock. You won!");
//        wins += 1;
//    }
//    else if (user_number == 2 and comp_number == 2)
//    {
//        ui->outcomeLabel->setText("You both chose paper. It's a tie");
//    }
//    else if (user_number == 2 and comp_number == 3)
//    {
//        ui->outcomeLabel->setText("Opponent chose scissors. You lost");
//    }

//    CreateButton();
//}

//void MainWindow::on_ScissorsButton_clicked()
//{
//    user_number = 3;
//    digitalWrite(4, HIGH);
//    digitalWrite(18, LOW);
//    digitalWrite(17, LOW);

//    if (user_number == 3 and comp_number == 1)
//    {
//        ui->outcomeLabel->setText("Opponent chose rock. You lost");
//    }
//    else if (user_number == 3 and comp_number == 2)
//    {
//        ui->outcomeLabel->setText("Opponent chose paper. You won!");
//        wins += 1;
//    }
//    else if (user_number == 3 and comp_number == 3)
//    {
//        ui->outcomeLabel->setText("You both chose scissors. It's a tie");
//    }

//    CreateButton();
//}

//void MainWindow::on_button_Clicked()    {
//    ui->stackedWidget->setCurrentIndex(2);
//}

//void MainWindow::on_YesButton_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWindow::on_NoButton_clicked()
//{
//    close();
//    digitalWrite(17, LOW);
//    digitalWrite(18, LOW);
//    digitalWrite(4, LOW);
//}

void MainWindow::on_CloseButton_clicked()
{
    close();
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);
    digitalWrite(4, LOW);
}
