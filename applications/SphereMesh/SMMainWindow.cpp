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
	SphereMesh* mesh = new SphereMesh();
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open OBJ"), "/", tr("Mesh Files (*.obj)"));
	if(fileName.isEmpty())
	{
		delete mesh;
		return;
	}
	mesh->openMeshOBJ(fileName.toStdString());
	m_pWidget->setSceneRadius(mesh->meshScale);
	m_pWidget->m_pmesh = mesh;
}

void SMMainWindow::openOFF()
{
	SphereMesh* mesh = new SphereMesh(); 
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open OFF"), "/", tr("Mesh Files (*.off)"));
	if(fileName.isEmpty())
	{
		delete mesh;
		return;
	}
	mesh->openMeshOFF(fileName.toStdString());
	m_pWidget->setSceneRadius(mesh->meshScale);
	m_pWidget->m_pmesh = mesh;
}

void SMMainWindow::openPLY()
{
	SphereMesh* mesh = new SphereMesh();
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open PLY"), "/", tr("Mesh Files (*.ply)"));
	if(fileName.isEmpty())
	{
		delete mesh;
		return;
	}
	mesh->openMeshPLY(fileName.toStdString());
	m_pWidget->setSceneRadius(mesh->meshScale);
	m_pWidget->m_pmesh = mesh;
}