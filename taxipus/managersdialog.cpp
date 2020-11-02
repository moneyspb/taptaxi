#include "managersdialog.h"
#include "ui_managersdialog.h"

ManagersDialog::ManagersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagersDialog)
{
    ui->setupUi(this);

    load_data();
}

ManagersDialog::~ManagersDialog()
{
    delete ui;
}

void ManagersDialog::load_data()
{
    manager_repository* repo = new manager_repository();
    managers = repo->get_all();

    ui->tableWidget->setRowCount(managers.size());

    ui->tableWidget->hideColumn(0);

    auto start = managers.begin();
    int i = 0;
    while(start != managers.end())
    {
        manager* man = start->second;
       update_item(i, man);

        start++;
        i++;
    }
}

void ManagersDialog::update_item(int row, manager* man)
{
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(man->get_id())));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(man->get_fio()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(man->get_phone()));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(man->get_password()));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(man->get_is_admin())));
}

void ManagersDialog::on_pushButton_clicked()
{
    AddManagerDialog* dialog = new AddManagerDialog();
    //this->hide();
    int res = dialog->exec();
    if (res)
    {
        manager* man = dialog->get_manager();
        manager_repository* repo = new manager_repository();
        repo->add(man);

        managers.emplace(man->get_id(), man);
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
         update_item(row, man);
    }
}

void ManagersDialog::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    auto it = managers.find(id);
    manager* man = it->second;

    AddManagerDialog* dialog = new AddManagerDialog();
    dialog->set_manager(man);
    int res = dialog->exec();
    if (res)
    {
        update_item(row, man);

        manager_repository* repo = new manager_repository();
        repo->update(man);
    }
}

void ManagersDialog::on_pushButton_3_clicked()
{
    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    manager_repository* repo = new manager_repository();
    repo->remove(id);

    managers.erase(managers.find(id));
    ui->tableWidget->removeRow(row);
}
