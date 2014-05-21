#include "CTimer.h" 
#include <windows.h>

CTimer::CTimer()
: m_dSecondsPerCount(0.0), m_dDeltaTime(0), m_iBaseTime(0)
, m_iPausedTime(0), m_iPreviousTime(0), m_iCurrentTime(0)
, m_bStopped(false)
{ 
	GLint64 iCountsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&iCountsPerSec);
	m_dSecondsPerCount = 1.0 / (GLdouble)iCountsPerSec;
}

// Returns the total time elapsed since reset() was called, NOT counting any
// time when the clock is stopped.
GLdouble CTimer::GetGameTime()const
{
	// If we are stopped, do not count the time that has passed since we stopped.
	//
	// ----*---------------*------------------------------*------> time
	//  mBaseTime       mStopTime                      mCurrentTime

	if( m_bStopped )
	{
		return ((m_iStopTime - m_iBaseTime) * m_dSecondsPerCount);
	}

	// The distance mCurrentTime - mBaseTime includes paused time,
	// which we do not want to count.  To correct this, we can subtract 
	// the paused time from mCurrentTime:  
	//
	//  (mCurrentTime - mPausedTime) - mBaseTime 
	//
	//                     |<-------d------->|
	// ----*---------------*-----------------*------------*------> time
	//  mBaseTime       mStopTime        startTime     mCurrentTime
	
	else
	{
		return (((m_iCurrentTime - m_iPausedTime) - m_iBaseTime) * m_dSecondsPerCount);
	}
}

GLdouble CTimer::GetDeltaTime()const
{
	return m_dDeltaTime;
}

GLvoid CTimer::Reset()
{
	GLint64 iCurrTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&iCurrTime);

	m_iBaseTime = iCurrTime;
	m_iPreviousTime = iCurrTime;
	m_iStopTime = 0;
	m_bStopped  = false;
}

GLvoid CTimer::Start()
{
	GLint64 iStartTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&iStartTime);


	// Accumulate the time elapsed between stop and start pairs.
	//
	//                     |<-------d------->|
	// ----*---------------*-----------------*------------> time
	//  mBaseTime       mStopTime        startTime     

	if( m_bStopped )
	{
		m_iPausedTime += (iStartTime - m_iStopTime);	

		m_iPreviousTime = iStartTime;
		m_iStopTime = 0;
		m_bStopped  = false;
	}
}

GLvoid CTimer::Stop()
{
	if( !m_bStopped )
	{
		GLint64 iCurrTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&iCurrTime);

		m_iStopTime = iCurrTime;
		m_bStopped  = true;
	}
}

GLdouble CTimer::Tick()
{
	if( m_bStopped )
	{
		m_dDeltaTime = 0.0;
		return m_dDeltaTime;
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&m_iCurrentTime);

	// Time difference between this frame and the previous.
	m_dDeltaTime = (m_iCurrentTime - m_iPreviousTime) * m_dSecondsPerCount;

	// Prepare for next frame.
	m_iPreviousTime = m_iCurrentTime;

	// Force nonnegative.  The DXSDK's CDXUTTimer mentions that if the 
	// processor goes GLinto a power save mode or we get shuffled to another
	// processor, then mDeltaTime can be negative.
	if(m_dDeltaTime < 0.0)
	{
		m_dDeltaTime = 0.0;
	}

	return m_dDeltaTime;
}

GLboolean CTimer::IsStopped() const
{
	return m_bStopped;
}