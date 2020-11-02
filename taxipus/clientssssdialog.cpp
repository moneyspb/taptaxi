#include "clientssssdialog.h"
#include "ui_clientssssdialog.h"


clientssssDialog::clientssssDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientssssDialog)
{
    ui->setupUi(this);
   load_data();

   if (!ApplicationHelper::current_manager->get_is_admin())
   {
       ui->pushButton_3->setVisible(false);
   }
}

clientssssDialog::~clientssssDialog()
{
    delete ui;
}

void clientssssDialog::load_data()
{
    client_repository* repo = new client_repository();
    clients = repo->get_all();

    ui->tableWidget->setRowCount(clients.size());

    ui->tableWidget->hideColumn(0);

    auto start = clients.begin();
    int i = 0;
    while(start != clients.end())
    {
        client* cl = start->second;
       update_item(i, cl);

        start++;
        i++;
    }
}

void clientssssDialog::update_item(int row, client* cl)
{
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(cl->get_id())));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(cl->get_fio()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(cl->get_phone()));
      ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(cl->get_reputation())));
}

void clientssssDialog::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row != -1)
    {
        int id = ui->tableWidget->item(row, 0)->text().toInt();

        auto it = clients.find(id);
        client* cl = it->second;

        AddClientDialog* dialog = new AddClientDialog();
        dialog->set_client(cl);
        int res = dialog->exec();
        if (res)
        {
            update_item(row, cl);

            client_repository* repo = new client_repository();
            repo->update(cl);
        }
    }
}

void clientssssDialog::on_pushButton_3_clicked()
{
    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    client_repository* repo = new client_repository();
    repo->remove(id);

    clients.erase(clients.find(id));
    ui->tableWidget->removeRow(row);
}


void clientssssDialog::on_pushButton_clicked()
{
    AddClientDialog* dialog = new AddClientDialog();
    int res = dialog->exec();
    if (res)
    {
        client* cli = dialog->get_client();
        client_repository* repo = new client_repository();
        repo->add(cli);

        clients.emplace(cli->get_id(), cli);
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        update_item(row, cli);
    }
}
