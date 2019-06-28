#ifndef PAY_H
#define PAY_H

#include <QDialog>
#include "addpay.h"
#include "billingsystem.h"

namespace Ui {
class Pay;
}

class Pay : public QDialog
{
    Q_OBJECT

public:
    explicit Pay(QWidget *parent = nullptr);
    ~Pay();

private slots:
    void on_Chooseitem_clicked();

    void on_ReloadTable_clicked();

    void on_Home_clicked();

    void on_Bills_clicked();

private:
    Ui::Pay *ui;
    AddPay *addpayed;
    vector <storeFile> boughtItem;
    vector <storeFile> data;
    Function func;

};

#endif // PAY_H
