#include "SMMainWindow.h"

SMMainWindow::SMMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.setupUi(this);
	m_pWidget = new MeshViewer();
	this->setCentralWidget(m_pWidget);
}

SMMainWindow::~SMMainWindow()
{

}

#include <QFileDialog>
void SMMainWindow::openOBJ()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open OBJ"), "/", tr("Mesh Files (*.obj)"));
	if(fileName.isEmpty())
	{
		return;
	}
	m_pWidget->m_mesh.openMeshOBJ(fileName.toStdString());
	m_pWidget->setSceneRadius(m_pWidget->m_mesh.meshScale);
}

void SMMainWindow::openOFF()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open OFF"), "/", tr("Mesh Files (*.off)"));
	if(fileName.isEmpty())
	{
		return;
	}
	m_pWidget->m_mesh.openMeshOFF(fileName.toStdString());
	m_pWidget->setSceneRadius(m_pWidget->m_mesh.meshScale);
}

void SMMainWindow::openPLY()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open PLY"), "/", tr("Mesh Files (*.ply)"));
	if(fileName.isEmpty())
	{
		return;
	}
	m_pWidget->m_mesh.openMeshPLY(fileName.toStdString());
	m_pWidget->setSceneRadius(m_pWidget->m_mesh.meshScale);
}

void SMMainWindow::openSpheres()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Spheres"), "/", tr("Sphere Files (*.skn)"));
	if(fileName.isEmpty())
	{
		return;
	}
	m_pWidget->m_mesh.loadSpheres(fileName.toStdString());
}