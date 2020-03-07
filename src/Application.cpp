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

	// Patch inventory icons to use cache, not DBC
	eng->detourFunction(eng->RVAToPtr(CItemGetSafeInventoryItemArtAddr), GetSafeInventoryIcon, 0x3F);
	eng->detourFunction(eng->RVAToPtr(CItemGetRightClickFunctionAddr), GetRightClickFunction, 0x2D);
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

const char* Application::GetSafeInventoryIcon()
{
	Engine* eng = Engine::getInstance();
	UINT32 itemID;
	UINT32 displayId = 0;

	__asm
	{
		mov eax, dword ptr ds : [ecx + 0x8] // this(CObject)->data
		mov eax, dword ptr ds : [eax + 0xC] // data->itemID
		mov itemID, eax
	}

	cacheEntry* cache = eng->GetInfoBlockByID(itemID);
	if( cache )
		displayId = cache->displayId;

	return eng->GetInventoryArt(displayId);
}

UINT32 Application::GetRightClickFunction()
{
	Engine* eng = Engine::getInstance();

	cacheEntry* ret = eng->ItemGetCacheEntry();
	if( ret )
		return ret->always4;
	return 0;
}
