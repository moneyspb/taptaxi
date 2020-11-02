#ifndef TAXISTSSSSDIALOG_H
#define TAXISTSSSSDIALOG_H

#include <QDialog>
#include <map>
#include "taxist.h"
#include "taxist_repository.h"
#include "addtaxistdialog.h"
#include "applicationhelper.h"

namespace Ui {
class taxistssssDialog;
}

class taxistssssDialog : public QDialog
{
    Q_OBJECT

public:
    explicit taxistssssDialog(QWidget *parent = nullptr);
    ~taxistssssDialog();

private slots:
    void on_pushButtonCreate_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::taxistssssDialog *ui;

    map<int, taxist*> taxists;

    void load_data();
     void update_item(int row, taxist* tax);
};

#endif // TAXISTSSSSDIALOG_H
