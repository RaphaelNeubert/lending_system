#ifndef MAINWINDOW_H 
#define MAINWINDOW_H 
#include "ui_MainWindow.h"
#include "lending_system.h"

struct checkbox_t{
    unsigned int id;
    QTableWidgetItem* checkbox;
};

namespace Ui{
    class MainWindow;
}

class MainWindow: public QMainWindow{
    Q_OBJECT
    private:
        Ui::MainWindow* ui;
        //background stuff
        lending_system lend;
        //used to access checkbox states later on
        QList<checkbox_t> checkbox_list;

        void create_person_table();
        void delete_person(unsigned int id);
        void delete_medium(unsigned int id);
	public:
		MainWindow(QMainWindow *parent=0);
		~MainWindow();
    public slots:
        void create_medium_table();
        void create_lend_table();
        void change_lend_status();
        void add_person();
        void add_medium();
};

#endif
