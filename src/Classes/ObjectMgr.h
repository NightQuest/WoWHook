#pragma once

typedef unsigned int (__cdecl* ObjectMgrGetActivePlayerGUIDFunc)();
typedef void* (__cdecl* ObjectMgrGetActivePlayerObjectFunc)();

class ObjectMgr
{
private:
	Engine* eng;

	ObjectMgrGetActivePlayerGUIDFunc fpObjectMgrGetActivePlayerGUID;
	ObjectMgrGetActivePlayerObjectFunc fpObjectMgrGetActivePlayerObject;

public:
	ObjectMgr();
	~ObjectMgr();

	unsigned int getActivePlayerGUID() { return fpObjectMgrGetActivePlayerGUID(); }
	void* getActivePlayerObject() { return fpObjectMgrGetActivePlayerObject(); }

};
