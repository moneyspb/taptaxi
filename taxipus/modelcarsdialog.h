#ifndef MODELCARSDIALOG_H
#define MODELCARSDIALOG_H

#include <QDialog>
#include "model_car_repository.h"
#include "addmodelcardialog.h"
#include "model_car_repository.h"
#include <map>

namespace Ui {
class ModelCarsDialog;
}

class ModelCarsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModelCarsDialog(QWidget *parent = nullptr);
    ~ModelCarsDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ModelCarsDialog *ui;
    vector<model_car*> models;

    void load_data();
};

#endif // MODELCARSDIALOG_H
