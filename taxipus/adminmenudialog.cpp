#include "adminmenudialog.h"
#include "ui_adminmenudialog.h"

AdminMenuDialog::AdminMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMenuDialog)
{
    ui->setupUi(this);

    if (!ApplicationHelper::current_manager->get_is_admin())
    {
        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(false);
    }
}

AdminMenuDialog::~AdminMenuDialog()
{
    delete ui;
}

void AdminMenuDialog::on_pushButton_4_clicked()
{
    ModelCarsDialog* dialog = new ModelCarsDialog();
    this->hide();
    int res = dialog->exec();
    this->show();

}

void AdminMenuDialog::on_pushButton_5_clicked()
{
    ManagersDialog* dialog = new ManagersDialog();
    //this->hide();
    int res = dialog->exec();
    //this->show();
}

void AdminMenuDialog::on_pushButton_3_clicked()
{
    OrdersWindow* window = new OrdersWindow(this);
    window->show();

}

void AdminMenuDialog::on_pushButton_clicked()
{
    taxistssssDialog* dialog = new taxistssssDialog();
    //this->hide();
    int res = dialog->exec();
}

void AdminMenuDialog::on_pushButton_2_clicked()
{
    clientssssDialog* window = new clientssssDialog(this);
    window->show();
}
