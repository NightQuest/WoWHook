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
	unique_ptr<Engine> eng;
};
