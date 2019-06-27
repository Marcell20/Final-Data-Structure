#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pay.h"
#include "add.h"
#include "edit.h"
#include "billingsystem.h"
#include "vector"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_PayButton_clicked();

    void on_AddButton_clicked();

    void on_EditButton_clicked();

    void on_ReloadTable_clicked();

private:
    Function func;
    vector <storeFile> data;
    vector <storeFile> boughtItem;

    Ui::MainWindow *ui;

    Pay *payed;
    Add *added;
    edit *edited;

};

#endif // MAINWINDOW_H
