#include "taptaxi.h"
#include "ui_taptaxi.h"

TapTaxi::TapTaxi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TapTaxi)
{
    ui->setupUi(this);
}

TapTaxi::~TapTaxi()
{
    delete ui;
}

manager* ApplicationHelper::current_manager = nullptr;
client* ApplicationHelper::current_client = nullptr;

void TapTaxi::on_pushButton_2_clicked()
{
    ApplicationHelper::current_client = nullptr;
    ApplicationHelper::current_manager  = nullptr;

    person_repository* per_repo = new person_repository();
    int countPerson = per_repo->count_person();
    if (countPerson == 0)
    {
        AdminMenuDialog* dialog = new AdminMenuDialog();
        this->hide();
        int res = dialog->exec();
        this->show();
    }
    else
    {
        client_repository* repo = new client_repository();
        QString phone = ui->lineEditPhone->text();
        QString password = ui->lineEditPassword->text();
        client* cl = repo->find(phone, password);
        if (cl != nullptr)
        {
            ApplicationHelper::current_client = cl;

            orderDialog* dialog = new orderDialog();
            this->hide();
            int res = dialog->exec();
            if (res)
            {
                order* ord = dialog->get_order();
                order_repository* repo = new order_repository();
                repo->add(ord);
            }
            this->show();
        }
        else
        {
            manager_repository* manager_repo = new manager_repository();
            manager* man = manager_repo->find(phone, password);

            if (man != nullptr)
            {
                ApplicationHelper::current_manager = man;

                AdminMenuDialog* dialog = new AdminMenuDialog();
                this->hide();
                int res = dialog->exec();
                this->show();
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Неверный номер телефона или пароль.");
                msgBox.exec();
            }
        }
    }
}

void TapTaxi::on_pushButton_clicked()
{
    AddClientDialog* dialog = new AddClientDialog();
    int res = dialog->exec();
    if (res)
    {
        client* cli = dialog->get_client();
        client_repository* repo = new client_repository();
        repo->add(cli);
    }
}
