#ifndef ADMINMENUDIALOG_H
#define ADMINMENUDIALOG_H

#include <QDialog>
#include "modelcarsdialog.h"
#include "managersdialog.h"
#include "orderswindow.h"
#include "taxistssssdialog.h"
#include "clientssssdialog.h"
#include "applicationhelper.h"

namespace Ui {
class AdminMenuDialog;
}

class AdminMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMenuDialog(QWidget *parent = nullptr);
    ~AdminMenuDialog();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminMenuDialog *ui;
};

#endif // ADMINMENUDIALOG_H
