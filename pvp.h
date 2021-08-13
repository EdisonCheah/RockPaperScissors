#ifndef PVP_H
#define PVP_H

#include <QDialog>

namespace Ui {
class PvP;
}

class PvP : public QDialog
{
    Q_OBJECT

public:
    explicit PvP(QWidget *parent = nullptr);
    ~PvP();

protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void on_RockButton_clicked();

    void on_PaperButton_clicked();

    void on_ScissorsButton_clicked();

    void on_button_Clicked();

    void on_ResetButton_clicked();

    void on_CheckButton_clicked();

private:
    Ui::PvP *ui;
    void CreateButton();
};

#endif // PVP_H
