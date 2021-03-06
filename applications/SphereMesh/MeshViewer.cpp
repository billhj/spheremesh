#include <GL/glew.h>
#include "MeshViewer.h"

MeshViewer::MeshViewer(QWidget *parent)
	: QGLViewer(parent)
{
}

MeshViewer::~MeshViewer()
{
	clear();
}

void MeshViewer::clear()
{

}

void MeshViewer::init()
{
	GLenum errorEnum = glewInit();
	std::cout<<"glew init"<<std::endl;
	const char* str = (char*)glewGetString(GLEW_VERSION);               // check NULL return value
	if ( GLEW_OK != errorEnum ) {
		std::cout<< "Error Initializing Glew: " << glewGetErrorString( errorEnum ) << std::endl;
		assert( 0 );
		exit( 1 );
		return;
	}

	setMouseTracking(true);
	setFocusPolicy(Qt::StrongFocus);
	setShortcut(DISPLAY_FPS,Qt::CTRL+Qt::Key_F);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT,GL_FILL);

	glClearColor(0, 0, 0, 0.99);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glShadeModel(GL_SMOOTH);
	//glEnable(GL_MULTISAMPLE);
}

void MeshViewer::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_mesh.draw();
}