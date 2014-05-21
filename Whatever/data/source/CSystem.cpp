//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: system.cpp
// Description	: Implements the CSystem class.
// Author		: Rian Drake
// Mail			: rian.drake@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "CCubeApplication.h"

// This Includes
#include "CSystem.h"

namespace Application
{
	// Static Variables
	static CSystem* ApplicationHandle = 0;

	// Static Function Prototypes

	// Implementation
	CSystem::CSystem() :
		m_pApplication(0),
		m_bFullscreen(false)
	{

	}

	CSystem::~CSystem()
	{
		glfwTerminate();
	}

	GLboolean CSystem::Initialise()
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		if(m_bFullscreen)
			window = glfwCreateWindow(1600, 900, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
		else
			window = glfwCreateWindow(1600, 900, "OpenGL", nullptr, nullptr); // Windowed

		glfwMakeContextCurrent(window);

		glewExperimental = GL_TRUE;

		if(glewInit())
		{
			return false;
		}

		m_pApplication = new CCubeApplication;

		if(!m_pApplication->Initialise())
		{
			return false;
		}

		return true;
	}

	GLvoid CSystem::Shutdown()
	{
		if(m_pApplication)
			m_pApplication->Shutdown();

		glfwTerminate();

		delete m_pApplication;
		m_pApplication = 0;
	}

	GLvoid CSystem::Run()
	{
		GLfloat f = 0.125f;
		glClearColor(f, f, f, 1);
		m_Timer.Reset();

		while(!glfwWindowShouldClose(window))
		{
			glfwPollEvents();

			if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_pApplication->Frame((GLfloat)m_Timer.Tick());

			glfwSwapBuffers(window);
		}
	}

	GLboolean CSystem::Frame()
	{
		return true;
	}
};