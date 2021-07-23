#ifndef PAGE2_H
#define PAGE2_H

#include <QDialog>

namespace Ui {
class Page2;
}

class Page2 : public QDialog
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = nullptr);
    ~Page2();


private slots:

    void on_RockButton_clicked();

    void on_PaperButton_clicked();

    void on_ScissorsButton_clicked();

    void on_button_Clicked();

private:
    Ui::Page2 *ui;
    void CreateButton();
};

#endif // PAGE2_H
