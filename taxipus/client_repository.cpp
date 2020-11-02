#include "client_repository.h"
#include <map>

client_repository::client_repository()
{

}
map<int, client*> client_repository::get_all()
{
    db.open();

    QSqlQuery query;
    query.exec("SELECT * FROM client inner join person on client.id = person.id");

    map<int, client*> clients;

    while (query.next())
    {
        double reputation = query.value(0).toDouble();
        int id = query.value(1).toInt();
        QString fio = query.value(3).toString();
        QString phone = query.value(4).toString();
        QString password = query.value(5).toString();

        client* cl = new client();
        cl->set_id(id);
        cl->set_fio(fio);
        cl->set_phone(phone);
        cl->set_password(password);
        cl->set_reputation(reputation);

        clients.emplace(id, cl);
    }

    db.close();
    return clients;
}



void client_repository::add(client* cl)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("INSERT INTO person (fio, phone, password)"
                                  "VALUES (:fio, :phone, :password);");
    my_query.bindValue(":fio", cl->get_fio());
     my_query.bindValue(":phone", cl->get_phone());
    my_query.bindValue(":password", cl->get_password());

    my_query.exec();

    int id = my_query.lastInsertId().toInt();
    my_query.prepare("INSERT INTO client (id, reputation)"
                                  "VALUES (:id, :reputation);");
    my_query.bindValue(":id", id);
     my_query.bindValue(":reputation", cl->get_reputation());

    my_query.exec();

    db.close();
}



client* client_repository::find(QString phone, QString password)
{
    db.open();

    QSqlQuery query;
    query.prepare("SELECT * FROM client inner join person on client.id = person.id where phone = :phone and  password = :password;");
    query.bindValue(":phone", phone);
    query.bindValue(":password", password);

    query.exec();

    client* cl = nullptr;

    while (query.next())
    {
        double reput = query.value(0).toDouble();
        int id = query.value(1).toString().toInt();
        QString fio = query.value(3).toString();

        cl = new client();
        cl->set_reputation(reput);
        cl->set_id(id);
        cl->set_fio(fio);
        cl->set_phone(phone);
        cl->set_password(password);
    }

    db.close();

    return cl;
}



    void client_repository::remove(int id)
   {
    db.open();

    QSqlQuery my_query;
    my_query.prepare("DELETE FROM client where id = (:id);");
    my_query.bindValue(":id",id);

    my_query.exec();
    db.close();
}

    void client_repository::update(client* cl)
    {
        db.open();

        QSqlQuery my_query;
        my_query.prepare("UPDATE person set fio = :fio, phone = :phone, password = :password WHERE id = :id;");
        my_query.bindValue(":fio", cl->get_fio());
        my_query.bindValue(":phone", cl->get_phone());
        my_query.bindValue(":password", cl->get_password());
        my_query.bindValue(":id", cl->get_id());
        my_query.exec();

        my_query.prepare("UPDATE client set reputation = :reputation WHERE id = :id;");
        my_query.bindValue(":id", cl->get_id());
        my_query.bindValue(":reputation", cl->get_reputation());

        my_query.exec();

        db.close();
}
