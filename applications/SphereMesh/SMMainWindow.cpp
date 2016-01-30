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
	m_pWidget->m_pmesh = new SphereMesh(); 
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open OBJ"), "/", tr("Mesh Files (*.obj)"));
	m_pWidget->m_pmesh->openMeshOBJ(fileName.toStdString());
	m_pWidget->setSceneRadius(m_pWidget->m_pmesh->meshScale);
}

void SMMainWindow::openOFF()
{
	m_pWidget->m_pmesh = new SphereMesh(); 
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open OFF"), "/", tr("Mesh Files (*.off)"));
	m_pWidget->m_pmesh->openMeshOFF(fileName.toStdString());
	m_pWidget->setSceneRadius(m_pWidget->m_pmesh->meshScale);
}

void SMMainWindow::openPLY()
{
	m_pWidget->m_pmesh = new SphereMesh(); 
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open PLY"), "/", tr("Mesh Files (*.ply)"));
	m_pWidget->m_pmesh->openMeshPLY(fileName.toStdString());
	m_pWidget->setSceneRadius(m_pWidget->m_pmesh->meshScale);
}