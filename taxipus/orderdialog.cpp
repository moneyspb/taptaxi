#include "orderdialog.h"
#include "ui_orderdialog.h"

orderDialog::orderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::orderDialog)
{
    ui->setupUi(this);

    ord = nullptr;

    ui->dateTimeEdit->setDisabled(true);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    ui->comboBoxClient->setModel(new BaseComboModel("fio", "client INNER JOIN person on  person.id = client.id", this));
    ui->comboBoxDriver->setModel(new BaseComboModel("fio", "taxist INNER JOIN person on  person.id = taxist.id", this));

    if (ApplicationHelper::current_client != nullptr)
    {
        int size = ui->comboBoxClient->model()->rowCount();
        for (int i = 0; i < size; i++){
            QModelIndex cur= ui->comboBoxClient->model()->index(i, 0);
            int id = cur.data(Qt::UserRole).toInt();
            if (id == ApplicationHelper::current_client->get_id()){
                ui->comboBoxClient->setCurrentIndex(cur.row());
                break;
            }
        }

        ui->comboBoxDriver->setDisabled(true);
        ui->comboBoxClient->setDisabled(true);
    }
}

orderDialog::~orderDialog()
{
    delete ui;
}

void orderDialog::set_order(order* ord)
{
    this->ord = ord;

    ui->lineEditTo->setText(ord->get_to_place());
    ui->lineEditFrom->setText(ord->get_from_place());
    ui->lineEditCost->setText(QString::number(ord->get_cost()));
    ui->dateTimeEdit->setDateTime(ord->get_date());
    ui->comboBoxTariff->setCurrentIndex(ord->get_tariff());

    int size = ui->comboBoxClient->model()->rowCount();
    for (int i = 0; i < size; i++){
        QModelIndex cur= ui->comboBoxClient->model()->index(i, 0);
        int id = cur.data(Qt::UserRole).toInt();
        if (id == ord->get_client()->get_id()){
            ui->comboBoxClient->setCurrentIndex(cur.row());
            break;
        }
    }

    if (ord->get_taxist() != nullptr)
    {
        int size2 = ui->comboBoxDriver->model()->rowCount();
        for (int i = 0; i < size2; i++){
            QModelIndex cur= ui->comboBoxDriver->model()->index(i, 0);
            int id = cur.data(Qt::UserRole).toInt();
            if (id == ord->get_taxist()->get_id()){
                ui->comboBoxDriver->setCurrentIndex(cur.row());
                break;
            }
        }
    }

    changed = false;
}

void orderDialog::accept()
{
    if (ui->comboBoxClient->currentIndex() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Укажите клиента");
        msgBox.exec();
        check = false;
    }
    else
    {
        check = true;
        QDialog::accept();
    }
}

void orderDialog::set_client(client* cl)
{
    this->cl = cl;
}

void orderDialog::on_buttonBox_accepted()
{
    if (!check)
        return;

    if (ord == nullptr)
        ord = new order();
    ord->set_cost(ui->lineEditCost->text().toDouble());
    ord->set_date(ui->dateTimeEdit->dateTime());

    ord->set_to_place(ui->lineEditTo->text());
    ord->set_from_place(ui->lineEditFrom->text());
    ord->set_tariff((Tarif)ui->comboBoxTariff->currentIndex());

    QVariant var =  ui->comboBoxClient->model()->data(ui->comboBoxClient->model()->index(ui->comboBoxClient->currentIndex(), 0), Qt::UserRole);
    int idClient =  var.toInt();
    client_repository* repoClients = new client_repository();
     client* cli = repoClients->get_all().find(idClient)->second;

     int index_driver = ui->comboBoxDriver->currentIndex();
     if (index_driver != 0)
     {
         QVariant varDriver =  ui->comboBoxDriver->model()->data(ui->comboBoxDriver->model()->index(index_driver, 0), Qt::UserRole);
         int idDriver =  varDriver.toInt();
         taxist_repository* repoTaxs = new taxist_repository();
          taxist* tax = repoTaxs->get_all().find(idDriver)->second;
          ord->set_taxist(tax);
           ord->set_status(Assigned);
     }
     else
     {
         ord->set_taxist(nullptr);
          ord->set_status(New);
     }

      ord->set_client(cli);
}

void orderDialog::on_pushButtonCost_clicked()
{
    if (changed)
    {
        int distance = rand() % 20 + 2;
        int prob = rand() % 10;
        Tarif tariff = (Tarif)ui->comboBoxTariff->currentIndex();

        int cost = cost_trip(distance, tariff, prob);
        ui->lineEditCost->setText(QString::number(cost));
        changed = false;
    }
}

void orderDialog::on_lineEditFrom_textChanged(const QString &arg1)
{
    changed = true;
}

void orderDialog::on_lineEditTo_textChanged(const QString &arg1)
{
    changed = true;
}

void orderDialog::on_comboBoxTariff_currentIndexChanged(int index)
{
    changed = true;
}
