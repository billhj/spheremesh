#ifndef MESHVIEWER_H
#define MESHVIEWER_H

#include <QGLViewer/qglviewer.h>
#include "SphereMesh.h"

class MeshViewer : public QGLViewer
{
	Q_OBJECT

public:
	MeshViewer(QWidget *parent = 0);
	~MeshViewer();
	void clear();
	void init();
	void draw();

	SphereMesh m_mesh;
};

#endif // MESHVIEWER_H
