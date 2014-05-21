#pragma once 

#ifndef __TIMER_H__
#define __TIMER_H__

#include "GL\glew.h"

class CTimer 
{
public:
	CTimer();

	GLdouble GetGameTime() const;
	GLdouble GetDeltaTime() const;

	GLvoid Reset();
	GLvoid Start();
	GLvoid Stop();
	GLdouble Tick();

	GLboolean IsStopped() const;

private:
	GLdouble 
		m_dSecondsPerCount,
		m_dDeltaTime;

	GLint64 
		m_iBaseTime,
		m_iPausedTime,
		m_iStopTime,
		m_iPreviousTime,
		m_iCurrentTime;

	GLboolean
		m_bStopped;
};

#endif // __TIMER_H__