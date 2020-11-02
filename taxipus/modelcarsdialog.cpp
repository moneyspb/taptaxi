#include "modelcarsdialog.h"
#include "ui_modelcarsdialog.h"

ModelCarsDialog::ModelCarsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelCarsDialog)
{
    ui->setupUi(this);

    load_data();
}

ModelCarsDialog::~ModelCarsDialog()
{
    delete ui;
}

void ModelCarsDialog::load_data()
{
    model_car_repository* model_repo = new model_car_repository();
    map<int, model_car*> models = model_repo->get_all();

    ui->tableWidget->setRowCount(models.size());

    ui->tableWidget->hideColumn(1);

    int i = 0;
    for (auto start = models.begin(); start != models.end(); start++) {
        model_car* model = start->second;
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(model->get_name()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(model->get_id())));
        i++;
    }
}

void ModelCarsDialog::on_pushButton_clicked()
{

    AddModelCarDialog* dialog = new AddModelCarDialog();
    //this->hide();
    int res = dialog->exec();
    if (res)
    {
        model_car* model = dialog->get_model();
        model_car_repository* repo = new model_car_repository();
        repo->add(model);

        models.push_back(model);
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(model->get_name()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(model->get_id())));
    }
    //this->show();
}

void ModelCarsDialog::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 1)->text().toInt();

    ui->tableWidget->removeRow(row);
    model_car_repository* repo = new model_car_repository();
    repo->remove(id);
}
