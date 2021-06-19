#ifndef MEDIUM_H
#define MEDIUM_H
#include <QString>
class medium{
    private:
        QString name;
        bool lend;
        QString type;

    public:
        medium(QString name, QString type);
        QString getName();
        QString getType();
};
#endif
