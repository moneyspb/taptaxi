#include "addmanagerdialog.h"
#include "ui_addmanagerdialog.h"

AddManagerDialog::AddManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddManagerDialog)
{
    ui->setupUi(this);

    this->man = nullptr;
}

AddManagerDialog::~AddManagerDialog()
{
    delete ui;
}

manager* AddManagerDialog::get_manager()
{
    return man;
}

void AddManagerDialog::set_manager(manager* man)
{
    this->man = man;

    ui->lineEdit->setText(man->get_fio());
    ui->lineEdit_2->setText(man->get_phone());
    ui->lineEdit_3->setText(man->get_password());
    ui->checkBox->setChecked(man->get_is_admin());
}

void AddManagerDialog::on_buttonBox_accepted()
{
    if (man == nullptr)
        man = new manager();

    man->set_is_admin(ui->checkBox->isChecked());
    man->set_fio(ui->lineEdit->text());
    man->set_phone(ui->lineEdit_2->text());
    man->set_password(ui->lineEdit_3->text());
}
