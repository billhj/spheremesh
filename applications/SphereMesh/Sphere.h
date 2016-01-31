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


struct SphereSet //: public std::vector<Sphere*>
{
	std::vector<Sphere*> m_spheres;
	std::vector<std::pair<Sphere*, Sphere*>> m_edegs;
};