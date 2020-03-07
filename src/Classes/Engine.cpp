#include "preCompiled.h"

Engine* Engine::instance;

Engine::Engine() : baseAddress(nullptr), deviceD3d(nullptr), playerIsInGame(nullptr), fpEngineIsPlayerInGameOrOnInitialLoad(nullptr)
{
	// Grab the DOS header of Wow.exe and make sure its signature is valid
	IMAGE_DOS_HEADER* dosHeader = reinterpret_cast<IMAGE_DOS_HEADER*>(GetModuleHandle(NULL));
	if( dosHeader->e_magic != IMAGE_DOS_SIGNATURE )
		return;

	// Grab the NT header of Wow.exe and make sure its signature is valid
	IMAGE_NT_HEADERS* ntHeaders = reinterpret_cast<IMAGE_NT_HEADERS*>(reinterpret_cast<UINT>(dosHeader) + dosHeader->e_lfanew);
	if( ntHeaders->Signature != IMAGE_NT_SIGNATURE )
		return;

	// Set the base address, based on the header information.
	baseAddress = reinterpret_cast<LPVOID>(ntHeaders->OptionalHeader.ImageBase + ntHeaders->OptionalHeader.BaseOfCode);

	// Set our addresses:

	// Globals
	playerIsInGame = reinterpret_cast<bool*>(RVAToPtr(EngineIsPlayerInGameAddr));

	// Classes
	deviceD3d = reinterpret_cast<CGxDeviceD3d**>(RVAToPtr(CGxDeviceD3dPtrAddr));

	// Functions
	fpEngineIsPlayerInGameOrOnInitialLoad = reinterpret_cast<EngineIsPlayerInGameOrOnInitialLoadFunc>(RVAToPtr(EngineIsPlayerInGameOrOnInitialLoadAddr));
}

Engine::~Engine()
{
}

Engine* Engine::getInstance()
{
	if( instance != nullptr )
		return instance;

	instance = new Engine();

	return instance;
}

LPVOID Engine::RVAToPtr(LPVOID address)
{
	return RVAToPtr(reinterpret_cast<unsigned int>(address));
}

LPVOID Engine::RVAToPtr(unsigned int address)
{
	return reinterpret_cast<LPVOID>(reinterpret_cast<unsigned int>(baseAddress) + address);
}

bool Engine::patchBytes(LPVOID dest, const LPVOID src, size_t size)
{
	DWORD oldProtect;
	if( VirtualProtect(dest, size, PAGE_READWRITE, &oldProtect) )
	{
		memcpy(dest, src, size);
		VirtualProtect(dest, size, oldProtect, &oldProtect);
		return (memcmp(dest, src, size) == 0);
	}
	return false;
}

bool Engine::detourFunction(LPVOID originalFunc, LPVOID newFunc, size_t size)
{
	// Make sure there's room for our jump
	if( size < 5 )
		return false;

	// create our jump
	BYTE jmp[5] = { 0 };
	jmp[0] = '\xE9';
	UINT32 relativeAddress = reinterpret_cast<UINT32>(newFunc) - reinterpret_cast<UINT32>(originalFunc) - 5;
	*reinterpret_cast<UINT32*>(&jmp[1]) = relativeAddress;

	// Write our detour
	if( !patchBytes(originalFunc, &jmp, 5) )
		return false;

	bool ret = true;
	if( size > 5 )
	{
		// Fill the rest with NOPs
		BYTE* buffer = new BYTE[size - 5];
		memset(buffer, '\x90', size - 5);
		ret = patchBytes(reinterpret_cast<LPVOID>(reinterpret_cast<UINT32>(originalFunc) + 5), buffer, size - 5);
		delete[] buffer;
	}

	return ret;
}
