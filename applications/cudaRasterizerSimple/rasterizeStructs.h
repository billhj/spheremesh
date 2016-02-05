#pragma once
#include "glm/glm.hpp"

struct vertex {
	glm::vec3 pos;
	glm::vec3 color;
	//For Blinn-Phong
	glm::vec3 eyeNormal;
	glm::vec3 eyeLightDirection;
	glm::vec3 eyeHalfVector;
};

struct triangle {
	vertex v0;
	vertex v1;
	vertex v2;
};

struct fragment{
	//Together this is a 64-bit depth sortable tag
	union{
		struct{
			int primitiveIndex;
			float depth;
		};
		unsigned long long int depthPrimTag;
	};
	glm::vec2 position;
	glm::vec3 color;
	glm::vec3 normal;
	glm::vec3 lightDir;
	glm::vec3 halfVector;
};

struct uniforms{
	glm::mat4 viewTransform;
	glm::mat4 perspectiveTransform;
	glm::mat4 modelTransform;
	glm::vec4 lightPos;
	glm::vec3 lightColor;
	glm::vec3 blinnPhongParams;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	float shininess;
};


enum FRAGMENT_SHADER {DEPTH_SHADING, AMBIENT_LIGHTING, BLINN_PHONG_SHADING, NORMAL_SHADING};
enum RASTER_MODE {NAIVE, BIN };
struct pipelineOpts{
	FRAGMENT_SHADER fShaderProgram;
	RASTER_MODE rasterMode;
	bool showTriangleColors;
	bool backfaceCulling;
	bool totalClipping;
	bool recordMetrics;
};


struct PerformanceMetrics{
	float rasterTimeSeconds;
	int NumTriangles;
	int NumTrianglesRastered;
	float avgPixelsPerTri;
	float maxPixelsPerTri;
};