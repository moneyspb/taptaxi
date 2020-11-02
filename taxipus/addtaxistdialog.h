#ifndef ADDTAXISTDIALOG_H
#define ADDTAXISTDIALOG_H

#include <QDialog>
#include "taxist.h"
#include "model_car_repository.h"
#include "basecombomodel.h"

namespace Ui {
class AddTaxistDialog;
}

class AddTaxistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTaxistDialog(QWidget *parent = nullptr);
    ~AddTaxistDialog();

    taxist* get_taxist();
    void set_taxist(taxist* tax);


private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddTaxistDialog *ui;

    void load_models();
    taxist* tax;
    map<int, model_car*> models;
};

#endif // ADDTAXISTDIALOG_H
