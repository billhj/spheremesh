#pragma once
#include <vector>


struct SphereEdge;

struct Sphere
{
public:
	Sphere(void);
	~Sphere(void);
	void drawFill();
	void drawWireFrame();
	float m_center[3];
	float m_radius;
	float m_cluster;
	std::vector<SphereEdge*> edges;
};

struct SphereEdge
{
	std::pair<Sphere*, Sphere*> m_connectedSpheres;
	Sphere* getConnectedSphere(Sphere* sphere)
	{
		return m_connectedSpheres.first == sphere? m_connectedSpheres.second : m_connectedSpheres.first;
	}
};

struct SphereSet //: public std::vector<Sphere*>
{
	std::vector<Sphere*> m_spheres;
	std::vector<SphereEdge*> m_edegs;

	int getSphereIndex(Sphere* sphere)
	{
		return (&sphere - &m_spheres[0]) /  sizeof(Sphere*);
	}

	int getSphereEdgeIndex(SphereEdge* sphereedge)
	{
		return (&sphereedge - &m_edegs[0]) /  sizeof(SphereEdge*);
	}
	void clear();

	void readSpheresFromFile(const std::string& filename);
	void saveSpheresToFile(const std::string& filename);
};