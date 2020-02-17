#include "preCompiled.h"

ObjectMgr::ObjectMgr() : eng(Engine::getInstance())
{
	// Setup our functions
	fpObjectMgrGetActivePlayerGUID = reinterpret_cast<ObjectMgrGetActivePlayerGUIDFunc>(eng->RVAToPtr(ObjectMgrGetActivePlayerGUIDAddr));
	fpObjectMgrGetActivePlayerObject = reinterpret_cast<ObjectMgrGetActivePlayerObjectFunc>(eng->RVAToPtr(ObjectMgrGetActivePlayerObjectAddr));
}

ObjectMgr::~ObjectMgr()
{

}