#include "add.h"
#include "ui_add.h"


Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    func.readFile();
}

Add::~Add()
{
    on_Home_clicked();
    delete ui;
}

void Add::on_AddStock_clicked()
{
    string name = ui->name->text().toStdString();
    string brand = ui->brand->text().toStdString();
    int qty = ui->qty->text().toInt();
    int price = ui->price->text().toInt();
    func.addFile(name, brand, qty, price);
    ui->name->setText("");
    ui->brand->setText("");
    ui->qty->setText("");
    ui->price->setText("");
}


void Add::on_Home_clicked()
{
    func.fileWrite();
    close();
}
