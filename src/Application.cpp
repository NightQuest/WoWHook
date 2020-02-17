#include "preCompiled.h"

Application::Application() : eng(make_unique<Engine>())
{
}

Application::~Application()
{
}

void Application::OnAttach()
{
	// Redirect d3d9.dll to this dll
	unsigned int dllName_addr = reinterpret_cast<unsigned int>(dllName);
	eng->patchBytes(eng->RVAToPtr(Direct3DLibraryNameAddr), &dllName_addr, 4);
	eng->patchBytes(eng->RVAToPtr(Direct3DExLibraryNameAddr), &dllName_addr, 4);
}

void Application::OnDetach()
{
}

void Application::OnFrame(IDirect3DDevice9* device)
{
	static unsigned int frame = 0;
	if( frame < 2 && ++frame == 2 )
		MessageBox(NULL, "We're hooked in", "Success!", MB_OK);
	
	static bool fullyLoaded = false;
	if( fullyLoaded == false )
	{
		if( (fullyLoaded = eng->IsPlayerInGameOrOnInitialLoad()) == true )
		{
			MessageBox(NULL, "Player is loading or in game!", "Loaded", MB_OK);
		}
	}
}
