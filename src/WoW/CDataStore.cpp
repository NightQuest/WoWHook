#include "preCompiled.h"

CDataStore::CDataStore()
{
	Engine* eng = Engine::getInstance();

	fpInitialize = reinterpret_cast<CDataStoreInitializeFunc>(eng->RVAToPtr(CDataStoreInitializeAddr));
	fpDestroy = reinterpret_cast<CDataStoreDestroyFunc>(eng->RVAToPtr(CDataStoreDestroyAddr));

	fpPutInt8 = reinterpret_cast<CDataStorePutInt8Func>(eng->RVAToPtr(CDataStorePutByteAddr));
	fpPutInt16 = reinterpret_cast<CDataStorePutInt16Func>(eng->RVAToPtr(CDataStorePutInt16Addr));
	fpPutInt32 = reinterpret_cast<CDataStorePutInt32Func>(eng->RVAToPtr(CDataStorePutInt32Addr));
	fpPutInt64 = reinterpret_cast<CDataStorePutInt64Func>(eng->RVAToPtr(CDataStorePutInt64Addr));
	fpPutFloat = reinterpret_cast<CDataStorePutFloatFunc>(eng->RVAToPtr(CDataStorePutFloatAddr));
	fpPutString = reinterpret_cast<CDataStorePutStringFunc>(eng->RVAToPtr(CDataStorePutStringAddr));
	fpPutBytes = reinterpret_cast<CDataStorePutBytesFunc>(eng->RVAToPtr(CDataStorePutBytesAddr));
	fpPutVec3 = reinterpret_cast<CDataStorePutVec3Func>(eng->RVAToPtr(CDataStorePutVec3Addr));

	fpGetInt8 = reinterpret_cast<CDataStoreGetInt8Func>(eng->RVAToPtr(CDataStoreGetByteAddr));
	fpGetInt16 = reinterpret_cast<CDataStoreGetInt16Func>(eng->RVAToPtr(CDataStoreGetInt16Addr));
	fpGetInt32 = reinterpret_cast<CDataStoreGetInt32Func>(eng->RVAToPtr(CDataStoreGetInt32Addr));
	fpGetInt64 = reinterpret_cast<CDataStoreGetInt64Func>(eng->RVAToPtr(CDataStoreGetInt64Addr));
	fpGetFloat = reinterpret_cast<CDataStoreGetFloatFunc>(eng->RVAToPtr(CDataStoreGetFloatAddr));
	fpGetString = reinterpret_cast<CDataStoreGetStringFunc>(eng->RVAToPtr(CDataStoreGetStringAddr));
	fpGetBytes = reinterpret_cast<CDataStoreGetBytesFunc>(eng->RVAToPtr(CDataStoreGetBytesAddr));
	fpGetVec3 = reinterpret_cast<CDataStoreGetVec3Func>(eng->RVAToPtr(CDataStoreGetVec3Addr));

	fpInitialize(this);
}

CDataStore* CDataStore::Initialize()
{
	return fpInitialize(this);
}

void CDataStore::Destroy()
{
	fpDestroy(this);
}

CDataStore& CDataStore::PutInt8(INT8 value) { return fpPutInt8(this, value); }
CDataStore& CDataStore::PutInt16(INT16 value) { return fpPutInt16(this, value); }
CDataStore& CDataStore::PutInt32(INT32 value) { return fpPutInt32(this, value); }
CDataStore& CDataStore::PutInt64(INT64 value) { return fpPutInt64(this, value); }
CDataStore& CDataStore::PutFloat(float value) { return fpPutFloat(this, value); }
CDataStore& CDataStore::PutString(const char* str) { return fpPutString(this, str); }
CDataStore& CDataStore::PutBytes(PBYTE bytes, UINT32 size) { return fpPutBytes(this, bytes, size); }
CDataStore& CDataStore::PutVec3(Vec3* vec) { return fpPutVec3(this, vec); }


INT8 CDataStore::GetInt8()
{
	INT8 tmp;
	fpGetInt8(this, tmp);
	return tmp;
}

INT16 CDataStore::GetInt16()
{
	INT16 tmp;
	fpGetInt16(this, tmp);
	return tmp;
}

INT32 CDataStore::GetInt32()
{
	INT32 tmp;
	fpGetInt32(this, tmp);
	return tmp;
}

INT64 CDataStore::GetInt64()
{
	INT64 tmp;
	fpGetInt64(this, tmp);
	return tmp;
}

float CDataStore::GetFloat()
{
	float tmp;
	fpGetFloat(this, tmp);
	return tmp;
}

void CDataStore::GetString(char* str, UINT32 maxChars) { fpGetString(this, str, maxChars); }
void CDataStore::GetBytes(PBYTE bytes, UINT32 size) { fpGetBytes(this, bytes, size); }

Vec3 CDataStore::GetVec3()
{
	Vec3 pos = { 0.f };
	fpGetVec3(this, pos);
	return pos;
}
