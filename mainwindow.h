#ifndef MAINWINDOW_H 
#define MAINWINDOW_H 
#include "ui_lending_system.h"
#include "lending_system.h"

struct checkbox_t{
    unsigned int id;
    QTableWidgetItem* checkbox;
};

class mainwindow: public QMainWindow, public Ui::MainWindow{
    Q_OBJECT
    private:
        //background stuff
        lending_system lend;
        //used to access checkbox states later on
        QList<checkbox_t> checkbox_list;

        void create_person_table();
	public:
		mainwindow(QMainWindow *parent=0);
		~mainwindow();
    public slots:
        void create_medium_table();
        void create_lend_table();
        void change_lend_status();
        void add_person();
};

#endif
