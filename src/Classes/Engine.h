#pragma once

typedef bool(__cdecl* EngineIsPlayerInGameOrOnInitialLoadFunc)();

class Engine
{
private:
	LPVOID baseAddress;
	bool* playerIsInGame;

	// WoW functions
	EngineIsPlayerInGameOrOnInitialLoadFunc fpEngineIsPlayerInGameOrOnInitialLoad;

public:
	Engine();
	~Engine();

	// Utility functions
	LPVOID RVAToPtr(LPVOID address);
	LPVOID RVAToPtr(unsigned int address);
	bool patchBytes(LPVOID dest, const LPVOID src, size_t size);

	// WoW Helper functions
	bool IsPlayerInGame() { return *playerIsInGame; }

	// WoW functions
	bool IsPlayerInGameOrOnInitialLoad() { return fpEngineIsPlayerInGameOrOnInitialLoad(); }
};
