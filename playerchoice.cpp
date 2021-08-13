#include "playerchoice.h"
#include "ui_playerchoice.h"
#include "page2.h"
#include "pvppage.h"

PlayerChoice::PlayerChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerChoice)
{
    ui->setupUi(this);
}

PlayerChoice::~PlayerChoice()
{
    delete ui;
}

void PlayerChoice::on_PveButton_clicked()
{
    close();
    Page2 dialog;
    dialog.setModal(true);
    dialog.exec();
}

void PlayerChoice::on_PvpButton_clicked()
{
    close();
    PvpPage dialog;
    dialog.setModal(true);
    dialog.exec();
}
