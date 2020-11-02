#include "addmodelcardialog.h"
#include "ui_addmodelcardialog.h"

AddModelCarDialog::AddModelCarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddModelCarDialog)
{
    ui->setupUi(this);
}

AddModelCarDialog::~AddModelCarDialog()
{
    delete ui;
}

model_car* AddModelCarDialog::get_model()
{
    model_car* model = new model_car();
    model->set_name(ui->lineEdit->text());
    return model;
}
