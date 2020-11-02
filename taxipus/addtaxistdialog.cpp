#include "addtaxistdialog.h"
#include "ui_addtaxistdialog.h"

AddTaxistDialog::AddTaxistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTaxistDialog)
{
    ui->setupUi(this);
    tax = nullptr;

    ui->comboBoxModel->setModel(new BaseComboModel("name", "model_car", this));

    load_models();

    //ui->comboBoxModel->setCurrentIndex(0);
}

AddTaxistDialog::~AddTaxistDialog()
{
    delete ui;
}

taxist* AddTaxistDialog::get_taxist()
{
    return tax;
}

void AddTaxistDialog::load_models()
{
    model_car_repository* repo = new model_car_repository();
    models = repo->get_all();


}

void AddTaxistDialog::set_taxist(taxist* tax)
{
    this->tax = tax;

    ui->lineEditFIO->setText(tax->get_fio());
    ui->lineEditColor->setText(tax->get_color());
    ui->lineEditPhone->setText(tax->get_phone());
    ui->lineEditNumber->setText(tax->get_number_car());

    int size = ui->comboBoxModel->model()->rowCount();
    for (int i = 0; i < size; i++){
        QModelIndex cur= ui->comboBoxModel->model()->index(i, 0);
        int id = cur.data(Qt::UserRole).toInt();
        if (id == tax->get_model_car()->get_id()){
            ui->comboBoxModel->setCurrentIndex(cur.row());
            break;
        }
    }
}

void AddTaxistDialog::on_buttonBox_accepted()
{
    if (tax == nullptr)
        tax = new taxist();

    tax->set_fio(ui->lineEditFIO->text());
    tax->set_password("22");
    tax->set_phone(ui->lineEditPhone->text());
    tax->set_color(ui->lineEditColor->text());
    tax->set_number_car(ui->lineEditNumber->text());

   QVariant var =  ui->comboBoxModel->model()->data(ui->comboBoxModel->model()->index(ui->comboBoxModel->currentIndex(), 0), Qt::UserRole);
   int id =  var.toInt();
    model_car* model = models.find(id)->second;
    tax->set_model_car(model);
}
