#ifndef TAXIST_REPOSITORY_H
#define TAXIST_REPOSITORY_H

#include "base_repository.h"
#include "taxist.h"
#include "model_car_repository.h"

class taxist_repository : public base_repository
{
public:

    taxist_repository();
    void add(taxist* tax);
    taxist* find(QString phone, QString password);
    taxist* get(int id);
    void remove(int id);
    void update(taxist* tax);
     map<int, taxist*> get_all();
};





#endif // TAXIST_REPOSITORY_H
