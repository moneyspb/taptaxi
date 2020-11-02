#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H

#include <QDialog>
#include "client.h"
#include "client_repository.h"

namespace Ui {
class AddClientDialog;
}

class AddClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientDialog(QWidget *parent = nullptr);
    ~AddClientDialog();

    client* get_client();
    void set_client(client* cl);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddClientDialog *ui;

     client* cl;
};

#endif // ADDCLIENTDIALOG_H
