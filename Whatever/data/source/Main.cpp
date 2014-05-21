#include "CSystem.h"

#ifdef _USEVLD
	#pragma comment(lib, "data/lib/vld.lib")
	#include "vld/include/vld.h"
#endif

GLint WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, GLint iCmdshow)
{
	Application::CSystem* pSystem = new Application::CSystem;

	if(pSystem->Initialise())
		pSystem->Run();

	pSystem->Shutdown();

	delete pSystem;
	pSystem = 0;

	return 0;
}