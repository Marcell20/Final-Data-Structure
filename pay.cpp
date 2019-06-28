#include "pay.h"
#include "ui_pay.h"

Pay::Pay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pay)
{
    ui->setupUi(this);
    QStringList titlerow;
    titlerow << "Name" << "Brand" << "QTY" << "Price";
    ui->TableView->setColumnCount(4);
    ui->TableView->setHorizontalHeaderLabels(titlerow);
}

Pay::~Pay()
{
    delete ui;
}

void Pay::on_Chooseitem_clicked()
{
    addpayed = new AddPay(this);
    addpayed->show();

}

void Pay::on_Home_clicked()
{
    close();
}


void Pay::on_ReloadTable_clicked()
{
    string name,brand;
    int quantity, price, total;
    total = 0;

    ui->TableView->clearContents();
    ui->TableView->setRowCount(0);
    func.delete_boughtItem();
    func.ReadItembought();
    func.readFile();
    boughtItem = func.get_boughtitem();
    int x = boughtItem.size();
    for (int i=0; i < x;i++) {
        name = boughtItem.at(i).getName();
        brand = boughtItem.at(i).getBrand();
        quantity = boughtItem.at(i).getQuantity();
        price = boughtItem.at(i).getPrice()*quantity;
        total = total+price;
        ui->TableView->insertRow(ui->TableView->rowCount());
        int colom = ui->TableView->rowCount()-1;
        ui->TableView->setItem(colom,0,new QTableWidgetItem(QString::fromStdString(name)));
        ui->TableView->setItem(colom,1,new QTableWidgetItem(QString::fromStdString(brand)));
        ui->TableView->setItem(colom,2,new QTableWidgetItem(QString::number(quantity)));
        ui->TableView->setItem(colom,3,new QTableWidgetItem(QString::number(price)));

    }
    ui->TableView->insertRow(ui->TableView->rowCount());
    int colom = ui->TableView->rowCount()-1;
    ui->TableView->setItem(colom,2,new QTableWidgetItem("Total :"));
    ui->TableView->setItem(colom,3,new QTableWidgetItem(QString::number(total)));

}

void Pay::on_Bills_clicked()
{
   ui->TableView->clearContents();
   func.delete_boughtItem();
   func.ItemWrite();
}
