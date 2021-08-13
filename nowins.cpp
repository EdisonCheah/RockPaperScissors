#include "nowins.h"
#include "ui_nowins.h"
#include "commonvars.h"

NoWins::NoWins(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoWins)
{
    ui->setupUi(this);
}

NoWins::~NoWins()
{
    delete ui;
}

void NoWins::on_OkButton_clicked()
{
    close();
}
