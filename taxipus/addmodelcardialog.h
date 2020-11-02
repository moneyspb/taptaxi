#ifndef ADDMODELCARDIALOG_H
#define ADDMODELCARDIALOG_H

#include <QDialog>
#include "model_car.h"

namespace Ui {
class AddModelCarDialog;
}

class AddModelCarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddModelCarDialog(QWidget *parent = nullptr);
    ~AddModelCarDialog();

    model_car* get_model();

private:
    Ui::AddModelCarDialog *ui;
};

#endif // ADDMODELCARDIALOG_H
