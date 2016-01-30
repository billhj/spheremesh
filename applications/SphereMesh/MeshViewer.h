#ifndef MESHVIEWER_H
#define MESHVIEWER_H

#include <QGLViewer/qglviewer.h>

class MeshViewer : public QGLViewer
{
	Q_OBJECT

public:
	MeshViewer(QWidget *parent = 0);
	~MeshViewer();
	void clear();
	void init();
	void draw();

};

#endif // MESHVIEWER_H
