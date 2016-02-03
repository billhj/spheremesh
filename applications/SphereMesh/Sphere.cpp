#include "Sphere.h"
#include <GL/glew.h>
#include "wrap/gl/gl_geometry.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

Sphere::Sphere(void) : m_radius(0)
{
	m_center[0] = 0;
	m_center[1] = 0;
	m_center[2] = 0;
}


Sphere::~Sphere(void)
{
}

void Sphere::drawFill()
{
	glColor4f(1,0,0,0.5);
	glPushMatrix();
	glTranslatef(m_center[0],m_center[1],m_center[2]);
	glutSolidSphere(m_radius, 12, 12);
	glPopMatrix();
}

void Sphere::drawWireFrame()
{
	glColor4f(1,0,0,0.5);
	glPushMatrix();
	glTranslatef(m_center[0],m_center[1],m_center[2]);
	glutWireSphere(m_radius, 12, 12);
	glPopMatrix();
}

float sphereScale = 1.0/100000000.0;
void SphereSet::readSpheresFromFile(const std::string& filename)
{
	std::string line;
	std::ifstream myfile (filename);
	if (myfile.is_open())
	{
		getline(myfile,line);
		std::stringstream lineData(line);
		int nb = 0;
		lineData >> nb;

		while (!myfile.eof())
		{
			getline(myfile,line);

			if (line.empty())
				continue;

			std::stringstream lineData(line);

			Sphere* newSphere = new Sphere();

			lineData >> newSphere->m_center[0];
			newSphere->m_center[0] = newSphere->m_center[0] * sphereScale;

			lineData >> newSphere->m_center[1];
			newSphere->m_center[1] = newSphere->m_center[1] * sphereScale;

			lineData >> newSphere->m_center[2];
			newSphere->m_center[2] = newSphere->m_center[2] * sphereScale;

			lineData >> newSphere->m_radius;
			newSphere->m_radius = newSphere->m_radius * sphereScale;

			m_spheres.push_back(newSphere);
		}
		myfile.close();
		std::cout<<"read spheres from ["<<filename<<"] :" << nb <<" spheres!" <<m_spheres.size() <<std::endl;
		assert(nb == m_spheres.size());
	}
	else std::cout << "Unable to open file : "<<filename<<std::endl;; 
}

void SphereSet::saveSpheresToFile(const std::string& filename)
{
	std::ofstream myfile (filename);
	if (myfile.is_open())
	{
		myfile << m_spheres.size()<<std::endl;
		for(unsigned int i = 0; i < m_spheres.size(); ++i)
		{
			myfile << m_spheres[i]->m_center[0]<<" "<< m_spheres[i]->m_center[1]<<" "<< m_spheres[i]->m_center[2]<<" "<< m_spheres[i]->m_radius<<std::endl;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file : "<<filename<<std::endl;
}