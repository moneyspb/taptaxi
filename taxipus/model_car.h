#ifndef MODEL_CAR_H
#define MODEL_CAR_H
#include<QString>


class model_car
{
private:
    int id;
    QString name;

public:
    model_car();

    int get_id(){ return id; }
    void set_id(int id) { this->id = id; }

    QString get_name() { return name; }
    void set_name(QString name) { this->name = name; }
};

#endif // MODEL_CAR_H
