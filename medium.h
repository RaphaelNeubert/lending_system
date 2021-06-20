#ifndef MEDIUM_H
#define MEDIUM_H
#include <QString>
class medium{
    private:
        QString name;
        QString type;
        unsigned int id;
        bool lend;

    public:
        medium(QString name, QString type);
        medium(QString name, QString type, unsigned int id, bool lend);
        QString get_name();
        QString get_type();
        void set_lend(bool lend);
};
#endif
