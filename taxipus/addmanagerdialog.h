#ifndef ADDMANAGERDIALOG_H
#define ADDMANAGERDIALOG_H

#include <QDialog>
#include "manager.h"

namespace Ui {
class AddManagerDialog;
}

class AddManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddManagerDialog(QWidget *parent = nullptr);
    ~AddManagerDialog();

    manager* get_manager();
    void set_manager(manager* man);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddManagerDialog *ui;

    manager* man;

};

#endif // ADDMANAGERDIALOG_H
