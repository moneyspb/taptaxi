#include "model_car_repository.h"

model_car_repository::model_car_repository()
{

}

map<int, model_car*> model_car_repository::get_all()
{
    db.open();

    QSqlQuery query;
    query.exec("SELECT * FROM model_car");

    map<int, model_car*> models;

    while (query.next())
    {
        int id = query.value(0).toString().toInt();
        QString name = query.value(1).toString();

        model_car* model = new model_car();
        model->set_id(id);
        model->set_name(name);
        models.emplace(id, model);
    }

    db.close();
    return models;
}

void model_car_repository::add(model_car* model)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("INSERT INTO model_car (name) VALUES (:name);");
    my_query.bindValue(":name", model->get_name());

    my_query.exec();

    int id = my_query.lastInsertId().toInt();
    model->set_id(id);

    db.close();
}


void model_car_repository::remove(int id)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("DELETE FROM model_car where id = (:id);");
    my_query.bindValue(":id",id);

    my_query.exec();
    db.close();
}
