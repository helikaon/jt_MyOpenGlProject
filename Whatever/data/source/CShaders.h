#ifndef __CShaders_H__
#define __CShaders_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CShaders.h
// Description	: Defines the CShaders class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//

// Library Includes
#include <map>

// Local Includes
#include "CTexture.h"

namespace OpenGL
{
	// Types
	enum EShaders
	{
		SHADERS_VERTEX,
		SHADERS_FRAGMENT,
		SHADERS_GEOMETRY,
		SHADERS_MAX
	};

	// Constants

	// Prototypes
	class CShaders
	{
	public:
		CShaders();
		~CShaders();

		GLvoid AttachAttribute(
			const GLchar* _pAttribute,
			GLuint _uiSize,
			GLenum _eType,
			GLsizei _iStride,
			GLvoid* _glOffset,
			GLboolean _glNormalized = false);

		GLvoid AttachShader(EShaders _eShader, const GLchar* _pFile);
		GLvoid AttachUniform(const GLchar* _pcName);
		GLvoid AttachTexture(const GLchar* _pcName);
		GLint GetUniform(const GLchar* _pcName);

		GLvoid LinkProgram();
		GLvoid BindProgram();

	protected:
		GLvoid AttachShaderSource(EShaders _eShader, const GLchar* _pSource);
		GLvoid ReadShader(const GLchar* _pFile, std::string& _rShader);

	private:

	public:
	protected:
	private:
		GLuint m_glShaderProgram;
		std::map<std::string, GLint> m_glUniforms;

		CTexture* m_pTextures;
		GLuint m_uiNumTextures;
		static GLuint s_uiTotalNumTextures;
	};
};

#endif // __Shaders_H__