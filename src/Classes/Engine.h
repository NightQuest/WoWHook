#pragma once

class Engine
{
private:
	LPVOID baseAddress;

public:
	Engine();
	~Engine();

	// Utility functions
	LPVOID RVAToPtr(LPVOID address);
	LPVOID RVAToPtr(unsigned int address);
	bool patchBytes(LPVOID dest, const LPVOID src, size_t size);
};
