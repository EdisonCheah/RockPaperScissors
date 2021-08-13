#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wiringPi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //int wins;

private slots:
    void on_PlayButton_clicked();

//    void on_YesButton_clicked();

//    void on_NoButton_clicked();

    void on_CloseButton_clicked();

//    void on_RockButton_clicked();

//    void on_PaperButton_clicked();

//    void on_ScissorsButton_clicked();

//    void on_button_Clicked();

    void on_SettingsButton_clicked();

private:
    Ui::MainWindow *ui;
    void CreateButton();
};

#endif // MAINWINDOW_H
