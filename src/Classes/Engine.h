#pragma once

struct cacheEntry
{
	UINT32 unk;
	UINT32 unk2;
	UINT32 unk3;
	UINT32 unk4;
	UINT32 displayId;
	UINT32 always4;
};

typedef cacheEntry* (__thiscall* GetInfoBlockByIDFunc)(LPVOID dbCachePtr, UINT32 itemID, UINT32* out, UINT32 unk, UINT32 unk2, UINT32 unk3);
typedef const char* (__cdecl* GetInventoryArtFunc)(UINT32 id);
typedef cacheEntry* (__cdecl* ItemGetCacheEntryFunc)();
typedef bool(__cdecl* EngineIsPlayerInGameOrOnInitialLoadFunc)();

class Engine
{
private:
	LPVOID baseAddress;
	CGxDeviceD3d** deviceD3d;
	bool* playerIsInGame;

	// Singleton
	static Engine* instance;

	// WoW functions
	EngineIsPlayerInGameOrOnInitialLoadFunc fpEngineIsPlayerInGameOrOnInitialLoad;
	GetInfoBlockByIDFunc fpGetInfoBlockByID;
	GetInventoryArtFunc fpGetInventoryArt;
	ItemGetCacheEntryFunc fpItemGetCacheEntry;

public:
	Engine();
	~Engine();

	// Singleton
	static Engine* getInstance();

	// Utility functions
	LPVOID RVAToPtr(LPVOID address);
	LPVOID RVAToPtr(unsigned int address);
	bool patchBytes(LPVOID dest, const LPVOID src, size_t size);
	bool detourFunction(LPVOID originalFunc, LPVOID newFunc, size_t size);

	// WoW Helper functions
	bool IsPlayerInGame() { return *playerIsInGame; }


	// WoW Classes
	CGxDeviceD3d* GetDeviceD3d() { return *deviceD3d; }

	// WoW functions
	bool IsPlayerInGameOrOnInitialLoad() { return fpEngineIsPlayerInGameOrOnInitialLoad(); }
	cacheEntry* GetInfoBlockByID(UINT32 itemID) { UINT32 local = 0; return fpGetInfoBlockByID(RVAToPtr(DBItemCache), itemID, &local, 0, 0, 0); }
	const char* GetInventoryArt(UINT32 displayID) { return fpGetInventoryArt(displayID); }
	cacheEntry* ItemGetCacheEntry() { return fpItemGetCacheEntry(); }

};
