#ifndef __CBatch_H__
#define __CBatch_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CBatch.h
// Description	: Defines the CBatch class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
#include "GL\glew.h"

// Local Includes
#include "CShaders.h"
#include "CBuffer.h"
#include "CTexture.h"
			
inline void Test()
{
	int i = 0;
	i = 9 + 8;


}

namespace OpenGL
{
	// Types
			
	// Constants
			
	// Prototypes
	class CBatch
	{
		public:
			CBatch();
			~CBatch();

			GLvoid Bind();
			GLvoid Unbind();

			GLvoid AttachBuffers(GLuint _uiNumShaders);
			GLvoid AttachShaders(GLuint _uiNumBuffers);

			CBuffer* GetBuffers(GLuint _uiIndex);
			CShaders* GetShaders(GLuint _uiIndex);

			GLvoid DrawBatch(GLenum _eTopology, GLuint _uiFirstVertex, GLsizei _iCount);
			GLvoid DrawIndexedBatch(GLenum _eTopology, GLsizei _iCount, GLenum _eType = GL_UNSIGNED_INT, const GLvoid* _glOffset = 0);

			GLvoid AttachTextures(CTexture** _ppTextures, GLuint _uiCount);

			GLvoid SetActiveShader(GLuint _uiShader)
			{
				m_uiActiveShader = _uiShader;
			}
					
		protected:
		private:
				
		public:
		protected:
		private:
			GLuint	m_glVertexArrayObject;

			CBuffer* m_pBuffers;
			GLuint m_uiNumBuffers;

			CTexture** m_ppTextures;
			GLuint m_uiNumTextures;

			CShaders* m_pShaders;

			GLuint m_uiActiveShader;
	};
};

#endif // __Batch_H__