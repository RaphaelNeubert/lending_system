#include "mainwindow.h"
#include <QApplication>
#include "lending_system.h"

int main( int argc, char* argv[]){
	QApplication a(argc, argv);
	mainwindow w;
    lending_system tmp;
    tmp.read_medium();
    tmp.read_person();
    tmp.write_person();
	w.show();
	return a.exec();
}
