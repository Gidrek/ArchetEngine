//
// Created by giovanni on 16/03/21.
//

#include "Window.h"

#include <iostream>
#include "MouseListener.h"
#include "KeyListener.h"

Window::Window()
: mWidth(1920), mHeight(1080), mTitle("Archet Engine"), mWindow()
{
}

Window::~Window()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
	std::cout << "Bye! Engine" << std::endl;
}

Window& Window::Instance()
{
	static auto *window = new Window();
	return *window;
}

void Window::Run()
{
	Init();

	// Loop until the user closes the window
	while(!glfwWindowShouldClose(mWindow))
	{
		ProcessEvents();
		Update();
		Render();
	}
}

void Window::Init()
{
	// Initialize the library
	if(!glfwInit())
		throw std::runtime_error("Error initialing GLFW");

	// Define version and compatibility settings
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create a windowed mode window and its OpenGL context
	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
	if (!mWindow)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	// Mathe the window's context current
	glfwMakeContextCurrent(mWindow);

	// Callbacks
	glfwSetCursorPosCallback(mWindow, MouseListener::MousePosCallback);
	glfwSetMouseButtonCallback(mWindow, MouseListener::MouseButtonCallback);
	glfwSetScrollCallback(mWindow, MouseListener::MouseScrollCallback);
	glfwSetKeyCallback(mWindow, KeyListener::KeyCallback);

	//  Enable V-Sync
	glfwSwapInterval(1);

	// Initialize the OpenGL API with GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to initialize GLAD");
	}
}

void Window::ProcessEvents()
{
	// Poll for and process events
	glfwPollEvents();
}

void Window::Update()
{

}

void Window::Render()
{

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Render here!

	// Swap front and back buffers
	glfwSwapBuffers(mWindow);
}
