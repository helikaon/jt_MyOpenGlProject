#ifndef __CTexture_H__
#define __CTexture_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CTexture.h
// Description	: Defines the CTexture class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//

#ifdef _DEBUG
#pragma comment(lib, "data/lib/debug/SOIL.lib")
#else
#pragma comment(lib, "data/lib/release/SOIL.lib")
#endif
// Library Includes
			
// Local Includes
#include "soil\SOIL.h"
#include "GL\glew.h"

namespace OpenGL
{
	// Types
				
	// Constants
				
	// Prototypes
	class CTexture
	{
		public:
			CTexture();
			~CTexture();

			GLvoid Initialise(const GLchar* _pcFilename);
			GLuint GetTexture();
						
		protected:
		private:
					
		public:
		protected:
		private:
			GLuint m_glTexture;
	};
};

#endif // __Texture_H__
		