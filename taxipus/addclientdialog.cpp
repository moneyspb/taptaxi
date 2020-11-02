#include "addclientdialog.h"
#include "ui_addclientdialog.h"

AddClientDialog::AddClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);

    cl = nullptr;
}

AddClientDialog::~AddClientDialog()
{
    delete ui;
}

client* AddClientDialog::get_client()
{
    return cl;
}

void AddClientDialog::set_client(client *cl)
{
    this->cl = cl;

    ui->lineEditFIO->setText(cl->get_fio());
    ui->lineEditPhone->setText(cl->get_phone());
    ui->lineEditPassword->setText(cl->get_password());
    ui->lineEditReputation->setText(QString::number(cl->get_reputation()));
}

void AddClientDialog::on_buttonBox_accepted()
{
    if (cl == nullptr)
        cl = new client();
    cl->set_fio(ui->lineEditFIO->text());
    cl->set_phone(ui->lineEditPhone->text());
    cl->set_password(ui->lineEditPassword->text());
    cl->set_reputation(ui->lineEditReputation->text().toDouble());
}
