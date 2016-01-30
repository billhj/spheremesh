#pragma once
#include <vector>
class Sphere
{
public:
	Sphere(void);
	~Sphere(void);
	void drawFill();
	void drawWireFrame();
	float m_center[3];
	float m_radius;
};

typedef std::vector<Sphere*> SphereSet;

