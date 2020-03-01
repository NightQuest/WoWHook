#include "preCompiled.h"

Application::Application() : eng(Engine::getInstance())
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

	// Patch .sig verification
	unsigned int nops = 0x90909090;
	eng->patchBytes(eng->RVAToPtr(SigCompareLoopAddr), &nops, 4);

	// Patch language check
	eng->patchBytes(eng->RVAToPtr(UnderstandAnyLanguageAddr), &nops, 2);
}

void Application::OnDetach()
{
	// This should only be done here
	delete eng;
}

void Application::OnFrame(IDirect3DDevice9* device)
{
#ifdef _DEBUG
	static unsigned int frame = 0;
	if( frame < 2 && ++frame == 2 )
		MessageBox(NULL, "We're hooked in", "Success!", MB_OK);

	static bool fullyLoaded = false;
	if( fullyLoaded == false )
	{
		if( (fullyLoaded = eng->IsPlayerInGame()) == true )
		{
			MessageBox(NULL, "Player has entered the world!", "Loaded", MB_OK);
		}
	}
#endif
}
