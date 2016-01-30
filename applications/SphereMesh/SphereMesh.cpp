#include "SphereMesh.h"
#include <wrap/io_trimesh/import.h>
#include <wrap/io_trimesh/export.h>
#include <GL/glew.h>

SphereMesh::SphereMesh(void) : m_pmymesh(NULL), m_mask(0), m_drawmode(DMSmooth)
{
	array_buffers[0] = 0;
	array_buffers[1] = 0;
	array_buffers[2] = 0;
}


SphereMesh::~SphereMesh(void)
{
}

void SphereMesh::draw()
{
	drawMesh();
	drawSpheres();
}

void SphereMesh::drawMesh()
{
		/*glBegin(GL_TRIANGLES);
		glVertex3f(0,1,0);
		glVertex3f(-1,0,0);
		glVertex3f(1,0,0);
		glEnd();*/
	if(m_pmymesh)
	{
		if(m_drawmode==DMSmooth)
		{
			//glPolygonMode(GL_FRONT,GL_LINES);
			glColor4f(0,0,1,0.5);
			glEnableClientState (GL_NORMAL_ARRAY);
			glEnableClientState (GL_VERTEX_ARRAY);

			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[1]);
			glNormalPointer(GL_FLOAT,sizeof(MyMesh::VertexType),0);
			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[0]);
			glVertexPointer(3,GL_FLOAT,sizeof(MyMesh::VertexType),0);

			glDrawElements(GL_TRIANGLES ,m_pmymesh->fn*3,GL_UNSIGNED_INT, &(*indices.begin()) );

			glDisableClientState (GL_VERTEX_ARRAY);
			glDisableClientState (GL_NORMAL_ARRAY);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		else if(m_drawmode==DMWire)
		{
			//glPolygonMode(GL_FRONT,GL_LINES);
			glColor4f(0,0,1,0.5);
			glEnableClientState (GL_NORMAL_ARRAY);
			glEnableClientState (GL_VERTEX_ARRAY);

			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[1]);
			glNormalPointer(GL_FLOAT,sizeof(MyMesh::VertexType),0);
			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[0]);
			glVertexPointer(3,GL_FLOAT,sizeof(MyMesh::VertexType),0);

			glDrawElements(GL_LINES ,m_pmymesh->fn*3,GL_UNSIGNED_INT, &(*indices.begin()) );

			glDisableClientState (GL_VERTEX_ARRAY);
			glDisableClientState (GL_NORMAL_ARRAY);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		else if(m_drawmode==DMPoints)
		{
			//glPolygonMode(GL_FRONT,GL_LINES);
			glColor4f(0,0,1,0.5);
			glEnableClientState (GL_NORMAL_ARRAY);
			glEnableClientState (GL_VERTEX_ARRAY);

			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[1]);
			glNormalPointer(GL_FLOAT,sizeof(MyMesh::VertexType),0);
			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[0]);
			glVertexPointer(3,GL_FLOAT,sizeof(MyMesh::VertexType),0);

			glDrawElements(GL_POINTS ,m_pmymesh->fn*3,GL_UNSIGNED_INT, &(*indices.begin()) );

			glDisableClientState (GL_VERTEX_ARRAY);
			glDisableClientState (GL_NORMAL_ARRAY);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		else if(m_drawmode==DMHidden)
		{
			glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT | GL_LIGHTING_BIT );
			glEnable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(1.0, 1);
			//glDepthRange(ZTWIST,1.0f);
			glDisable(GL_LIGHTING);
			glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
			glColor4f(0,0,1,0.5);
			glEnableClientState (GL_NORMAL_ARRAY);
			glEnableClientState (GL_VERTEX_ARRAY);

			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[1]);
			glNormalPointer(GL_FLOAT,sizeof(MyMesh::VertexType),0);
			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[0]);
			glVertexPointer(3,GL_FLOAT,sizeof(MyMesh::VertexType),0);

			glDrawElements(GL_TRIANGLES ,m_pmymesh->fn*3,GL_UNSIGNED_INT, &(*indices.begin()) );

			glDisableClientState (GL_VERTEX_ARRAY);
			glDisableClientState (GL_NORMAL_ARRAY);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glDisable(GL_POLYGON_OFFSET_FILL);
			glEnable(GL_LIGHTING);
			glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
			////glDepthRange(0.0f,1.0f-ZTWIST);
			glColor4f(1,0,1,0.5);
			glEnableClientState (GL_NORMAL_ARRAY);
			glEnableClientState (GL_VERTEX_ARRAY);

			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[1]);
			glNormalPointer(GL_FLOAT,sizeof(MyMesh::VertexType),0);
			glBindBuffer(GL_ARRAY_BUFFER,array_buffers[0]);
			glVertexPointer(3,GL_FLOAT,sizeof(MyMesh::VertexType),0);

			glDrawElements(GL_LINES ,m_pmymesh->fn*3,GL_UNSIGNED_INT, &(*indices.begin()) );

			glDisableClientState (GL_VERTEX_ARRAY);
			glDisableClientState (GL_NORMAL_ARRAY);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glPopAttrib();
		}
	}
}

void SphereMesh::drawSpheres()
{
	for(unsigned int i = 0; i < m_sphereset.size(); ++i)
	{
		if(m_sphereset[i] != NULL)
		{
			if(m_drawmode==DMSmooth)
			{
				m_sphereset[i]->drawFill();
			}
			else if(m_drawmode==DMWire)
			{
				m_sphereset[i]->drawWireFrame();
			}
		}
		
	}
}

void SphereMesh::openMeshPLY(const std::string& filepath)
{
	if(filepath.empty()) return;
	MyMesh* mesh = new MyMesh();
	int b = vcg::tri::io::ImporterPLY<MyMesh>::Open(*mesh, filepath.c_str(), m_mask);
	if(b)
	{
		std::cout<<vcg::tri::io::ImporterPLY<MyMesh>::ErrorMsg(b)<<std::endl;
		//m_pmymesh = NULL;
	}
	if(b==1) 
	{
		m_pmymesh = NULL;
		return;
	}
	if(m_pmymesh!=NULL) 
	{
		delete m_pmymesh;
	}
	m_pmymesh = mesh;
	update();
	//}
}

void SphereMesh::saveMeshPLY(const std::string& filepath)
{
	vcg::tri::io::ExporterPLY<MyMesh>::Save(*m_pmymesh, filepath.c_str());
}

void SphereMesh::openMeshOBJ(const std::string& filepath)
{
	if(filepath.empty()) return;
	MyMesh* mesh = new MyMesh();
	int b = vcg::tri::io::ImporterOBJ<MyMesh>::Open(*mesh, filepath.c_str(), m_mask);
	if(b)
	{
		std::cout<<vcg::tri::io::ImporterOBJ<MyMesh>::ErrorMsg(b)<<std::endl;
		//m_pmymesh = NULL;
	}
	if(b==1) 
	{
		m_pmymesh = NULL;
		return;
	}
	if(m_pmymesh!=NULL) 
	{
		delete m_pmymesh;
	}
	m_pmymesh = mesh;
	update();
		
	//}
}

void SphereMesh::openMeshOFF(const std::string& filepath)
{
	if(filepath.empty()) return;
	MyMesh* mesh = new MyMesh();
	int b = vcg::tri::io::ImporterOFF<MyMesh>::Open(*mesh, filepath.c_str(), m_mask);
	if(b)
	{
		std::cout<<vcg::tri::io::ImporterOFF<MyMesh>::ErrorMsg(b)<<std::endl;
		//m_pmymesh = NULL;
	}
	if(b==1) 
	{
		m_pmymesh = NULL;
		return;
	}
	//else
	//{
	if(m_pmymesh!=NULL) 
	{
		delete m_pmymesh;
	}
	m_pmymesh = mesh;
	update();
	//}
}

void SphereMesh::init()
{

}

void SphereMesh::update()
{
	vcg::tri::UpdateBounding<MyMesh>::Box(*m_pmymesh);
	vcg::tri::RequirePerVertexNormal(*m_pmymesh);
	vcg::tri::UpdateNormal<MyMesh>::PerVertexNormalized(*m_pmymesh);
	indices.clear();
	for(MyMesh::FaceIterator fi = m_pmymesh->face.begin(); fi != m_pmymesh->face.end(); ++fi)
	{
		indices.push_back((unsigned int)((*fi).V(0) - &(*m_pmymesh->vert.begin())));
		indices.push_back((unsigned int)((*fi).V(1) - &(*m_pmymesh->vert.begin())));
		indices.push_back((unsigned int)((*fi).V(2) - &(*m_pmymesh->vert.begin())));
	}

	if(!glIsBuffer(array_buffers[1]))
		glGenBuffers(2,(GLuint*)array_buffers);
	glBindBuffer(GL_ARRAY_BUFFER,array_buffers[0]);
	glBufferData(GL_ARRAY_BUFFER_ARB, m_pmymesh->vn * sizeof(MyMesh::VertexType),
		(char *)&(m_pmymesh->vert[0].P()), GL_STATIC_DRAW_ARB);

	glBindBuffer(GL_ARRAY_BUFFER,array_buffers[1]);
	glBufferData(GL_ARRAY_BUFFER_ARB, m_pmymesh->vn * sizeof(MyMesh::VertexType),
		(char *)&(m_pmymesh->vert[0].N()), GL_STATIC_DRAW_ARB);


	glVertexPointer(3,GL_FLOAT,sizeof(MyMesh::VertexType),0);
	glNormalPointer(GL_FLOAT,sizeof(MyMesh::VertexType),0);
	vcg::Box3f box = m_pmymesh->bbox;
	vcg::Point3f maxp = box.max;
	vcg::Point3f minp = box.min;
	vcg::Point3f len = maxp - minp;
	meshScale = len.Norm();
}

void SphereMesh::clear()
{
	for(int i=0;i<3;++i)
		if(glIsBuffer(GLuint(array_buffers[i])))
			glDeleteBuffersARB(1, (GLuint *)(array_buffers+i));
}


void SphereMesh::loadSpheres(const std::string& filepath)
{

}