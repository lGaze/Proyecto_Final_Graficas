#pragma once
#include "CApp.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <windows.h>
#include "CManager.h"
#include "defines.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>



class CApp_Opengl : public CApp
{
public:

	CApp_Opengl();
	~CApp_Opengl();

	bool Init();
	bool InitWindow();
	int run();
	void Render();


private:
  CManager m_Manager;
	GLFWwindow * window;
  glm::mat4x4 m_view, m_projection;

};


