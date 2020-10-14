#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"


class Object 
{
public:
	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint Texture;
	GLuint TextureID;

	std::vector<glm::vec3>vertices;
	std::vector<glm::vec2>uvs;
	std::vector<glm::vec3>normals;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint LightID;

public:
	void shutDown();
};