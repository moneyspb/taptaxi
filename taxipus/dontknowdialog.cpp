#include "dontknowdialog.h"
#include "ui_dontknowdialog.h"

dontknowDialog::dontknowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dontknowDialog)
{
    ui->setupUi(this);
}

dontknowDialog::~dontknowDialog()
{
    delete ui;
}
