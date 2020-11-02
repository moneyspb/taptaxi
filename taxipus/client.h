#ifndef CLIENT_H
#define CLIENT_H
#include "person.h"


class client : public person
{
private:
    double reputation;
public:
    client();

    double get_reputation() { return reputation; }
    void set_reputation(double reputation) { this->reputation = reputation; }
};

#endif // CLIENT_H
