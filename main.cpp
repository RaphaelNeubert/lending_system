#include "mainwindow.h"
#include <QApplication>
#include "book.h"
#include <iostream>

int main( int argc, char* argv[]){
	QApplication a(argc, argv);
	lending_system w;
	w.show();
	return a.exec();
}
