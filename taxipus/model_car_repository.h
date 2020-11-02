#ifndef MODEL_CAR_REPOSITORY_H
#define MODEL_CAR_REPOSITORY_H
#include "base_repository.h"
#include "model_car.h"

class model_car_repository : public base_repository
{
public:
    model_car_repository();
    map<int, model_car*> get_all();
    void add(model_car* model);
    void remove(int id);
};

#endif // MODEL_CAR_REPOSITORY_H
