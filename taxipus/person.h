#ifndef PERSON_H
#define PERSON_H
#include<QString>


class person
{
private:
    int id;
    QString fio;
    QString phone;
    QString password;
public:
    person();

    int get_id(){ return id; }
    void set_id(int id) { this->id = id; }

    QString get_fio() { return fio; }
    void set_fio(QString fio) { this->fio = fio; }

    QString get_phone() { return phone; }
    void set_phone(QString phone) { this->phone = phone; }

    QString get_password() { return password; }
    void set_password(QString password) { this->password = password; }
};

#endif // PERSON_H
