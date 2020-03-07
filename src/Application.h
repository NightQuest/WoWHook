#pragma once

class Application
{
public:
	Application();
	~Application();

	void OnAttach();
	void OnDetach();
	void OnFrame(IDirect3DDevice9* device);

	static const char* GetSafeInventoryIcon();
	static UINT32 GetRightClickFunction();

private:
	Engine* eng;
};
