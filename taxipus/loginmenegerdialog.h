#ifndef LOGINMENEGERDIALOG_H
#define LOGINMENEGERDIALOG_H

#include <QDialog>

namespace Ui {
class LoginMenegerDialog;
}

class LoginMenegerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginMenegerDialog(QWidget *parent = nullptr);
    ~LoginMenegerDialog();

private:
    Ui::LoginMenegerDialog *ui;
};

#endif // LOGINMENEGERDIALOG_H
