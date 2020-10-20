struct GLFWwindow;
class Object;

class Renderer
{
private:
	GLFWwindow* window;

public:
	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}
public:

	void render(RenderableObject* src_obj);
	void init();
	void shutDown();
};
