//
// Created by giovanni on 16/03/21.
//

#ifndef _MOUSELISTENER_H_
#define _MOUSELISTENER_H_

#include <GLFW/glfw3.h>

class MouseListener
{
 public:
	~MouseListener();

	static MouseListener& Instance();
	static void MousePosCallback(GLFWwindow* window, double xPos, double yPos);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void MouseScrollCallback(GLFWwindow *window, double xOffset, double yOffset);
	static void EndFrame();
	static float GetX();
	static float GetY();
	static float GetDeltaX();
	static float GetDeltaY();
	static float GetScrollX();
	static float GetScrollY();
	static bool GetIsDragging();
	static bool GetMouseButtonDown(int button);

 private:
	static const int TotalMouseButtons = 3;

	MouseListener();

	double mScrollX;
	double mScrollY;
	double mXPos;
	double mYPos;
	double mLastX;
	double mLastY;
	bool mMouseButtonPressed[TotalMouseButtons];
	bool mIsDragging;

};

#endif //_MOUSELISTENER_H_
