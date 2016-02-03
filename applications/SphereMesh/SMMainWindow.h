#ifndef SMMAINWINDOW_H
#define SMMAINWINDOW_H

#include <QMainWindow>
#include "ui_SMMainWindow.h"
#include "MeshViewer.h"

class SMMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	SMMainWindow(QWidget *parent = 0);
	~SMMainWindow();
public slots:
	void openOBJ();
	void openOFF();
	void openPLY();
	void openSpheres();
	void algo_sphereSimplificationOneStep();
	void algo_sphereSimplificationAllSteps();
private:
	Ui::SMMainWindow ui;
	MeshViewer* m_pWidget;
};

#endif // SMMAINWINDOW_H
