#include "orderswindow.h"
#include "ui_orderswindow.h"

OrdersWindow::OrdersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrdersWindow)
{
    ui->setupUi(this);

    load_data();
}

OrdersWindow::~OrdersWindow()
{
    delete ui;
}

void OrdersWindow::load_data()
{
    order_repository* repo = new order_repository();
    orders = repo->get_all();

    //ui->tableWidget->setRowCount(orders.size());

    ui->tableWidget->hideColumn(0);

    /*auto start = orders.begin();
    int i = 0;
    while(start != orders.end())
    {
        order* ord = start->second;
       update_item(i, ord);

        start++;
        i++;
    }*/

    on_comboBox_currentIndexChanged(0);
}

void OrdersWindow::update_item(int row, order* ord)
{
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(ord->get_id())));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(ord->get_client()->get_fio()));
    if (ord->get_taxist() != nullptr)
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(ord->get_taxist()->get_fio()));
    else
         ui->tableWidget->setItem(row, 2, new QTableWidgetItem(""));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(ord->get_date().toString()));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(ord->get_from_place()));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(ord->get_to_place()));
    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(ord->get_cost())));
    ui->tableWidget->setItem(row, 7, new QTableWidgetItem(statusToString(ord->get_status())));

}

QString OrdersWindow::statusToString(status_order status)
{
    if (status == New)
        return "Новый";
    else if (status == Assigned)
        return "Назначенный";
    else if (status == Accepted)
        return "Пассажира забрали";
    else if (status == Completed)
        return "Поездка завершена";
    else if (Canceled == Completed)
        return "Поездка отменена";
    else
        return "Клиент пропал";
}

void OrdersWindow::on_pushButtonCreate_clicked()
{
    orderDialog* dialog = new orderDialog();
    int res = dialog->exec();
    if (res)
    {
        order* ord = dialog->get_order();
        order_repository* repo = new order_repository();
        repo->add(ord);

        orders.emplace(ord->get_id(), ord);
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        update_item(row, ord);
    }
}

void OrdersWindow::on_pushButtonEdit_clicked()
{
    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    auto it = orders.find(id);
    order* ord = it->second;

     orderDialog* dialog = new orderDialog();
    dialog->set_order(ord);
    int res = dialog->exec();
    if (res)
    {
        update_item(row, ord);

        order_repository* repo = new order_repository();
        repo->update(ord);
    }
}

void OrdersWindow::change_status(status_order status)
{
    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    auto it = orders.find(id);
    order* ord = it->second;
    ord->set_status(status);

    update_item(row, ord);
    order_repository* repo = new order_repository();
    repo->update(ord);
}

void OrdersWindow::on_action_triggered()
{
    change_status(Accepted);
}

void OrdersWindow::on_action_2_triggered()
{
    change_status(Completed);
}

void OrdersWindow::on_action_3_triggered()
{
    change_status(Canceled);
}

void OrdersWindow::on_action_4_triggered()
{
    change_status(Failed);
}

void OrdersWindow::on_comboBox_currentIndexChanged(int index)
{
    status_order status = (status_order)index;

    ui->tableWidget->setRowCount(0);
    auto start = orders.begin();
    int i = 0;
    while(start != orders.end())
    {
        order* ord = start->second;
        if (ord->get_status() == status)
        {
             ui->tableWidget->setRowCount(i+1);

             update_item(i, ord);
             i++;
        }

        start++;
    }


}
