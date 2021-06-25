#ifndef CD_H
#define CD_H

#include "medium.h"
#include <QString>

class cd: public medium{
    private:
        QString artist;
        QString producer;
    
    public:
        cd(QString title, QString artist, QString producer, unsigned int id, bool lend, unsigned int person_id, QDate lend_date);
        QString get_artist();
        QString get_producer();
};


#endif

