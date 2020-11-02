#ifndef APPLICATIONHELPER_H
#define APPLICATIONHELPER_H
#include "manager.h"
#include "client.h"


class ApplicationHelper
{
public:
    static manager* current_manager;
    static client* current_client;
};



#endif // APPLICATIONHELPER_H
