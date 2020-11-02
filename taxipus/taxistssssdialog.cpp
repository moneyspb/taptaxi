#include "taxistssssdialog.h"
#include "ui_taxistssssdialog.h"
#include "taxist.h"
#include "taxist_repository.h"
taxistssssDialog::taxistssssDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::taxistssssDialog)
{
    ui->setupUi(this);
    load_data();

    if (!ApplicationHelper::current_manager->get_is_admin())
    {
        ui->pushButtonEdit->setVisible(false);
        ui->pushButtonCreate->setVisible(false);
        ui->pushButtonDelete->setVisible(false);

    }
}

taxistssssDialog::~taxistssssDialog()
{
    delete ui;
}

void taxistssssDialog::load_data()
{
    taxist_repository* repo = new taxist_repository();
    taxists = repo->get_all();

    ui->tableWidget->setRowCount(taxists.size());

    ui->tableWidget->hideColumn(0);

    auto start = taxists.begin();
    int i = 0;
    while(start != taxists.end())
    {
        taxist* tax = start->second;
       update_item(i, tax);

        start++;
        i++;
    }
}

void taxistssssDialog::update_item(int row, taxist* tax)
{
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(tax->get_id())));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(tax->get_fio()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(tax->get_phone()));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(tax->get_model_car()->get_name()));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(tax->get_number_car()));
     ui->tableWidget->setItem(row, 5, new QTableWidgetItem(tax->get_color()));
      ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(tax->get_reputation())));
}

void taxistssssDialog::on_pushButtonCreate_clicked()
{
    AddTaxistDialog* dialog = new AddTaxistDialog();
    int res = dialog->exec();
    if (res)
    {
        taxist* tax = dialog->get_taxist();
        taxist_repository* repo = new taxist_repository();
        repo->add(tax);

        taxists.emplace(tax->get_id(), tax);
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        update_item(row, tax);
    }
}

void taxistssssDialog::on_pushButtonEdit_clicked()
{
    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    auto it = taxists.find(id);
    taxist* tax = it->second;

    AddTaxistDialog* dialog = new AddTaxistDialog();
    dialog->set_taxist(tax);
    int res = dialog->exec();
    if (res)
    {
        update_item(row, tax);

        taxist_repository* repo = new taxist_repository();
        repo->update(tax);
    }
}

void taxistssssDialog::on_pushButtonDelete_clicked()
{
    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    taxist_repository* repo = new taxist_repository();
    repo->remove(id);

    taxists.erase(taxists.find(id));
    ui->tableWidget->removeRow(row);
}
