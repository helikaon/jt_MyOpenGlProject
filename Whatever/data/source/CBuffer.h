#ifndef __CBuffer_H__
#define __CBuffer_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CBuffer.h
// Description	: Defines the CBuffer class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "GL\glew.h"

namespace OpenGL
{
	// Types
	enum EBuffers
	{
		BUFFER_VERTEX,
		BUFFER_INDEX,
	};
				
	// Constants
				
	// Prototypes
	class CBuffer
	{
		public:
			CBuffer();
			~CBuffer();

			GLvoid Map(GLenum _eTarget, GLuint _uiSize, GLvoid* _pData, GLenum _eUsage);
			GLvoid Bind();
						
		protected:
		private:
					
		public:
		protected:
		private:
			GLenum m_glTarget;
			GLuint m_glBuffer;
	};
};

#endif // __Buffer_H__
		