#ifndef CLIENT_REPOSITORY_H
#define CLIENT_REPOSITORY_H
#include "base_repository.h"
#include "client.h"

class client_repository : public base_repository
{
public:
    client_repository();
    void add(client* cl);
    client* find(QString phone, QString password);
     map<int,client*> get_all();
     void remove(int id);
     void update (client* cl);
};

#endif // CLIENT_REPOSITORY_H
