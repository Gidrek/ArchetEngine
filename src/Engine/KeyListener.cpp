//
// Created by giovanni on 16/03/21.
//

#include "KeyListener.h"

KeyListener::KeyListener()
: mKeyPressed()
{

}

KeyListener::~KeyListener()
= default;

KeyListener& KeyListener::Instance()
{
	static auto *keyListener = new KeyListener();
	return *keyListener;
}

void KeyListener::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		Instance().mKeyPressed[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		Instance().mKeyPressed[key] = false;
	}

}
bool KeyListener::IsKeyPressed(int keycode)
{
	return Instance().mKeyPressed[keycode];
}
