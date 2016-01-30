#pragma once
#include <string>
#include<vcg/complex/complex.h>

#include "Sphere.h"

class MyVertex; class MyEdge; class MyFace;
struct MyUsedTypes : public vcg::UsedTypes<vcg::Use<MyVertex>   ::AsVertexType,
                                           vcg::Use<MyEdge>     ::AsEdgeType,
                                           vcg::Use<MyFace>     ::AsFaceType>{};
class MyVertex  : public vcg::Vertex< MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Normal3f, vcg::vertex::BitFlags  >{};
class MyFace    : public vcg::Face<   MyUsedTypes, vcg::face::FFAdj,  vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyEdge    : public vcg::Edge<   MyUsedTypes> {};
class MyMesh    : public vcg::tri::TriMesh< std::vector<MyVertex>, std::vector<MyFace> , std::vector<MyEdge>  > {};

enum DrawMode{DMNone, DMBox, DMPoints, DMWire, DMHidden, DMFlat, DMSmooth, DMFlatWire, DMRadar, DMLast} ;

class SphereMesh
{
public:
	SphereMesh(void);
	~SphereMesh(void);
	void draw();
	void drawMesh();
	void drawSpheres();
	void openMeshPLY(const std::string& filepath);
	void saveMeshPLY(const std::string& filepath);

	void openMeshOBJ(const std::string& filepath);
	void openMeshOFF(const std::string& filepath);

	void loadSpheres(const std::string& filepath);


	void compute();

	void init();
	void update();
	void clear();

	MyMesh* m_pmymesh;
	int m_mask;
	std::vector<unsigned int> indices;
	unsigned int array_buffers[3];
	float meshScale;
	DrawMode m_drawmode; // Current DrawMode

	SphereSet m_sphereset;
};

