#ifndef __Application_H__
#define __Application_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: Application.h
// Description	: Defines the IApplication GLinterface.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "GL\glew.h"
			
namespace Application
{
	// Types
			
	// Constants
			
	// Prototypes
	class IApplication
	{
		public:
			IApplication() {};
			virtual ~IApplication() {};

			virtual GLboolean Initialise() = 0;
			virtual GLvoid Shutdown() = 0;
			virtual GLboolean Frame(GLfloat _fDt) = 0;
					
		protected:
		private:
				
		public:
		protected:
		private:
	};
};
		
#endif // __Application_H__