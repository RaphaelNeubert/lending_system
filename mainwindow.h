#ifndef MAINWINDOW_H 
#define MAINWINDOW_H 
#include "ui_lending_system.h"

class mainwindow: public QMainWindow, public Ui::MainWindow{
    Q_OBJECT

	public:
		mainwindow(QMainWindow *parent=0);
		~mainwindow();

    private slots:

};

#endif
