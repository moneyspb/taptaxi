#include "DataBase.h"

DataBase::DataBase(QObject *parent): QObject(parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    if(!QFile(DATABASE_NAME).exists())
    {
        this->restartDataBase();
    }

    else
    {
        this->openDataBase();
    }


}

bool DataBase::restartDataBase()
{
    if(this->openDataBase())
    {
        //if(!this->createTable())
        {
            return false;
        }

        //else
            //return false;
    }
    else
    {
        qDebug()<<"Не удалось восстоновить базу данных";
        return false;
    }
    return false;
}

bool DataBase::openDataBase()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);

    if(db.open())
        return true;
    else
        return false;
}
void DataBase::closeDataBase()
{
    db.close();

}






