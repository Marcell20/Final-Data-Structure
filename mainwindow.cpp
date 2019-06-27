#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList titlerow;
    titlerow << "Name" << "Brand" << "QTY" << "Price";
    ui->ListTable->setColumnCount(4);
    ui->ListTable->setHorizontalHeaderLabels(titlerow);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PayButton_clicked()
{
    payed= new Pay(this);
    payed->show();
}

void MainWindow::on_AddButton_clicked()
{
    added = new Add(this);
    added->show();
}

void MainWindow::on_EditButton_clicked()
{
    edited = new edit(this);
    edited->show();
}

void MainWindow::on_ReloadTable_clicked()
{
    string name,brand;
    int quantity, price;

    ui->ListTable->clearContents();
    ui->ListTable->setRowCount(0);
    func.delete_data();
    func.readFile();
    data = func.get_data();
    for(int i=0; i<data.size(); i++){
        name = data.at(i).getName();
        brand = data.at(i).getBrand();
        quantity = data.at(i).getQuantity();
        price = data.at(i).getPrice();
        ui->ListTable->insertRow(ui->ListTable->rowCount());
        int colom = ui->ListTable->rowCount()-1;
        ui->ListTable->setItem(colom,0,new QTableWidgetItem(QString::fromStdString(name)));
        ui->ListTable->setItem(colom,1,new QTableWidgetItem(QString::fromStdString(brand)));
        ui->ListTable->setItem(colom,2,new QTableWidgetItem(QString::number(quantity)));
        ui->ListTable->setItem(colom,3,new QTableWidgetItem(QString::number(price)));
        }
}
