#ifndef ORDER_REPOSITORY_H
#define ORDER_REPOSITORY_H
#include "base_repository.h"
#include "order.h"
#include "taxist_repository.h"
#include "client_repository.h"

class order_repository : public base_repository
{
public:
    order_repository();
    void add(order* ord);
    void update(order* ord);
    map<int, order*> get_all();
     void remove(int id);
};

#endif // ORDER_REPOSITORY_H
