#include "gui.h"
#include <QtWidgets/QApplication>

#include "scanner.h"

using namespace std;

int main(int argc, char* argv[])
{
	queue<Token> scanned;
    scanned = scan();

	QApplication a(argc, argv);
	gui w;
	w.show();
	return a.exec();
}
