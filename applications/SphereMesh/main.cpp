#include "SMMainWindow.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QGLFormat glf = QGLFormat::defaultFormat();
    glf.setSampleBuffers(true);
    glf.setSamples(16);
    QGLFormat::setDefaultFormat(glf);

	SMMainWindow w;
	w.show();
	return a.exec();
}
