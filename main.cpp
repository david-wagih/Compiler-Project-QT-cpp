#include "gui.h"
#include "Scan.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	initMap();
	QApplication a(argc, argv);
	gui w;
	w.show();
	return a.exec();
}
