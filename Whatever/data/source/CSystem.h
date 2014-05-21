//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: system.h
// Description	: Defines the CSystem class.
// Author		: Rian Drake
// Mail			: rian.drake@mediadesign.school.nz
//

#pragma once

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#define WIN32_LEAN_AND_MEAN

#pragma comment(lib, "data/lib/glfw3.lib")
#pragma comment(lib, "data/lib/glfw3dll.lib")
#pragma comment(lib, "data/lib/glew32.lib")
#pragma comment(lib, "data/lib/glew32s.lib")
#pragma comment(lib, "opengl32")

#define GLEW_STATIC
#define GLFW_DLL

// Library Includes
#include <Windows.h>

// Local Includes
#include "IApplication.h"
#include "CTimer.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace Application
{
	// Types

	// Constants

	// Prototypes
	class CSystem
	{
		// Member Functions
	public:
		// Constructors/Destructors
		CSystem();
		~CSystem();

		// Methods
		GLboolean Initialise();
		GLvoid Shutdown();
		GLvoid Run();

	protected:
	private:
		GLboolean Frame();

		// Member Variables
	public:
	protected:
	private:
		IApplication* m_pApplication;

		GLint m_iWidth, m_iHeight;
		GLboolean m_bFullscreen;

		GLFWwindow* window;

		CTimer m_Timer;
	};
};

#endif // __SYSTEM_H__