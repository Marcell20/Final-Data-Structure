#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "billingsystem.h"

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

private slots:
    void on_AddStock_clicked();

    void on_Home_clicked();

private:
    Ui::Add *ui;
    Function func;
};

#endif // ADD_H
