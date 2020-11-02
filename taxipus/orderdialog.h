#ifndef ORDERDIALOG_H
#define ORDERDIALOG_H

#include <QDialog>
#include "client.h"
#include "order.h"
#include "status_order.h"
#include "basecombomodel.h"
#include "client_repository.h"
#include "taxist_repository.h"
#include "mathLibrary.h"
#include <QMessageBox>
#include "applicationhelper.h"

namespace Ui {
class orderDialog;
}

class orderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit orderDialog(QWidget *parent = nullptr);
    ~orderDialog();
    void set_client(client* cl);
    void set_order(order* ord);
    order* get_order() { return  ord; }

private slots:
    void on_buttonBox_accepted();

    void on_pushButtonCost_clicked();

    void on_lineEditFrom_textChanged(const QString &arg1);

    void on_lineEditTo_textChanged(const QString &arg1);

    void on_comboBoxTariff_currentIndexChanged(int index);

private:
    Ui::orderDialog *ui;
    client* cl;
    order* ord;

    bool check;
    bool changed;
    void accept() override;
};

#endif // ORDERDIALOG_H
