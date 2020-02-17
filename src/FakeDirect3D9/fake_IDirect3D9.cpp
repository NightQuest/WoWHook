#include "preCompiled.h"

fake_IDirect3D9::fake_IDirect3D9(IDirect3D9* real_IDirect3D9) : real(real_IDirect3D9)
{
}

fake_IDirect3D9::~fake_IDirect3D9()
{
}

ULONG WINAPI fake_IDirect3D9::AddRef()
{
	return real->AddRef();
}

HRESULT WINAPI fake_IDirect3D9::QueryInterface(REFIID riid, LPVOID* ppvObj)
{
	*ppvObj = NULL;

	HRESULT hRes = real->QueryInterface(riid, ppvObj);
	if( hRes == NOERROR )
		*ppvObj = this;

	return hRes;
}

ULONG WINAPI fake_IDirect3D9::Release()
{
	ULONG references = real->Release();

	if( references == 0 )
	{
		delete this;
	}

	return references;
}


HRESULT WINAPI fake_IDirect3D9::RegisterSoftwareDevice(LPVOID pInitializeFunction)
{
	return real->RegisterSoftwareDevice(pInitializeFunction);
}

UINT WINAPI fake_IDirect3D9::GetAdapterCount()
{
	return real->GetAdapterCount();
}

HRESULT WINAPI fake_IDirect3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
	return real->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT WINAPI fake_IDirect3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
	return real->GetAdapterModeCount(Adapter, Format);
}

HRESULT WINAPI fake_IDirect3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
	return real->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

HRESULT WINAPI fake_IDirect3D9::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
	return real->GetAdapterDisplayMode(Adapter, pMode);
}

HRESULT WINAPI fake_IDirect3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
	return real->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
}

HRESULT WINAPI fake_IDirect3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
	return real->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

HRESULT WINAPI fake_IDirect3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, LPDWORD pQualityLevels)
{
	return real->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

HRESULT WINAPI fake_IDirect3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
	return real->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT WINAPI fake_IDirect3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
	return real->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}

HRESULT WINAPI fake_IDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
	return real->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HMONITOR WINAPI fake_IDirect3D9::GetAdapterMonitor(UINT Adapter)
{
	return real->GetAdapterMonitor(Adapter);
}

HRESULT WINAPI fake_IDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
	HRESULT hRes = real->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);

	*ppReturnedDeviceInterface = new fake_IDirect3DDevice9(*ppReturnedDeviceInterface);

	return hRes;
}
