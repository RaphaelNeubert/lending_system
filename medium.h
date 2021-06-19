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
        QString getName();
        QString getType();
};
#endif
