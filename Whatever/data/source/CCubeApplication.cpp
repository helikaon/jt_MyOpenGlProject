//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CubeApplication.cpp
// Description	: Implements the CCubeApplication class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
#include <Windows.h>
			
// Local Includes
#include "CCubeApplication.h"
#include "CBatch.h"
#include "CShaders.h"
#include "CTimer.h"
#include "CBuffer.h"
			
// This Includes

namespace Application
{
	// Static Variables

	// Static Function Prototypes

	// Implementation
	CCubeApplication::CCubeApplication():
		m_f3Eye(0,0,-1)
	{
		m_ppBatches[BATCH_ONE] = 0;
		m_ppBatches[BATCH_TWO] = 0;

		glEnable(GL_DEPTH_TEST);
	}
			
	CCubeApplication::~CCubeApplication()
	{
		Shutdown();
	}
		
	GLboolean CCubeApplication::Initialise()
	{
		return InitialiseBatch();
	}

	GLboolean CCubeApplication::InitialiseBatch()
	{
		m_matMatrices[MATRIX_PROJ] = glm::perspective(glm::radians(45.0f), 1600.0f/900.0f, 0.1f, 1000.0f);
		m_matMatrices[MATRIX_VIEW] = glm::lookAt(m_f3Eye, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		m_matMatrices[MATRIX_WVP] = m_matMatrices[MATRIX_PROJ] * m_matMatrices[MATRIX_VIEW] * m_matMatrices[MATRIX_WORLD];

		GLfloat points[] = 
		{
			-1, -1, -1,		0, 0, 0,
			-1, -1,  1,		0, 0, 1,
			-1,  1, -1,		0, 1, 0,
			-1,  1,  1,		0, 1, 1,
			 1, -1, -1,		1, 0, 0,
			 1, -1,  1,		1, 0, 1,
			 1,  1, -1,		1, 1, 0,
			 1,  1,  1,		1, 1, 1,
			 
			-4, -1, -1,		0, 0, 0,
			-4, -1,  1,		0, 0, 1,
			-4,  1, -1,		0, 1, 0,
			-4,  1,  1,		0, 1, 1,
			 4, -1, -1,		1, 0, 0,
			 4, -1,  1,		1, 0, 1,
			 4,  1, -1,		1, 1, 0,
			 4,  1,  1,		1, 1, 1,
			 
			-1, -4, -1,		0, 0, 0,
			-1, -4,  1,		0, 0, 1,
			-1,  4, -1,		0, 1, 0,
			-1,  4,  1,		0, 1, 1,
			 1, -4, -1,		1, 0, 0,
			 1, -4,  1,		1, 0, 1,
			 1,  4, -1,		1, 1, 0,
			 1,  4,  1,		1, 1, 1,
			 
			-4, -4, -1,		0, 0, 0,
			-4, -4,  1,		0, 0, 1,
			-4,  4, -1,		0, 1, 0,
			-4,  4,  1,		0, 1, 1,
			 4, -4, -1,		1, 0, 0,
			 4, -4,  1,		1, 0, 1,
			 4,  4, -1,		1, 1, 0,
			 4,  4,  1,		1, 1, 1,
			-1, -1, -1,		0, 0, 0,
			-1, -1,  1,		0, 0, 1,
			-1,  1, -1,		0, 1, 0,
			-1,  1,  1,		0, 1, 1,
			 1, -1, -1,		1, 0, 0,
			 1, -1,  1,		1, 0, 1,
			 1,  1, -1,		1, 1, 0,
			 1,  1,  1,		1, 1, 1,
			 
			-4, -1, -1,		0, 0, 0,
			-4, -1,  1,		0, 0, 1,
			-4,  1, -1,		0, 1, 0,
			-4,  1,  1,		0, 1, 1,
			 4, -1, -1,		1, 0, 0,
			 4, -1,  1,		1, 0, 1,
			 4,  1, -1,		1, 1, 0,
			 4,  1,  1,		1, 1, 1,
			 
			-1, -4, -1,		0, 0, 0,
			-1, -4,  1,		0, 0, 1,
			-1,  4, -1,		0, 1, 0,
			-1,  4,  1,		0, 1, 1,
			 1, -4, -1,		1, 0, 0,
			 1, -4,  1,		1, 0, 1,
			 1,  4, -1,		1, 1, 0,
			 1,  4,  1,		1, 1, 1,
			 
			-4, -4, -1,		0, 0, 0,
			-4, -4,  1,		0, 0, 1,
			-4,  4, -1,		0, 1, 0,
			-4,  4,  1,		0, 1, 1,
			 4, -4, -1,		1, 0, 0,
			 4, -4,  1,		1, 0, 1,
			 4,  4, -1,		1, 1, 0,
			 4,  4,  1,		1, 1, 1,
			 
			-1, -1, -4,		0, 0, 0,
			-1, -1,  4,		0, 0, 1,
			-1,  1, -4,		0, 1, 0,
			-1,  1,  4,		0, 1, 1,
			 1, -1, -4,		1, 0, 0,
			 1, -1,  4,		1, 0, 1,
			 1,  1, -4,		1, 1, 0,
			 1,  1,  4,		1, 1, 1,
			 
			-4, -1, -4,		0, 0, 0,
			-4, -1,  4,		0, 0, 1,
			-4,  1, -4,		0, 1, 0,
			-4,  1,  4,		0, 1, 1,
			 4, -1, -4,		1, 0, 0,
			 4, -1,  4,		1, 0, 1,
			 4,  1, -4,		1, 1, 0,
			 4,  1,  4,		1, 1, 1,
			 
			-1, -4, -4,		0, 0, 0,
			-1, -4,  4,		0, 0, 1,
			-1,  4, -4,		0, 1, 0,
			-1,  4,  4,		0, 1, 1,
			 1, -4, -4,		1, 0, 0,
			 1, -4,  4,		1, 0, 1,
			 1,  4, -4,		1, 1, 0,
			 1,  4,  4,		1, 1, 1,
			 
			-4, -4, -4,		0, 0, 0,
			-4, -4,  4,		0, 0, 1,
			-4,  4, -4,		0, 1, 0,
			-4,  4,  4,		0, 1, 1,
			 4, -4, -4,		1, 0, 0,
			 4, -4,  4,		1, 0, 1,
			 4,  4, -4,		1, 1, 0,
			 4,  4,  4,		1, 1, 1,
		};

		using namespace OpenGL;
		m_ppBatches[BATCH_ONE] = new CBatch;

		m_ppBatches[BATCH_ONE]->Bind();
		{
			m_ppBatches[BATCH_ONE]->AttachShaders(2);

			CShaders* pShaders = m_ppBatches[BATCH_ONE]->GetShaders(0);
			pShaders->AttachShader(EShaders::SHADERS_VERTEX, "data/glsl/cube_vs.glsl");
			pShaders->AttachShader(EShaders::SHADERS_GEOMETRY, "data/glsl/star_gs.glsl");
			pShaders->AttachShader(EShaders::SHADERS_FRAGMENT, "data/glsl/cube_ps.glsl");
			pShaders->LinkProgram();

			CShaders* pShaders2 = m_ppBatches[BATCH_ONE]->GetShaders(1);
			pShaders2->AttachShader(EShaders::SHADERS_VERTEX, "data/glsl/cube_vs.glsl");
			pShaders2->AttachShader(EShaders::SHADERS_GEOMETRY, "data/glsl/cube_gs.glsl");
			pShaders2->AttachShader(EShaders::SHADERS_FRAGMENT, "data/glsl/cube_ps.glsl");
			pShaders2->LinkProgram();

			pShaders->AttachTexture("data/assets/cat.png");

			m_ppBatches[BATCH_ONE]->AttachBuffers(1);
			CBuffer* pVB = m_ppBatches[BATCH_ONE]->GetBuffers(0);

			pVB->Map(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
		
			pShaders->AttachAttribute("position", 3, GL_FLOAT, sizeof(GLfloat)* 6, 0, GL_FALSE);
			pShaders->AttachAttribute("color1", 3, GL_FLOAT, sizeof(GLfloat) * 6, (GLvoid*)(sizeof(GLfloat) * 3), GL_FALSE);

			pShaders->AttachUniform("trans");
			pShaders->AttachUniform("override");

			glUniformMatrix4fv(pShaders->GetUniform("trans"), 1, false, glm::value_ptr(m_matMatrices[MATRIX_WVP]));
			glUniform4fv(pShaders->GetUniform("override"), 1, glm::value_ptr(glm::vec4(1, 1, 1, 1)));
		}
		m_ppBatches[BATCH_ONE]->Unbind();

		return true;
	}

	GLboolean CCubeApplication::Update(GLfloat _fDt)
	{
		static float fRadius = 1.0f;
		static float fSpeed = 1.0f;
		static glm::vec3 f3YPR(0, 0, 0);

		if(GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)	f3YPR.x -= 2.0f*_fDt;
		if(GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)	f3YPR.x += 2.0f*_fDt;
		if(GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)	f3YPR.y -= 2.0f*_fDt;
		if(GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000)	f3YPR.y += 2.0f*_fDt;
		if(GetAsyncKeyState('Z') & 0x8000)	fRadius -= fSpeed *_fDt;
		if(GetAsyncKeyState('X') & 0x8000)	fRadius += fSpeed *_fDt;

		// Do not allow the radius to reach zero.
		if(fRadius <= 0.0f)
		{
			fRadius += fSpeed * _fDt;
		}

		// Restrict the angle mPhi.
		if(f3YPR.y < 0.1f)
			f3YPR.y = 0.1f;

		if(f3YPR.y > 3.14f)
			f3YPR.y = 3.14f;


		if(GetAsyncKeyState('Q') & 0x8000)
		{
			m_ppBatches[0]->SetActiveShader(1);
		}
		else
		{
			m_ppBatches[0]->SetActiveShader(0);
		}

		// Convert Spherical to Cartesian coordinates: mPhi measured from +y
		// and mTheta measured counterclockwise from -z.
		m_f3Eye.x = fRadius*sinf(f3YPR.y)*sinf(f3YPR.x);
		m_f3Eye.z = -fRadius*sinf(f3YPR.y)*cosf(f3YPR.x);
		m_f3Eye.y = fRadius*cosf(f3YPR.y);

		m_matMatrices[MATRIX_VIEW] = glm::lookAt(m_f3Eye, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		m_matMatrices[MATRIX_WVP] = m_matMatrices[MATRIX_PROJ] * m_matMatrices[MATRIX_VIEW] * m_matMatrices[MATRIX_WORLD];

		glUniformMatrix4fv(m_ppBatches[0]->GetShaders(0)->GetUniform("trans"), 1, false, glm::value_ptr(m_matMatrices[MATRIX_WVP]));

		return true;
	}

	GLboolean CCubeApplication::Draw()
	{
		auto pShaders = m_ppBatches[0]->GetShaders(0);

		glUniform4fv(pShaders->GetUniform("override"), 1, glm::value_ptr(glm::vec4(1, 1, 1, 1)));
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		m_ppBatches[BATCH_ONE]->DrawBatch(GL_POINTS, 0, 64);

		glUniform4fv(pShaders->GetUniform("override"), 1, glm::value_ptr(glm::vec4(0, 0, 0, 0)));
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		m_ppBatches[BATCH_ONE]->DrawBatch(GL_POINTS, 0, 64);
		glDisable(GL_CULL_FACE);
		
		return true;
	}

	GLvoid CCubeApplication::Shutdown()
	{
		for(GLuint ui = 0; ui < BATCHES_MAX; ++ui)
		{
			delete m_ppBatches[ui];
			m_ppBatches[ui] = 0;
		}
	}

	GLboolean CCubeApplication::Frame(GLfloat _fDt)
	{
		CTimer timer;
		timer.Reset();

		GLfloat fFrameTime = 0.0f;

		while(fFrameTime < 0.016666f)
		{
			GLfloat dt = (GLfloat)timer.GetDeltaTime();
			Update(dt);

			timer.Tick();
			fFrameTime += dt;
		}

		Draw();
		return true;
	}
};