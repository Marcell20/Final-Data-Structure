#ifndef ADDPAY_H
#define ADDPAY_H

#include <QDialog>
#include "billingsystem.h"

namespace Ui {
class AddPay;
}

class AddPay : public QDialog
{
    Q_OBJECT

public:
    explicit AddPay(QWidget *parent = nullptr);
    ~AddPay();

private slots:
    void on_Home_clicked();

    void on_AddStock_clicked();

    void on_Search_clicked();

private:
    Ui::AddPay *ui;
    Function func;
    vector <storeFile> data;
    vector <storeFile> boughtItem;
};

#endif // ADDPAY_H
