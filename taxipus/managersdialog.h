#ifndef MANAGERSDIALOG_H
#define MANAGERSDIALOG_H

#include <QDialog>
#include "manager_repository.h"
#include "addmanagerdialog.h"

namespace Ui {
class ManagersDialog;
}

class ManagersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManagersDialog(QWidget *parent = nullptr);
    ~ManagersDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ManagersDialog *ui;
    map<int, manager*> managers;

    void load_data();
    void update_item(int row, manager* man);
};

#endif // MANAGERSDIALOG_H
