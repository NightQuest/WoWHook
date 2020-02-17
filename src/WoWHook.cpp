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