//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CTexture.cpp
// Description	: Implements the CTexture class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "CTexture.h"
			
// This Includes

namespace OpenGL
{	
	// Static Variables
				
	// Static Function Prototypes
				
	// Implementation
	CTexture::CTexture()
		: m_glTexture(0)
	{
				
	}
				
	CTexture::~CTexture()
	{
		glDeleteTextures(1, &m_glTexture);
	}

	GLvoid CTexture::Initialise(const GLchar* _pcFilename)
	{
		int width, height;
		GLubyte* image = SOIL_load_image(_pcFilename, &width, &height, 0, SOIL_LOAD_RGB);

		glBindTexture(GL_TEXTURE_2D, m_glTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	GLuint CTexture::GetTexture()
	{
		return m_glTexture;
	}
};
