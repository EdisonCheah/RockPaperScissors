#ifndef NOWINS_H
#define NOWINS_H

#include <QDialog>

namespace Ui {
class NoWins;
}

class NoWins : public QDialog
{
    Q_OBJECT

public:
    explicit NoWins(QWidget *parent = nullptr);
    ~NoWins();

private slots:
    void on_OkButton_clicked();

private:
    Ui::NoWins *ui;
};

#endif // NOWINS_H
