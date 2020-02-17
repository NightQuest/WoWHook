#include "preCompiled.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch( ul_reason_for_call )
	{
	case DLL_PROCESS_ATTACH:
		app.OnAttach();
		break;

	case DLL_PROCESS_DETACH:
		app.OnDetach();
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}

HRESULT WINAPI fake_DirectInput8Create(HINSTANCE hInst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
	// Load the dll in the system directory, so our calls can be forwarded
	if( !hDinput )
	{
		char tmp[MAX_PATH] = { 0 };
		GetSystemDirectory(tmp, MAX_PATH);
		strcat_s(tmp, "\\dinput8.dll");
		hDinput = LoadLibrary(tmp);

		// Make sure we were able to load it
		if( !hDinput )
			ExitProcess(EXIT_FAILURE);
	}

	// Define our function type
	typedef HRESULT(WINAPI* DirectInput8Create_type)(HINSTANCE hInst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);

	// Create our function pointer
	DirectInput8Create_type real_DirectInput8Create = reinterpret_cast<DirectInput8Create_type>(GetProcAddress(hDinput, "DirectInput8Create"));
	if( !real_DirectInput8Create )
		ExitProcess(EXIT_FAILURE);

	// Call the real DirectInputCreate8
	return real_DirectInput8Create(hInst, dwVersion, riidltf, ppvOut, punkOuter);
}

IDirect3D9* WINAPI fake_Direct3DCreate9(UINT SDKVersion)
{
	// Load the dll in the system directory, so our calls can be forwarded
	if( !hD3d9 )
	{
		char tmp[MAX_PATH] = { 0 };
		GetSystemDirectory(tmp, MAX_PATH);
		strcat_s(tmp, "\\d3d9.dll");
		hD3d9 = LoadLibrary(tmp);

		// Make sure we were able to load it
		if( !hD3d9 )
			ExitProcess(EXIT_FAILURE);
	}

	// Define our function type
	typedef IDirect3D9* (WINAPI* Direct3DCreate9_type)(UINT SDKVersion);

	// create our function pointer
	Direct3DCreate9_type real_Direct3DCreate9 = reinterpret_cast<Direct3DCreate9_type>(GetProcAddress(hD3d9, "Direct3DCreate9"));
	if( !real_Direct3DCreate9 )
		ExitProcess(1);

	// Call the real Direct3DCreate9
	IDirect3D9* real = real_Direct3DCreate9(SDKVersion);

	// Return our fake one
	return new fake_IDirect3D9(real);
}
