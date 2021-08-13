#ifndef PAGE2EASY_H
#define PAGE2EASY_H

#include <QDialog>

namespace Ui {
class Page2Easy;
}

class Page2Easy : public QDialog
{
    Q_OBJECT

public:
    explicit Page2Easy(QWidget *parent = nullptr);
    ~Page2Easy();

private slots:

    void on_RockButton_clicked();

    void on_PaperButton_clicked();

    void on_ScissorsButton_clicked();

    void on_button_Clicked();

    void on_ResetButton_clicked();

private:
    Ui::Page2Easy *ui;
    void CreateButton();
};

#endif // PAGE2EASY_H
