#pragma once

typedef UINT64(__cdecl* ObjectMgrGetActivePlayerGUIDFunc)();
typedef void* (__cdecl* ObjectMgrGetActivePlayerObjectFunc)();
typedef void* (__cdecl* ObjectMgrGetObjectFunc)(UINT64 objectGUID, unsigned int unk, const char* file, unsigned int line);

class ObjectMgr
{
private:
	Engine* eng;

	ObjectMgrGetActivePlayerGUIDFunc fpObjectMgrGetActivePlayerGUID;
	ObjectMgrGetActivePlayerObjectFunc fpObjectMgrGetActivePlayerObject;
	ObjectMgrGetObjectFunc fpObjectMgrGetObject;

public:
	ObjectMgr();
	~ObjectMgr();

	UINT64 GetActivePlayerGUID() { return fpObjectMgrGetActivePlayerGUID(); }
	void* GetActivePlayerObject() { return fpObjectMgrGetActivePlayerObject(); }
	void* GetObject(UINT64 objectGUID, unsigned int unk) { return fpObjectMgrGetObject(objectGUID, unk, __FILE__, __LINE__); }

};
