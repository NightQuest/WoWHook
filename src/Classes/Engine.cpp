#include "preCompiled.h"

Engine::Engine() : baseAddress(nullptr)
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

	// Functions
	fpEngineIsPlayerInGameOrOnInitialLoad = reinterpret_cast<EngineIsPlayerInGameOrOnInitialLoadFunc>(RVAToPtr(EngineIsPlayerInGameOrOnInitialLoadAddr));
}

Engine::~Engine()
{
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
