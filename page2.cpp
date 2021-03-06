#include "page2.h"
#include "ui_page2.h"
#include "mainwindow.h"
#include "page3.h"
#include <QRandomGenerator>
#include "commonvars.h"
#include "nowins.h"

int user_number;
//QRandomGenerator *generator = QRandomGenerator::global();
//int comp_number = QRandomGenerator::global()->bounded(1, 4);
//bool ObjSelected = false;
//int user_wins = 0;
//int comp_wins = 0;

Page2::Page2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page2)
{
    ui->setupUi(this);
//    if (comp_number < 3)    {
//        comp_number += 1;
//    }
//    else {
//        comp_number = 1;
//    }
    ObjSelected = false;
    ui->UserVsCompLabel->setText(QString::number(user_wins) + " | " + QString::number(comp_wins));
}

Page2::~Page2()
{
    delete ui;
}

void Page2::CreateButton() {
    QPushButton *button = new QPushButton(this);
    connect(button, SIGNAL(clicked()), this, SLOT(on_button_Clicked()));
    button->setText("Continue");
    ui->ContinueLayout->addWidget(button);
    button->show();

    //if (ui->stackedWidget->currentIndex() != 1) {
        //ui->ContinueLayout->removeWidget(button);
        //ui->outcomeLabel->setText("");
    //}
}

void Page2::on_RockButton_clicked()
{
    if (ObjSelected == false)    {
        user_number = 1;
        srand(time(NULL));
        int comp_number = rand()%3+1;
        digitalWrite(18, HIGH);
        digitalWrite(22, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(4, LOW);

        if (user_number == 1 and comp_number == 1)
        {
            ui->outcomeLabel->setText("You both chose rock. It's a tie");
        }
        else if (user_number == 1 and comp_number == 2)
        {
            ui->outcomeLabel->setText("Opponent chose paper. You lost");
            comp_wins += 1;
        }
        else if (user_number == 1 and comp_number == 3)
        {
            ui->outcomeLabel->setText("Opponent chose scissors. You won!");
            user_wins += 1;
        }
        CreateButton();
        ObjSelected = true;
        ui->UserVsCompLabel->setText(QString::number(user_wins) + " | " + QString::number(comp_wins));
    }
    else    {
    }
}

void Page2::on_PaperButton_clicked()
{
    if (ObjSelected == false)   {
        user_number = 2;
        srand(time(NULL));
        int comp_number = rand()%3+1;
        digitalWrite(17, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(4, LOW);

        if (user_number == 2 and comp_number == 1)
        {
            ui->outcomeLabel->setText("Opponent chose rock. You won!");
            user_wins += 1;
        }
        else if (user_number == 2 and comp_number == 2)
        {
            ui->outcomeLabel->setText("You both chose paper. It's a tie");
        }
        else if (user_number == 2 and comp_number == 3)
        {
            ui->outcomeLabel->setText("Opponent chose scissors. You lost");
            comp_wins += 1;
        }

        CreateButton();
        ObjSelected = true;
        ui->UserVsCompLabel->setText(QString::number(user_wins) + " | " + QString::number(comp_wins));
    }
    else    {
    }
}

void Page2::on_ScissorsButton_clicked()
{
    if (ObjSelected == false)   {
        user_number = 3;
        srand(time(NULL));
        int comp_number = rand()%3+1;
        digitalWrite(4, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(17, LOW);

        if (user_number == 3 and comp_number == 1)
        {
            ui->outcomeLabel->setText("Opponent chose rock. You lost");
            comp_wins += 1;
        }
        else if (user_number == 3 and comp_number == 2)
        {
            ui->outcomeLabel->setText("Opponent chose paper. You won!");
            user_wins += 1;
        }
        else if (user_number == 3 and comp_number == 3)
        {
            ui->outcomeLabel->setText("You both chose scissors. It's a tie");
        }

        CreateButton();
        ObjSelected = true;
        ui->UserVsCompLabel->setText(QString::number(user_wins) + " | " + QString::number(comp_wins));
    }
    else {
    }
}

void Page2::on_button_Clicked()    {
//    ui->stackedWidget->setCurrentIndex(2);
    close();
    Page3 dialog;
    dialog.setModal(true);
    dialog.exec();
}

void Page2::on_ResetButton_clicked()
{
    if (user_wins > 0)  {
        user_wins = 0;
        comp_wins = 0;
        ui->UserVsCompLabel->setText("0 | 0");
    }
    else {
        NoWins dialog;
        dialog.setModal(true);
        dialog.exec();
    }
}
