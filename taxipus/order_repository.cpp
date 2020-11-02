#include "order_repository.h"
#include <QSqlError>

order_repository::order_repository()
{

}

void order_repository::add(order* ord)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("INSERT INTO order_car(client_id, taxist_id, date, from_place, to_place, cost, status, tariff) "
                     "VALUES(:client_id, :taxist_id, :date, :from_place, :to_place, :cost, :status, :tariff);");
    my_query.bindValue(":client_id", ord->get_client()->get_id());
    if (ord->get_taxist() != nullptr)
        my_query.bindValue(":taxist_id", ord->get_taxist()->get_id());
    else
        my_query.bindValue(":taxist_id", QVariant(QVariant::Int));

    my_query.bindValue(":date", ord->get_date().toString());
    my_query.bindValue(":from_place", ord->get_from_place());
    my_query.bindValue(":to_place", ord->get_to_place());
    my_query.bindValue(":cost", ord->get_cost());
    my_query.bindValue(":status", (int)ord->get_status());
    my_query.bindValue(":tariff", (int)ord->get_tariff());

    bool res = my_query.exec();

    int id = my_query.lastInsertId().toInt();
    ord->set_id(id);

    db.close();
}

void order_repository::update(order* ord)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("UPDATE order_car set client_id = :client_id, taxist_id = :taxist_id, date = :date, "
                     "from_place = :from_place, to_place = :to_place, cost = :cost, status = :status, tariff =:tariff  WHERE id = :id;");

    my_query.bindValue(":id", ord->get_id());
    my_query.bindValue(":client_id", ord->get_client()->get_id());
    if (ord->get_taxist() != nullptr)
        my_query.bindValue(":taxist_id", ord->get_taxist()->get_id());
    else
        my_query.bindValue(":taxist_id", QVariant(QVariant::Int));

    my_query.bindValue(":date", ord->get_date().toString());
    my_query.bindValue(":from_place", ord->get_from_place());
    my_query.bindValue(":to_place", ord->get_to_place());
    my_query.bindValue(":cost", ord->get_cost());
    my_query.bindValue(":status", (int)ord->get_status());
    my_query.bindValue(":tariff", (int)ord->get_tariff());

    bool res = my_query.exec();

    db.close();
}

map<int, order*> order_repository::get_all()
{
    taxist_repository* tax_repo = new taxist_repository();
    map<int, taxist*> taxists = tax_repo->get_all();

    client_repository* cli_repo = new client_repository();
    map<int, client*> clients = cli_repo->get_all();

    db = QSqlDatabase::addDatabase("QSQLITE");
    QString pathToDB = QDir::currentPath()+QString("/taptaxi.db");
    db.setDatabaseName(pathToDB);

    db.open();

    QSqlQuery query;
    query.exec("SELECT * FROM order_car");

    map<int, order*> orders;

    while (query.next())
    {
        int id = query.value(0).toInt();
        int client_id = query.value(1).toInt();
        int tax_id = query.value(2).toInt();
        QString sdate = query.value(3).toString();
        QDateTime date = QDateTime::fromString(sdate);
        QString from_place = query.value(4).toString();
        QString to_place = query.value(5).toString();
        double cost = query.value(6).toDouble();
        int status = query.value(7).toInt();
        Tarif tarif = (Tarif)query.value(8).toInt();

        order* ord = new order();
        ord->set_id(id);
        ord->set_cost(cost);
        ord->set_date(date);
        ord->set_status((status_order)status);
        ord->set_to_place(to_place);
        ord->set_from_place(from_place);
        ord->set_tariff(tarif);

        client* cl = clients.find(client_id)->second;
        if (tax_id != 0)
        {
            taxist* tax = taxists.find(tax_id)->second;
            ord->set_taxist(tax);
        }

        ord->set_client(cl);

        orders.emplace(id, ord);
    }

    db.close();
    return orders;
}
void order_repository::remove(int id)
{
    db.open();

    QSqlQuery my_query;
    my_query.prepare("DELETE FROM order WHERE id = :id;");
     my_query.bindValue(":id", id);

    my_query.exec();

    db.close();
}

