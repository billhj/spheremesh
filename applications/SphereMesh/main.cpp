#include "SMMainWindow.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SMMainWindow w;
	w.show();
	return a.exec();
}
