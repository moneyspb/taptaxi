#ifndef PERSON_REPOSITORY_H
#define PERSON_REPOSITORY_H
#include "base_repository.h"

class person_repository : public base_repository
{
public:
    person_repository();

    int count_person();
};

#endif // PERSON_REPOSITORY_H
