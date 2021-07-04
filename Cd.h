#ifndef CD_H
#define CD_H

#include "Medium.h"
#include <QString>

class Cd: public Medium{
    private:
        QString artist;
        QString producer;
    
    public:
        Cd(QString title, QString artist, QString producer, unsigned int id, bool lend, unsigned int person_id, QDate lend_date);
        QString get_artist();
        QString get_producer();
};


#endif

