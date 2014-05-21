#ifndef __CubeApplication_H__
#define __CubeApplication_H__

#pragma once

//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: CubeApplication.h
// Description	: Defines the CCubeApplication class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//
			
// Library Includes
			
// Local Includes
#include "IApplication.h"
#include "CBatch.h"
#include "CShaders.h"
#include "CBuffer.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace Application
{
	// Types
	enum EMatricies
	{
		MATRIX_PROJ,
		MATRIX_VIEW,
		MATRIX_WORLD,
		MATRIX_WVP,
		MATRIX_MAX
	};

	enum EBatches
	{
		BATCH_ONE,
		BATCH_TWO,
		BATCHES_MAX
	};
			
	// Constants
			
	// Prototypes
	class CCubeApplication : public IApplication
	{
		public:
			CCubeApplication();
			~CCubeApplication();

			GLboolean Initialise();
			GLvoid Shutdown();
			GLboolean Frame(GLfloat _fDt);
					
		protected:
			GLboolean Update(GLfloat _fDt);
			GLboolean Draw();

			GLboolean InitialiseBatch();

		private:
				
		public:
		protected:
		private:

			glm::mat4x4 m_matMatrices[MATRIX_MAX];
			glm::vec3 m_f3Eye;

			OpenGL::CBatch* m_ppBatches[BATCHES_MAX];
			GLuint m_uiNumBatches;
	};
};

#endif // __CubeApplication_H__
		