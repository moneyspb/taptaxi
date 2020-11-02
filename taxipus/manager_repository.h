#ifndef MANAGER_REPOSITORY_H
#define MANAGER_REPOSITORY_H
#include "base_repository.h"
#include "manager.h"


class manager_repository : public base_repository
{
public:
    manager_repository();

    map<int, manager*> get_all();
    void add(manager* man);
    void update(manager* man);
    void remove(int id);
    manager* find(QString phone, QString password);
};

#endif // MANAGER_REPOSITORY_H
