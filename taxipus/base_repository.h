#ifndef BASE_REPOSITORY_H
#define BASE_REPOSITORY_H

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QVariant"
#include <QString>
#include <QDir>
#include <vector>
#include<map>
using namespace std;


class base_repository
{
protected:
    QSqlDatabase db;
public:
    base_repository();
};

#endif // BASE_REPOSITORY_H
