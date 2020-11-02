#ifndef MANAGER_H
#define MANAGER_H
#include "person.h"


class manager : public person
{
private:
    bool is_admin;
public:
    manager();
    bool get_is_admin() { return is_admin; }
    void set_is_admin(bool is_admin) { this->is_admin = is_admin; }
};

#endif // MANAGER_H
