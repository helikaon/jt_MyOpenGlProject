//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CShaders.cpp
// Description	: Implements the CShaders class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//

// Library Includes
#include <fstream>
#include <cassert>
#include <Windows.h>
#include <string>

// Local Includes
#include "CShaders.h"

// This Includes

namespace OpenGL
{	
	// Static Variables
	GLuint CShaders::s_uiTotalNumTextures = 0;

	// Static Function Prototypes

	// Implementation
	CShaders::CShaders():
		m_glShaderProgram(0),
		m_uiNumTextures(0),
		m_pTextures(0)
	{
		m_glShaderProgram = glCreateProgram();
	}

	CShaders::~CShaders()
	{
		glDeleteProgram(m_glShaderProgram);
	}

	GLvoid CShaders::AttachAttribute(const GLchar* _pAttribute, GLuint _uiSize, GLenum _eType, GLsizei _iStride, GLvoid* _glOffset, GLboolean _glNormalized)
	{
		GLint glAttribute = glGetAttribLocation(m_glShaderProgram, _pAttribute);

		if(glAttribute == -1)
		{
			MessageBox(0, L"Could not find attribute.", L"Shader Error", 0);
		}

		glEnableVertexAttribArray(glAttribute);
		glVertexAttribPointer(glAttribute, _uiSize, _eType, _glNormalized, _iStride, _glOffset);
	}

	GLvoid CShaders::AttachUniform(const GLchar* _pcName)
	{
		m_glUniforms[_pcName] = glGetUniformLocation(m_glShaderProgram, _pcName);

		if(m_glUniforms[_pcName] == -1)
			MessageBox(0, L"Uniform was not found.", L"Shader Error", 0);
	}

	GLint CShaders::GetUniform(const GLchar* _pcName)
	{
		return m_glUniforms[_pcName];
	}
			
	GLvoid CShaders::AttachTexture(const GLchar* _pcName)
	{
		CTexture* pTextures = new CTexture[m_uiNumTextures + 1];

		for(GLuint ui = 0; ui < m_uiNumTextures; ++ui)
			pTextures[ui] = m_pTextures[ui];

		pTextures[m_uiNumTextures].Initialise(_pcName);

		if(pTextures[m_uiNumTextures].GetTexture() == -1)
			MessageBox(0, L"Texture was not found.", L"Shader Error", 0);
		
		delete[] m_pTextures;
		m_pTextures = pTextures;
		++m_uiNumTextures;

		if(m_uiNumTextures > s_uiTotalNumTextures)
			s_uiTotalNumTextures = m_uiNumTextures;
	}

	GLvoid CShaders::LinkProgram()
	{
		glLinkProgram(m_glShaderProgram);
		BindProgram();
	}

	GLvoid CShaders::BindProgram()
	{
		glUseProgram(m_glShaderProgram);

		glBindTexture(GL_TEXTURE_2D, 0);

		GLuint ui = 0;
		for(ui; ui < m_uiNumTextures; ++ui)
		{
			glBindTexture(GL_TEXTURE_2D + ui, m_pTextures[ui].GetTexture());
		}

		for(ui; ui < s_uiTotalNumTextures; ++ui)
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}

	GLvoid CShaders::AttachShader(EShaders _eShader, const GLchar* _pFile)
	{
		GLuint glShader = 0;

		switch(_eShader)
		{
		case SHADERS_VERTEX:
			glShader = glCreateShader(GL_VERTEX_SHADER);
			break;
		case SHADERS_GEOMETRY:
			glShader = glCreateShader(GL_GEOMETRY_SHADER);
			break;
		case SHADERS_FRAGMENT:
			glShader = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		default:assert(0);
		}

		std::string sShader;
		ReadShader(_pFile, sShader);
		const GLchar* pShader = sShader.c_str();

		glShaderSource(glShader, 1, &pShader, nullptr);
		glCompileShader(glShader);

		GLint status = 0;
		glGetShaderiv(glShader, GL_COMPILE_STATUS, &status);

		if(!status)
		{
			GLchar buffer[512];
			glGetShaderInfoLog(glShader, 512, NULL, buffer);

			MessageBox(0, L"Shader failed to compile.", L"Shader Error", 0);
		}
		
		glAttachShader(m_glShaderProgram, glShader);
	}

	GLvoid CShaders::AttachShaderSource(EShaders _eShader, const GLchar* _pSource)
	{
		GLuint glShader = 0;

		switch(_eShader)
		{
		case SHADERS_VERTEX:
			glShader = glCreateShader(GL_VERTEX_SHADER);
			break;
		case SHADERS_GEOMETRY:
			glShader = glCreateShader(GL_GEOMETRY_SHADER);
			break;
		case SHADERS_FRAGMENT:
			glShader = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		default:assert(0);
		}

		glShaderSource(glShader, 1, &_pSource, nullptr);
		glCompileShader(glShader);

		GLint status = 0;
		glGetShaderiv(glShader, GL_COMPILE_STATUS, &status);

		if(!status)
		{
			GLchar buffer[512];
			glGetShaderInfoLog(glShader, 512, NULL, buffer);

			MessageBox(0, L"Shader failed to compile.", L"Shader Error", 0);
		}

		glAttachShader(m_glShaderProgram, glShader);
	}

	GLvoid CShaders::ReadShader(const GLchar* _pFile, std::string& _rsShader)
	{
		std::fstream myFile(_pFile);
		std::string sLine, sShader;

		if(!myFile || myFile.bad())
		{
			MessageBox(0, L"Shader file was not found.", L"Shader Error", 0);
		}

		while(!myFile.eof())
		{
			std::getline(myFile, sLine);
			sShader += sLine + '\n';
		}

		_rsShader = sShader.c_str();
	}
};
