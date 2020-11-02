#include "base_repository.h"

base_repository::base_repository()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString pathToDB = QDir::currentPath()+QString("/taptaxi.db");
    db.setDatabaseName(pathToDB);
}
