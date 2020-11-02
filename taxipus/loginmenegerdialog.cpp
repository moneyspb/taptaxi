#include "loginmenegerdialog.h"
#include "ui_loginmenegerdialog.h"

LoginMenegerDialog::LoginMenegerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginMenegerDialog)
{
    ui->setupUi(this);
}

LoginMenegerDialog::~LoginMenegerDialog()
{
    delete ui;
}
