#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object_6.h"
#include "FileManager_6.h"
#include "Renderer_6.h"
#include "Sphere.h"
#include "ICleanUp.h"
#include "Sphere.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();

	RenderableObject* cube = new RenderableObject();

	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"20183288_vs.shader",
		"20183288_fs.shader"
	);

	Sphere* sphere = new Sphere();

	NonRenderableObject* non_render_obj = new NonRenderableObject();

	while (true)
	{
		renderer->render(cube);
		renderer->render(sphere);
	}

	non_render_obj->shutDown();
	cube->shutDown();
	sphere->shutDown();
	renderer->shutDown();

	delete cube;

	return 0;
}