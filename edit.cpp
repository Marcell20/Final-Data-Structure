#include "edit.h"
#include "ui_edit.h"

edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
    QStringList titlerow;
    titlerow << "Name" << "QTY" << "Price";
    ui->Table->setColumnCount(3);
    ui->Table->setHorizontalHeaderLabels(titlerow);
    func.readFile();
}

edit::~edit()
{
    delete ui;
}

void edit::on_Home_clicked()
{
    close();
    func.fileWrite();
}

void edit::on_Edit_clicked()
{
    string name = ui->Editname->text().toStdString();
    int qty = ui->Editqty->text().toInt();
    int price = ui->Editprice->text().toInt();
    func.editFile(name,qty,price);
    ui->Editname->setText("");
    ui->Editqty->setText("");
    ui->Editprice->setText("");
    ui->Table->clearContents();
    ui->Table->setRowCount(0);
}

void edit::on_Search_clicked()
{
    ui->Table->clearContents();
    ui->Table->setRowCount(0);
    func.delete_data();
    func.readFile();
    data = func.get_data();
    string name = ui->Editname->text().toStdString();
    ui->Table->insertRow(ui->Table->rowCount());
    int colom = ui->Table->rowCount()-1;
    int qty = func.search(name);
    int price = func.search1(name);
    ui->Table->setItem(colom,0,new QTableWidgetItem(QString::fromStdString(name)));
    ui->Table->setItem(colom,1,new QTableWidgetItem(QString::number(qty)));
    ui->Table->setItem(colom,2,new QTableWidgetItem(QString::number(price)));

}
