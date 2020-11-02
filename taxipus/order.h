#ifndef ORDER_H
#define ORDER_H
#include "client.h"
#include "taxist.h"
#include "tariff.h"
#include <QDate>
#include <QString>
#include "status_order.h"

class order
{
private:
    int id;
    client* m_client;
    taxist* m_taxist;
    QDateTime date;
    QString from_place;
    QString to_place;
    double cost;
    status_order status;
    Tarif tariff;

public:
    order();

    int get_id(){ return id; }
    void set_id(int id) { this->id = id; }

    QString get_from_place() { return from_place; }
    void set_from_place(QString from_place) { this->from_place = from_place; }

    QString get_to_place() { return to_place; }
    void set_to_place(QString to_place) { this->to_place = to_place; }

    double get_cost() { return cost; }
    void set_cost(double cost) { this->cost = cost; }

    QDateTime get_date() {return date; }
    void set_date (QDateTime date) {this->date = date;}

    client* get_client() {return m_client;}
    void set_client(client* cl) { m_client = cl; }

    taxist* get_taxist() {return m_taxist;}
    void set_taxist(taxist* tax) { m_taxist = tax; }

    status_order get_status(){return status;}
    void set_status(status_order status) { this->status = status;}

    Tarif get_tariff(){return tariff;}
    void set_tariff(Tarif tariff) { this->tariff = tariff;}
};

#endif // ORDER_H
