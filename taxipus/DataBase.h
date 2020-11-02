#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

#define DATABASE_HOSTNAME "TapTaxi"
#define DATABASE_NAME "TapTaxi.db"

class DataBase : public QObject
{
    Q_OBJECT
 public:
    explicit DataBase(QObject * parent=0);
    ~DataBase();
    void connectToDataBase();
    bool insertIntoTable(const QVariantList &data);
 private:
    QSqlDatabase db;
 private:
    bool openDataBase();
    bool restartDataBase();
    void closeDataBase();
    bool createTable();
};



#endif // DATABASE_H
