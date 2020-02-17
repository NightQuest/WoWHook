#include "preCompiled.h"

fake_IDirect3DDevice9::fake_IDirect3DDevice9(IDirect3DDevice9* real_IDirect3DDevice9) : real(real_IDirect3DDevice9)
{
}

fake_IDirect3DDevice9::~fake_IDirect3DDevice9()
{
}

ULONG WINAPI fake_IDirect3DDevice9::AddRef()
{
	return real->AddRef();
}

HRESULT WINAPI fake_IDirect3DDevice9::QueryInterface(REFIID riid, void** ppvObj)
{
	*ppvObj = NULL;

	HRESULT hRes = real->QueryInterface(riid, ppvObj);
	if( hRes == NOERROR )
		*ppvObj = this;

	return hRes;
}

ULONG WINAPI fake_IDirect3DDevice9::Release()
{
	ULONG references = real->Release();

	if( references == 0 )
	{
		delete this;
	}

	return references;
}

HRESULT WINAPI fake_IDirect3DDevice9::TestCooperativeLevel()
{
	return real->TestCooperativeLevel();
}

UINT WINAPI fake_IDirect3DDevice9::GetAvailableTextureMem()
{
	return real->GetAvailableTextureMem();
}

HRESULT WINAPI fake_IDirect3DDevice9::EvictManagedResources()
{
	return real->EvictManagedResources();
}

HRESULT WINAPI fake_IDirect3DDevice9::GetDirect3D(IDirect3D9** ppD3D9)
{
	return real->GetDirect3D(ppD3D9);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetDeviceCaps(D3DCAPS9* pCaps)
{
	return real->GetDeviceCaps(pCaps);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
	return real->GetDisplayMode(iSwapChain, pMode);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
	return real->GetCreationParameters(pParameters);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
	return real->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

void WINAPI fake_IDirect3DDevice9::SetCursorPosition(int X, int Y, DWORD Flags)
{
	return real->SetCursorPosition(X, Y, Flags);
}

BOOL WINAPI fake_IDirect3DDevice9::ShowCursor(BOOL bShow)
{
	return real->ShowCursor(bShow);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain)
{
	return real->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
	return real->GetSwapChain(iSwapChain, pSwapChain);
}

UINT WINAPI fake_IDirect3DDevice9::GetNumberOfSwapChains()
{
	return real->GetNumberOfSwapChains();
}

HRESULT WINAPI fake_IDirect3DDevice9::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	return real->Reset(pPresentationParameters);
}

HRESULT WINAPI fake_IDirect3DDevice9::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
	return real->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
	return real->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
	return real->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetDialogBoxMode(BOOL bEnableDialogs)
{
	return real->SetDialogBoxMode(bEnableDialogs);
}

void WINAPI fake_IDirect3DDevice9::SetGammaRamp(UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
	return real->SetGammaRamp(iSwapChain, Flags, pRamp);
}

void WINAPI fake_IDirect3DDevice9::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
	return real->GetGammaRamp(iSwapChain, pRamp);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
	return real->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
	return real->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
	return real->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
	return real->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
	return real->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return real->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return real->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT WINAPI fake_IDirect3DDevice9::UpdateSurface(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
{
	return real->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT WINAPI fake_IDirect3DDevice9::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
	return real->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
	return real->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
	return real->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT WINAPI fake_IDirect3DDevice9::StretchRect(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
	return real->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT WINAPI fake_IDirect3DDevice9::ColorFill(IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color)
{
	return real->ColorFill(pSurface, pRect, color);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return real->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
	return real->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
	return real->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
	return real->SetDepthStencilSurface(pNewZStencil);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
	return real->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT WINAPI fake_IDirect3DDevice9::BeginScene()
{
	return real->BeginScene();
}

HRESULT WINAPI fake_IDirect3DDevice9::EndScene()
{
	return real->EndScene();
}

HRESULT WINAPI fake_IDirect3DDevice9::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
	return real->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
	return real->SetTransform(State, pMatrix);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
	return real->GetTransform(State, pMatrix);
}

HRESULT WINAPI fake_IDirect3DDevice9::MultiplyTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
	return real->MultiplyTransform(State, pMatrix);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetViewport(CONST D3DVIEWPORT9* pViewport)
{
	return real->SetViewport(pViewport);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetViewport(D3DVIEWPORT9* pViewport)
{
	return real->GetViewport(pViewport);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetMaterial(CONST D3DMATERIAL9* pMaterial)
{
	return real->SetMaterial(pMaterial);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetMaterial(D3DMATERIAL9* pMaterial)
{
	return real->GetMaterial(pMaterial);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetLight(DWORD Index, CONST D3DLIGHT9* pLight)
{
	return real->SetLight(Index, pLight);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetLight(DWORD Index, D3DLIGHT9* pLight)
{
	return real->GetLight(Index, pLight);
}

HRESULT WINAPI fake_IDirect3DDevice9::LightEnable(DWORD Index, BOOL Enable)
{
	return real->LightEnable(Index, Enable);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetLightEnable(DWORD Index, BOOL* pEnable)
{
	return real->GetLightEnable(Index, pEnable);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetClipPlane(DWORD Index, CONST float* pPlane)
{
	return real->SetClipPlane(Index, pPlane);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetClipPlane(DWORD Index, float* pPlane)
{
	return real->GetClipPlane(Index, pPlane);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
	return real->SetRenderState(State, Value);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
	return real->GetRenderState(State, pValue);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
	return real->CreateStateBlock(Type, ppSB);
}

HRESULT WINAPI fake_IDirect3DDevice9::BeginStateBlock()
{
	return real->BeginStateBlock();
}

HRESULT WINAPI fake_IDirect3DDevice9::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
	return real->EndStateBlock(ppSB);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus)
{
	return real->SetClipStatus(pClipStatus);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
	return real->GetClipStatus(pClipStatus);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
	return real->GetTexture(Stage, ppTexture);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
	return real->SetTexture(Stage, pTexture);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
	return real->GetTextureStageState(Stage, Type, pValue);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
	return real->SetTextureStageState(Stage, Type, Value);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
	return real->GetSamplerState(Sampler, Type, pValue);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
	return real->SetSamplerState(Sampler, Type, Value);
}

HRESULT WINAPI fake_IDirect3DDevice9::ValidateDevice(DWORD* pNumPasses)
{
	return real->ValidateDevice(pNumPasses);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY* pEntries)
{
	return real->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
	return real->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetCurrentTexturePalette(UINT PaletteNumber)
{
	return real->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetCurrentTexturePalette(UINT* PaletteNumber)
{
	return real->GetCurrentTexturePalette(PaletteNumber);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetScissorRect(CONST RECT* pRect)
{
	return real->SetScissorRect(pRect);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetScissorRect(RECT* pRect)
{
	return real->GetScissorRect(pRect);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetSoftwareVertexProcessing(BOOL bSoftware)
{
	return real->SetSoftwareVertexProcessing(bSoftware);
}

BOOL WINAPI fake_IDirect3DDevice9::GetSoftwareVertexProcessing()
{
	return real->GetSoftwareVertexProcessing();
}

HRESULT WINAPI fake_IDirect3DDevice9::SetNPatchMode(float nSegments)
{
	return real->SetNPatchMode(nSegments);
}

float WINAPI fake_IDirect3DDevice9::GetNPatchMode()
{
	return real->GetNPatchMode();
}

HRESULT WINAPI fake_IDirect3DDevice9::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	return real->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	return real->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return real->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT WINAPI fake_IDirect3DDevice9::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return real->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT WINAPI fake_IDirect3DDevice9::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
	return real->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
	return real->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
	return real->SetVertexDeclaration(pDecl);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
	return real->GetVertexDeclaration(ppDecl);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetFVF(DWORD FVF)
{
	return real->SetFVF(FVF);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetFVF(DWORD* pFVF)
{
	return real->GetFVF(pFVF);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateVertexShader(CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
	return real->CreateVertexShader(pFunction, ppShader);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetVertexShader(IDirect3DVertexShader9* pShader)
{
	return real->SetVertexShader(pShader);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
	return real->GetVertexShader(ppShader);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetVertexShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
	return real->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
	return real->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetVertexShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
	return real->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
	return real->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetVertexShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT BoolCount)
{
	return real->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
	return real->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
	return real->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride)
{
	return real->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetStreamSourceFreq(UINT StreamNumber, UINT Setting)
{
	return real->SetStreamSourceFreq(StreamNumber, Setting);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting)
{
	return real->GetStreamSourceFreq(StreamNumber, pSetting);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
	return real->SetIndices(pIndexData);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
	return real->GetIndices(ppIndexData);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreatePixelShader(CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
	return real->CreatePixelShader(pFunction, ppShader);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetPixelShader(IDirect3DPixelShader9* pShader)
{
	return real->SetPixelShader(pShader);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
	return real->GetPixelShader(ppShader);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetPixelShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
	return real->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
	return real->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetPixelShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
	return real->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
	return real->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::SetPixelShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT BoolCount)
{
	return real->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
	return real->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT WINAPI fake_IDirect3DDevice9::DrawRectPatch(UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
	return real->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT WINAPI fake_IDirect3DDevice9::DrawTriPatch(UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
	return real->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT WINAPI fake_IDirect3DDevice9::DeletePatch(UINT Handle)
{
	return real->DeletePatch(Handle);
}

HRESULT WINAPI fake_IDirect3DDevice9::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
	return real->CreateQuery(Type, ppQuery);
}
