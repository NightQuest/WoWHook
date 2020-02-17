#pragma once

class Application
{
public:
	Application();
	~Application();

	void OnAttach();
	void OnDetach();

private:
	unique_ptr<Engine> eng;
};
