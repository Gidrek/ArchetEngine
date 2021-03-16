//
// Created by giovanni on 16/03/21.
//

#include "MouseListener.h"

MouseListener::MouseListener()
: mScrollX(0.0), mScrollY(0.0), mXPos(0.0), mYPos(0.0), mLastX(0.0), mLastY(0.0),
  mIsDragging(false), mMouseButtonPressed()
{
}

MouseListener::~MouseListener()
= default;

MouseListener& MouseListener::Instance()
{
	static auto *mouseListener = new MouseListener();
	return *mouseListener;
}

void MouseListener::MousePosCallback(GLFWwindow* window, double xPos, double yPos)
{
	Instance().mLastX = Instance().mXPos;
	Instance().mLastY = Instance().mYPos;
	Instance().mXPos = xPos;
	Instance().mYPos = yPos;
	Instance().mIsDragging = Instance().mMouseButtonPressed[0] || Instance().mMouseButtonPressed[1] || Instance().mMouseButtonPressed[2];
}

void MouseListener::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		// Only support for a 3 buttons mouse
		if (button < TotalMouseButtons)
		{
			Instance().mMouseButtonPressed[button] = true;
		}
	}
	else if (action == GLFW_RELEASE)
	{
		if (button < TotalMouseButtons)
		{
			Instance().mMouseButtonPressed[button] = false;
			Instance().mIsDragging = false;
		}
	}
}

void MouseListener::MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	Instance().mScrollX = xOffset;
	Instance().mScrollY = yOffset;
}
void MouseListener::EndFrame()
{
	Instance().mScrollX = 0;
	Instance().mScrollY = 0;
	Instance().mLastX = Instance().mXPos;
	Instance().mLastY = Instance().mYPos;
}

float MouseListener::GetX()
{
	return static_cast<float>(Instance().mXPos);
}

float MouseListener::GetY()
{
	return static_cast<float>(Instance().mYPos);
}

float MouseListener::GetDeltaX()
{
	return static_cast<float>(Instance().mLastX - Instance().mXPos);
}

float MouseListener::GetDeltaY()
{
	return static_cast<float>(Instance().mLastY - Instance().mYPos);
}

float MouseListener::GetScrollX()
{
	return static_cast<float>(Instance().mScrollX);
}

float MouseListener::GetScrollY()
{
	return static_cast<float>(Instance().mScrollY);
}

bool MouseListener::GetIsDragging()
{
	return Instance().mIsDragging;
}

bool MouseListener::GetMouseButtonDown(int button)
{
	if (button < TotalMouseButtons)
	{
		return Instance().mMouseButtonPressed[button];
	}
	return false;
}


