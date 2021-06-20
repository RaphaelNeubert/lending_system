#include "mainwindow.h"
#include <QApplication>
#include "lending_system.h"

int main( int argc, char* argv[]){
	QApplication a(argc, argv);
	mainwindow w;
    lending_system tmp;
    tmp.read_medium();
	w.show();
	return a.exec();
}
