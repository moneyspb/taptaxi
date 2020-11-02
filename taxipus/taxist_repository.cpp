#include "taxist_repository.h"


taxist_repository::taxist_repository()
{

}

void taxist_repository::add(taxist* tax)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("INSERT INTO person (fio, phone, password) VALUES (:fio, :phone, :password);");
    my_query.bindValue(":fio", tax->get_fio());
     my_query.bindValue(":phone", tax->get_phone());
    my_query.bindValue(":password", tax->get_password());

    bool res = my_query.exec();

    int id = my_query.lastInsertId().toInt();
    my_query.prepare("INSERT INTO taxist (id, number_car, model_id, color, is_busy, reputation)"
                                  "VALUES (:id, :number_car, :model_id, :color, :is_busy, :reputation);");
    my_query.bindValue(":id", id);
    my_query.bindValue(":reputation", tax->get_reputation());
    my_query.bindValue(":number_car", tax->get_number_car());
    my_query.bindValue(":model_id", tax->get_model_car()->get_id());
    my_query.bindValue(":color", tax->get_color());
    my_query.bindValue(":is_busy", tax->get_is_busy());

    res = my_query.exec();

    db.close();
   }

map<int, taxist*> taxist_repository::get_all()
{
    model_car_repository* repo = new model_car_repository();
    map<int, model_car*> models = repo->get_all();

    db = QSqlDatabase::addDatabase("QSQLITE");
    QString pathToDB = QDir::currentPath()+QString("/taptaxi.db");
    db.setDatabaseName(pathToDB);

    db.open();

    QSqlQuery query;
      //query.exec("SELECT * FROM manager inner join person on manager.id = person.id");
    bool res = query.exec("SELECT * FROM taxist inner join person on taxist.id = person.id");

    map<int, taxist*> taxists;

    while (query.next())
    {
        int id = query.value(0).toInt();
        QString numberCar = query.value(1).toString();
        int modelId = query.value(2).toInt();
        QString color = query.value(3).toString();
        bool isBusy = (bool)query.value(4).toInt();
        double reput = query.value(5).toDouble();
        QString fio = query.value(7).toString();
        QString phone = query.value(8).toString();
        QString password = query.value(9).toString();

        model_car* model = models.find(modelId)->second;

        taxist* tax = new taxist();
        tax->set_id(id);
        tax->set_reputation(reput);
        tax->set_fio(fio);
        tax->set_phone(phone);
        tax->set_password(password);
        tax->set_color(color);
        tax->set_is_busy(isBusy);
        tax->set_number_car(numberCar);
        tax->set_model_car(model);

        taxists.emplace(id, tax);
    }

    db.close();

    return taxists;
}

taxist* taxist_repository::get(int id)
{
    model_car_repository* repo = new model_car_repository();
    map<int, model_car*> models = repo->get_all();

    db.open();

    QSqlQuery query;
    query.prepare("SELECT * from person inner join taxist on taxist.id = person.id where person.id = :id");
    query.bindValue(":id", id);

    query.exec();

    taxist* tax = nullptr;

    while (query.next())
    {
        int id = query.value(0).toInt();
        QString numberCar = query.value(1).toString();
        int modelId = query.value(2).toInt();
        QString color = query.value(3).toString();
        bool isBusy = (bool)query.value(4).toInt();
        double reput = query.value(5).toDouble();
        QString fio = query.value(7).toString();
        QString phone = query.value(8).toString();
        QString password = query.value(9).toString();

        model_car* model = models.find(modelId)->second;

        tax = new taxist();
        tax->set_id(id);
        tax->set_reputation(reput);
        tax->set_fio(fio);
        tax->set_phone(phone);
        tax->set_password(password);
        tax->set_color(color);
        tax->set_is_busy(isBusy);
        tax->set_number_car(numberCar);
        tax->set_model_car(model);

    }

    db.close();

    return tax;
}

taxist* taxist_repository::find(QString phone, QString password)
{
    model_car_repository* repo = new model_car_repository();
    map<int, model_car*> models = repo->get_all();

    db.open();

    QSqlQuery query;
    query.prepare("SELECT * from person inner join taxist on taxist.id = person.id where person.phone = :phone and person.password = :password");
    query.bindValue(":phone", phone);
    query.bindValue(":password", password);

    query.exec();

    taxist* tax = nullptr;

    while (query.next())
    {
        int id = query.value(0).toInt();
        QString numberCar = query.value(1).toString();
        int modelId = query.value(2).toInt();
        QString color = query.value(3).toString();
        bool isBusy = (bool)query.value(4).toInt();
        double reput = query.value(5).toDouble();
        QString fio = query.value(7).toString();
        QString phone = query.value(8).toString();
        QString password = query.value(9).toString();

        model_car* model = models.find(modelId)->second;

        tax = new taxist();
        tax->set_id(id);
        tax->set_reputation(reput);
        tax->set_fio(fio);
        tax->set_phone(phone);
        tax->set_password(password);
        tax->set_color(color);
        tax->set_is_busy(isBusy);
        tax->set_number_car(numberCar);
        tax->set_model_car(model);

    }

    db.close();

    return tax;
}
void taxist_repository::update(taxist* tax)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("UPDATE person set fio = :fio, phone = :phone, password = :password WHERE id = :id;");
    my_query.bindValue(":fio", tax->get_fio());
     my_query.bindValue(":phone", tax->get_phone());
    my_query.bindValue(":password", tax->get_password());
     my_query.bindValue(":id", tax->get_id());

    bool res = my_query.exec();


    my_query.prepare("UPDATE taxist set reputation = :reputation,color = :color, is_busy =:is_busy,number_car =:number_car, model_id =:model_id WHERE id = :id;");
    my_query.bindValue(":id", tax->get_id());
    my_query.bindValue(":reputation", tax->get_reputation());
    my_query.bindValue(":color", tax->get_color());
    my_query.bindValue(":is_busy", tax->get_is_busy());
    my_query.bindValue(":number_car", tax->get_number_car());
    my_query.bindValue(":model_id", tax->get_model_car()->get_id());



    res = my_query.exec();

    db.close();

}


void taxist_repository::remove(int id)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("DELETE FROM person WHERE id = :id;");
     my_query.bindValue(":id", id);

    my_query.exec();

    my_query.prepare("DELETE FROM taxist WHERE id = :id;");
    my_query.bindValue(":id", id);

    my_query.exec();

    db.close();
}
