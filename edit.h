#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include "billingsystem.h"

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    ~edit();

private slots:
    void on_Home_clicked();

    void on_Edit_clicked();

    void on_Search_clicked();
    
private:
    Ui::edit *ui;
    Function func;
    vector <storeFile> data;

};

#endif // EDIT_H
