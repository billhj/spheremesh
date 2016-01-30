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
