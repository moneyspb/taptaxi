#ifndef CLIENTSSSSDIALOG_H
#define CLIENTSSSSDIALOG_H
#include <map>
#include <QDialog>
#include "client.h"
#include "client_repository.h"
#include "addclientdialog.h"
#include "applicationhelper.h"


namespace Ui {
class clientssssDialog;
}

class clientssssDialog : public QDialog
{
    Q_OBJECT

public:
    explicit clientssssDialog(QWidget *parent = nullptr);
    ~clientssssDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::clientssssDialog *ui;
    map<int, client*> clients;

    void load_data();
    void update_item(int row, client* cl);
};

#endif // CLIENTSSSSDIALOG_H
