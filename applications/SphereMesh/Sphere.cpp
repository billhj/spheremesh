#include "Sphere.h"
#include <GL/glew.h>
#include "wrap/gl/gl_geometry.h"

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
	glPushMatrix();
	glTranslatef(m_center[0],m_center[1],m_center[2]);
	glutSolidSphere(m_radius, 12, 12);
	glPopMatrix();
}

void Sphere::drawWireFrame()
{
	glPushMatrix();
	glTranslatef(m_center[0],m_center[1],m_center[2]);
	glutWireSphere(m_radius, 12, 12);
	glPopMatrix();
}
