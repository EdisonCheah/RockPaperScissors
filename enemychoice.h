#ifndef ENEMYCHOICE_H
#define ENEMYCHOICE_H

#include <QDialog>

namespace Ui {
class EnemyChoice;
}

class EnemyChoice : public QDialog
{
    Q_OBJECT

public:
    explicit EnemyChoice(QWidget *parent = nullptr);
    ~EnemyChoice();

private slots:
    void on_PvpButton_clicked();

    void on_PveButton_clicked();

private:
    Ui::EnemyChoice *ui;
};

#endif // ENEMYCHOICE_H
