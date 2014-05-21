//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CBatch.cpp
// Description	: Implements the CBatch class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "CBatch.h"
#include "CShaders.h"
#include "CBuffer.h"

// This Includes

namespace OpenGL
{
	// Static Variables

	// Static Function Prototypes

	// Implementation
	CBatch::CBatch() :
		m_pBuffers(0),
		m_pShaders(0),
		m_uiNumBuffers(0),
		m_ppTextures(0),
		m_uiNumTextures(0),
		m_glVertexArrayObject(0),
		m_uiActiveShader(0)
	{
		glGenVertexArrays(1, &m_glVertexArrayObject);
		glBindVertexArray(m_glVertexArrayObject);
	}

	CBatch::~CBatch()
	{
		for(GLuint ui = 0; ui < m_uiNumTextures; ++ui)
		{
			GLuint glTexture = m_ppTextures[ui]->GetTexture();
			glDeleteTextures(1, &glTexture);
		}

		glDeleteVertexArrays(1, &m_glVertexArrayObject);

		delete[] m_pShaders; m_pShaders = 0;
		delete[] m_pBuffers; m_pBuffers = 0;
	}

	GLvoid CBatch::AttachShaders(GLuint _uiNumShaders)
	{
		m_pShaders = new CShaders[_uiNumShaders];
	}

	GLvoid CBatch::AttachBuffers(GLuint _uiNumBuffers)
	{
		m_pBuffers = new CBuffer[_uiNumBuffers];
	}

	GLvoid CBatch::DrawBatch(GLenum _eTopology, GLuint _uiFirstVertex, GLsizei _iCount)
	{
		Bind();
		glDrawArrays(_eTopology, _uiFirstVertex, _iCount);
		Unbind();
	}

	GLvoid CBatch::DrawIndexedBatch(GLenum _eTopology, GLsizei _iCount, GLenum _eType, const GLvoid* _glOffset)
	{
		Bind();
		glDrawElements(_eTopology, _iCount, _eType, _glOffset);
		Unbind();
	}
	
	GLvoid CBatch::AttachTextures(CTexture** _ppTextures, GLuint _uiCount)
	{
		m_ppTextures = _ppTextures;
		m_uiNumTextures = 0;
	}

	GLvoid CBatch::Bind()
	{
		glBindVertexArray(m_glVertexArrayObject);

		if(m_pShaders)
			m_pShaders[m_uiActiveShader].BindProgram();
	}

	GLvoid CBatch::Unbind()
	{
		glBindVertexArray(0);
	}

	CShaders* CBatch::GetShaders(GLuint _uiIndex)
	{
		return &m_pShaders[_uiIndex];
	}

	CBuffer* CBatch::GetBuffers(GLuint _uiIndex)
	{
		return &m_pBuffers[_uiIndex];
	}
};