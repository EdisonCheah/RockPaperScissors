#include "pvp.h"
#include "ui_pvp.h"
#include "commonvars.h"
#include "mainwindow.h"
#include "nowins.h"
#include "page3.h"
#include <QKeyEvent>
#include "time.h"

int player1_number;
int player2_number;
int player1_wins = 0;
int player2_wins = 0;
bool CheckSelected = false;
bool KeySelected = false;

PvP::PvP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PvP)
{
    ui->setupUi(this);
    ObjSelected = false;
    CheckSelected = false;
    ui->UserVsCompLabel->setText(QString::number(player1_wins) + " | " + QString::number(player2_wins));
}

PvP::~PvP()
{
    delete ui;
}

void PvP::CreateButton() {
    QPushButton *button = new QPushButton(this);
    connect(button, SIGNAL(clicked()), this, SLOT(on_button_Clicked()));
    button->setText("Continue");
    ui->ContinueLayout->addWidget(button);
    button->show();
}

void PvP::keyPressEvent(QKeyEvent *e)    {
    if (e->key() == Qt::Key_1)  {
        player2_number = 1;
    }
    else if (e->key() == Qt::Key_2) {
        player2_number = 2;
    }
    else if (e->key() == Qt::Key_3) {
        player2_number = 3;
    }
    KeySelected = true;
}

void PvP::on_RockButton_clicked()
{
    if (ObjSelected == false)    {
        player1_number = 1;
        digitalWrite(18, HIGH);
        digitalWrite(22, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(4, LOW);
        ObjSelected = true;
    }
    else    {
    }
}

void PvP::on_PaperButton_clicked()
{
    if (ObjSelected == false)   {
        player1_number = 2;
        digitalWrite(17, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(4, LOW);
        ObjSelected = true;
    }
    else    {
    }
}

void PvP::on_ScissorsButton_clicked()
{
    if (ObjSelected == false)   {
        player1_number = 3;
        digitalWrite(4, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(17, LOW);
        ObjSelected = true;
    }
    else {
    }
}

void PvP::on_button_Clicked()    {
    close();
    Page3 dialog;
    dialog.setModal(true);
    dialog.exec();
}

void PvP::on_ResetButton_clicked()
{
    if (player1_wins > 0)  {
        player1_wins = 0;
        player2_wins = 0;
        ui->UserVsCompLabel->setText("0 | 0");
    }
    else {
        NoWins dialog;
        dialog.setModal(true);
        dialog.exec();
    }
}

void PvP::on_CheckButton_clicked()
{
    if (CheckSelected == false and ObjSelected == true and KeySelected == true) {
        if (player1_number == 1 and player2_number == 1)
        {
            ui->outcomeLabel->setText("You both chose rock. It's a tie");
        }
        else if (player1_number == 1 and player2_number == 2)
        {
            ui->outcomeLabel->setText("Opponent chose paper. You lost");
            player2_wins += 1;
        }
        else if (player1_number == 1 and player2_number == 3)
        {
            ui->outcomeLabel->setText("Opponent chose scissors. You won!");
            player1_wins += 1;
        }
        else if (player1_number == 2 and player2_number == 1)
        {
            ui->outcomeLabel->setText("Opponent chose rock. You won!");
            player1_wins += 1;
        }
        else if (player1_number == 2 and player2_number == 2)
        {
            ui->outcomeLabel->setText("You both chose paper. It's a tie");
        }
        else if (player1_number == 2 and player2_number == 3)
        {
            ui->outcomeLabel->setText("Opponent chose scissors. You lost");
            player2_wins += 1;
        }
        else if (player1_number == 3 and player2_number == 1)
        {
            ui->outcomeLabel->setText("Opponent chose rock. You lost");
            player2_wins += 1;
        }
        else if (player1_number == 3 and player2_number == 2)
        {
            ui->outcomeLabel->setText("Opponent chose paper. You won!");
            player1_wins += 1;
        }
        else if (player1_number == 3 and player2_number == 3)
        {
            ui->outcomeLabel->setText("You both chose scissors. It's a tie");
        }
        CreateButton();
        ui->UserVsCompLabel->setText(QString::number(player1_wins) + " | " + QString::number(player2_wins));
        CheckSelected = true;
    }
    else if (KeySelected == false or ObjSelected == false)  {
        ui->outcomeLabel->setText("Error: Not all players have selected!");
    }
    else {
    }
}
