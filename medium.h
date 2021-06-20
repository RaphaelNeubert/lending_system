#ifndef MEDIUM_H
#define MEDIUM_H
#include <QString>
#include <QDate>

class medium{
    private:
        QString name;
        QString type;
        unsigned int id;
        bool lend;
        unsigned int person_id;
        QDate lend_date;

    public:
        medium(QString name, QString type);
        medium(QString name, QString type, unsigned int id, bool lend, unsigned int person_id, QDate lend_date);
        QString get_name();
        QString get_type();
        bool get_lend();
        void set_lend(bool lend);
};
#endif
