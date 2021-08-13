#include "settings.h"
#include "ui_settings.h"
#include "commonvars.h"
#include "unistd.h"
#include "mainwindow.h"

//std::string difficulty;

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->DifficultyLabel->setText("Difficulty: " + difficulty);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_EasyButton_clicked()
{
    difficulty = "Easy";
    ui->DifficultyLabel->setText("Difficulty: Easy");
}

void Settings::on_HardButton_clicked()
{
    difficulty = "Hard";
    ui->DifficultyLabel->setText("Difficulty: Hard");
}

void Settings::on_BackButton_clicked()
{
    close();
    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
}
