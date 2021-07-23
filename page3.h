#ifndef PAGE3_H
#define PAGE3_H

#include <QDialog>

namespace Ui {
class Page3;
}

class Page3 : public QDialog
{
    Q_OBJECT

public:
    explicit Page3(QWidget *parent = nullptr);
    ~Page3();

private slots:

    void on_YesButton_clicked();

    void on_NoButton_clicked();

private:
    Ui::Page3 *ui;
};

#endif // PAGE3_H
