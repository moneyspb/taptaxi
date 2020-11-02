#ifndef DONTKNOWDIALOG_H
#define DONTKNOWDIALOG_H

#include <QDialog>

namespace Ui {
class dontknowDialog;
}

class dontknowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit dontknowDialog(QWidget *parent = nullptr);
    ~dontknowDialog();

private:
    Ui::dontknowDialog *ui;
};

#endif // DONTKNOWDIALOG_H
