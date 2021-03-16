//
// Created by giovanni on 16/03/21.
//

#ifndef ARCHETENGINE_WINDOW_H
#define ARCHETENGINE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
  public:
	~Window();

	static Window& Instance();
	void Run();

  private:
	Window();
	void Init();
	void ProcessEvents();
	void Update();
	void Render();

	int mWidth;
	int mHeight;
	std::string mTitle;
	GLFWwindow* mWindow;

};


#endif //ARCHETENGINE_WINDOW_H
