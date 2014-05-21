//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CBuffer.cpp
// Description	: Implements the CBuffer class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "CBuffer.h"
			
// This Includes

namespace OpenGL
{	
	// Static Variables
				
	// Static Function Prototypes
				
	// Implementation
	CBuffer::CBuffer()
	{
		glGenBuffers(1, &m_glBuffer);		
	}
				
	CBuffer::~CBuffer()
	{
		glDeleteBuffers(1, &m_glBuffer);
	}

	GLvoid CBuffer::Map(GLenum _eTarget, GLuint _uiSize, GLvoid* _pData, GLenum _eUsage)
	{
		m_glTarget = _eTarget;
		Bind();
		glBufferData(_eTarget, _uiSize, _pData, _eUsage);
	}

	GLvoid CBuffer::Bind()
	{
		glBindBuffer(m_glTarget, m_glBuffer);
	}
};
