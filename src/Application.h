#pragma once

class Application
{
public:
	Application();
	~Application();

	void OnAttach();
	void OnDetach();
	void OnFrame(IDirect3DDevice9* device);

private:
	Engine* eng;
};
