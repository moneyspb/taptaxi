#include "manager_repository.h"

manager_repository::manager_repository()
{

}


manager* manager_repository::find(QString phone, QString password)
{
    db.open();

    QSqlQuery query;
    query.prepare("SELECT * FROM manager inner join person on manager.id = person.id where phone = :phone and  password = :password;");
    query.bindValue(":phone", phone);
    query.bindValue(":password", password);

    query.exec();

    manager* man = nullptr;

    while (query.next())
    {
        bool is_admin = query.value(0).toBool();
        int id = query.value(1).toString().toInt();
        QString fio = query.value(3).toString();

        man = new manager();
        man->set_id(id);
        man->set_fio(fio);
        man->set_phone(phone);
        man->set_password(password);
        man->set_is_admin(is_admin);
    }

    db.close();

    return man;
}



map<int, manager*> manager_repository::get_all()
{
    db.open();

    QSqlQuery query;
    query.exec("SELECT * FROM manager inner join person on manager.id = person.id");

    map<int, manager*> managers;

    while (query.next())
    {
        int is_admin = query.value(0).toInt();
        int id = query.value(1).toInt();
        QString fio = query.value(3).toString();
        QString phone = query.value(4).toString();
        QString password = query.value(5).toString();

        manager* cl = new manager();
        cl->set_id(id);
        cl->set_fio(fio);
        cl->set_phone(phone);
        cl->set_password(password);
        cl->set_is_admin((bool)is_admin);

        managers.emplace(id, cl);
    }

    db.close();
    return managers;
}

void manager_repository::add(manager* man)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("INSERT INTO person (fio, phone, password)"
                                  "VALUES (:fio, :phone, :password);");
    my_query.bindValue(":fio", man->get_fio());
     my_query.bindValue(":phone", man->get_phone());
    my_query.bindValue(":password", man->get_password());

    my_query.exec();

    int id = my_query.lastInsertId().toInt();
    my_query.prepare("INSERT INTO manager (id, is_admin)"
                                  "VALUES (:id, :is_admin);");
    my_query.bindValue(":id", id);
    my_query.bindValue(":is_admin", (int)man->get_is_admin());

    my_query.exec();

    db.close();
}

void manager_repository::update(manager* man)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("UPDATE person set fio = :fio, phone = :phone, password = :password WHERE id = :id;");
    my_query.bindValue(":fio", man->get_fio());
     my_query.bindValue(":phone", man->get_phone());
    my_query.bindValue(":password", man->get_password());
     my_query.bindValue(":id", man->get_id());

    my_query.exec();

    my_query.prepare("UPDATE manager set is_admin = :is_admin WHERE id = :id;");
    my_query.bindValue(":id", man->get_id());
    my_query.bindValue(":is_admin", (int)man->get_is_admin());

    my_query.exec();

    db.close();

}

void manager_repository::remove(int id)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("DELETE FROM person WHERE id = :id;");
     my_query.bindValue(":id", id);

    my_query.exec();

    my_query.prepare("DELETE FROM manager WHERE id = :id;");
    my_query.bindValue(":id", id);

    my_query.exec();

    db.close();
}
