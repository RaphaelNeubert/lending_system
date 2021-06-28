#ifndef MEDIUM_H
#define MEDIUM_H
#include <QString>
#include <QDate>

class medium{
    private:
        QString title;
        QString type;
        unsigned int id;
        bool lend;
        unsigned int person_id;
        QDate lend_date;

    public:
        medium(QString title, QString type);
        medium(QString title, QString type, unsigned int id, bool lend, unsigned int person_id, QDate lend_date);
        QString get_title();
        QString get_type();
        unsigned int get_id();
        bool get_lend();
        unsigned int get_person_id();
        QDate get_lend_date();
        void set_lend(bool lend);
        void set_person_id(unsigned int person_id);
        void set_lend_date(QDate lend_date);
};
#endif
