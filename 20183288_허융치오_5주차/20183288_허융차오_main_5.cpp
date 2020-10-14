#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object_5.h"
#include "FileManager_5.h"
#include "Renderer_5.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();

	Object* cube = new Object();

	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"20183288_vs.shader",
		"20183288_fs.shader"
	);

	while (true)
	{
		renderer->render(cube);
	}

	cube->shutDown();
	renderer->shutDown();

	delete cube;

	return 0;
}