#ifndef LENDING_SYSTEM_H
#define LENDING_SYSTEM_H
#include "medium.h"
#include <QList>

class lending_system{
    private:
        QList<medium*> medlist;
    public:
        lending_system();
        void read_medium();
};


#endif
