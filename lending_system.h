#ifndef LENDING_SYSTEM_H
#define LENDING_SYSTEM_H
#include "ui_lending_system.h"

class lending_system : public QMainWindow, public Ui::MainWindow{
    Q_OBJECT

	public:
		lending_system(QMainWindow *parent=0);
		~lending_system();

    private slots:

};

#endif
