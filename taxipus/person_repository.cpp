#include "person_repository.h"

person_repository::person_repository()
{

}

 int person_repository::count_person()
 {
     db.open();

     int rows = 0;
     QSqlQuery query("SELECT COUNT(*) FROM person");
     if (query.next()) {
         rows = query.value(0).toInt();
     }

     db.close();

     return rows;
 }
