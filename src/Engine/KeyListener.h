//
// Created by giovanni on 16/03/21.
//

#ifndef _KEYLISTENER_H_
#define _KEYLISTENER_H_

#include <GLFW/glfw3.h>

class KeyListener
{
 public:
	~KeyListener();

	static KeyListener& Instance();
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool IsKeyPressed(int keycode);

 private:
	KeyListener();

	bool mKeyPressed[350];
};

#endif //_KEYLISTENER_H_
