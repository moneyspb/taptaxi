#ifndef ORDERSWINDOW_H
#define ORDERSWINDOW_H

#include <QMainWindow>
#include "orderdialog.h"
#include "order_repository.h"

namespace Ui {
class OrdersWindow;
}

class OrdersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrdersWindow(QWidget *parent = nullptr);
    ~OrdersWindow();

private slots:
    void on_pushButtonCreate_clicked();

    void on_pushButtonEdit_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::OrdersWindow *ui;

     map<int, order*> orders;
    void load_data();
    void update_item(int row, order* ord);
    QString statusToString(status_order status);
    void change_status(status_order status);
};

#endif // ORDERSWINDOW_H
