#include "enemychoice.h"
#include "ui_enemychoice.h"
#include "commonvars.h"
#include "page2.h"
#include "page2easy.h"
#include "pvp.h"

EnemyChoice::EnemyChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnemyChoice)
{
    ui->setupUi(this);
}

EnemyChoice::~EnemyChoice()
{
    delete ui;
}


void EnemyChoice::on_PvpButton_clicked()
{
    close();
    PvP dialog;
    dialog.setModal(true);
    dialog.exec();
}

void EnemyChoice::on_PveButton_clicked()
{
    if (difficulty == "Easy")   {
        close();
        Page2Easy dialog;
        dialog.setModal(true);
        dialog.exec();
    }
    else if (difficulty == "Hard")  {
        close();
        Page2 dialog;
        dialog.setModal(true);
        dialog.exec();
    }
}
