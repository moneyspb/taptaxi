#ifndef TAXIST_H
#define TAXIST_H
#include "person.h"
#include "model_car.h"
#include <QString>


class taxist : public person
{
private:
    QString number_car;
    model_car* model;
    QString color;
    bool is_busy;
    double reputation;

public:
    taxist();
    QString get_number_car() { return number_car; }
    void set_number_car(QString number_car) { this->number_car = number_car; }

    QString get_color() { return color; }
    void set_color(QString color) { this->color = color; }

    double get_is_busy() { return is_busy; }
    void set_is_busy(double is_busy) { this->is_busy = is_busy; }

    double get_reputation() { return reputation; }
    void set_reputation(double reputation) { this->reputation = reputation; }

    model_car* get_model_car() { return model; }
    void set_model_car(model_car* model) { this->model = model; }
};

#endif // TAXIST_H
