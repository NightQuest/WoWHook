#pragma once

typedef unsigned int (__cdecl* ObjectMgrGetActivePlayerGUIDFunc)();
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

	unsigned int getActivePlayerGUID() { return fpObjectMgrGetActivePlayerGUID(); }
	void* getActivePlayerObject() { return fpObjectMgrGetActivePlayerObject(); }
	void* getObject(UINT64 objectGUID, unsigned int unk) { return fpObjectMgrGetObject(objectGUID, unk, __FILE__, __LINE__); }

};
