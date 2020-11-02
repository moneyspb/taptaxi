#ifndef TAPTAXI_H
#define TAPTAXI_H

#include <QMainWindow>
#include <QMessageBox>
#include "model_car_repository.h"
#include "orderdialog.h"
#include "person_repository.h"
#include "adminmenudialog.h"
#include "client_repository.h"
#include "addclientdialog.h"
#include "applicationhelper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TapTaxi; }
QT_END_NAMESPACE

class TapTaxi : public QMainWindow
{
    Q_OBJECT

public:
    TapTaxi(QWidget *parent = nullptr);
    ~TapTaxi();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::TapTaxi *ui;
};
#endif // TAPTAXI_H
