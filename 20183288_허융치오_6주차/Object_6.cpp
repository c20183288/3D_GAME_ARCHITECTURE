#include "Object_6.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"

void RenderableObject::shutDown()
{
	//cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}

