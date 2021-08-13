#include "page2easy.h"
#include "ui_page2easy.h"
#include <QRandomGenerator>
#include "commonvars.h"
#include "nowins.h"
#include "page3.h"
#include "mainwindow.h"
#include "page2.h"

int user_number_easy;
QRandomGenerator *generator = QRandomGenerator::global();
int comp_number_easy = QRandomGenerator::global()->bounded(1, 4);
//bool ObjSelected = false;

Page2Easy::Page2Easy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page2Easy)
{
    ui->setupUi(this);
        if (comp_number_easy < 3)    {
            comp_number_easy += 1;
        }
        else {
            comp_number_easy = 1;
        }
        ObjSelected = false;
        ui->UserVsCompLabel->setText(QString::number(user_wins) + " | " + QString::number(comp_wins));
}

Page2Easy::~Page2Easy()
{
    delete ui;
}

void Page2Easy::CreateButton() {
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

void Page2Easy::on_RockButton_clicked()
{
    if (ObjSelected == false)    {
        user_number_easy = 1;
        digitalWrite(18, HIGH);
        digitalWrite(22, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(4, LOW);

        if (user_number_easy == 1 and comp_number_easy == 1)
        {
            ui->outcomeLabel->setText("You both chose rock. It's a tie");
        }
        else if (user_number_easy == 1 and comp_number_easy == 2)
        {
            ui->outcomeLabel->setText("Opponent chose paper. You lost");
            comp_wins += 1;
        }
        else if (user_number_easy == 1 and comp_number_easy == 3)
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

void Page2Easy::on_PaperButton_clicked()
{
    if (ObjSelected == false)   {
        user_number_easy = 2;
        digitalWrite(17, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(4, LOW);

        if (user_number_easy == 2 and comp_number_easy == 1)
        {
            ui->outcomeLabel->setText("Opponent chose rock. You won!");
            user_wins += 1;
        }
        else if (user_number_easy == 2 and comp_number_easy == 2)
        {
            ui->outcomeLabel->setText("You both chose paper. It's a tie");
        }
        else if (user_number_easy == 2 and comp_number_easy == 3)
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

void Page2Easy::on_ScissorsButton_clicked()
{
    if (ObjSelected == false)   {
        user_number_easy = 3;
        digitalWrite(4, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(17, LOW);

        if (user_number_easy == 3 and comp_number_easy == 1)
        {
            ui->outcomeLabel->setText("Opponent chose rock. You lost");
            comp_wins += 1;
        }
        else if (user_number_easy == 3 and comp_number_easy == 2)
        {
            ui->outcomeLabel->setText("Opponent chose paper. You won!");
            user_wins += 1;
        }
        else if (user_number_easy == 3 and comp_number_easy == 3)
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

void Page2Easy::on_button_Clicked()    {
//    ui->stackedWidget->setCurrentIndex(2);
    close();
    Page3 dialog;
    dialog.setModal(true);
    dialog.exec();
}

void Page2Easy::on_ResetButton_clicked()
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
