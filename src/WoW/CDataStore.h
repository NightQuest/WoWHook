#pragma once

class CDataStore;

typedef CDataStore* (__thiscall* CDataStoreInitializeFunc)(CDataStore* data);
typedef void(__thiscall* CDataStoreDestroyFunc)(CDataStore* data);

typedef CDataStore& (__thiscall* CDataStorePutInt8Func)(CDataStore* data, INT8 value);
typedef CDataStore& (__thiscall* CDataStorePutInt16Func)(CDataStore* data, INT16 value);
typedef CDataStore& (__thiscall* CDataStorePutInt32Func)(CDataStore* data, INT32 value);
typedef CDataStore& (__thiscall* CDataStorePutInt64Func)(CDataStore* data, INT64 value);
typedef CDataStore& (__thiscall* CDataStorePutFloatFunc)(CDataStore* data, float value);
typedef CDataStore& (__thiscall* CDataStorePutStringFunc)(CDataStore* data, char const* value);
typedef CDataStore& (__thiscall* CDataStorePutBytesFunc)(CDataStore* data, UINT8* bytes, UINT32 size);
typedef CDataStore& (__thiscall* CDataStorePutVec3Func)(CDataStore* data, Vec3* pos);

typedef CDataStore& (__thiscall* CDataStoreGetInt8Func)(CDataStore* data, INT8& value);
typedef CDataStore& (__thiscall* CDataStoreGetInt16Func)(CDataStore* data, INT16& value);
typedef CDataStore& (__thiscall* CDataStoreGetInt32Func)(CDataStore* data, INT32& value);
typedef CDataStore& (__thiscall* CDataStoreGetInt64Func)(CDataStore* data, INT64& value);
typedef CDataStore& (__thiscall* CDataStoreGetFloatFunc)(CDataStore* data, float& value);
typedef CDataStore& (__thiscall* CDataStoreGetStringFunc)(CDataStore* data, char* value, UINT32 maxChars);
typedef CDataStore& (__thiscall* CDataStoreGetBytesFunc)(CDataStore* data, UINT8* bytes, UINT32 size);
typedef CDataStore& (__thiscall* CDataStoreGetVec3Func)(CDataStore* data, Vec3& pos);


class CDataStore
{
public:
	CDataStore();

	virtual bool apparentlyDoNothing() { return false; }																						// 0047ADD0
	virtual void InternalDestroy(PBYTE buffer, PBYTE size, PBYTE allocated) {}																	// 0047AE50
	virtual bool InternalFetchRead() { return false; }																							// 00936900
	virtual bool InternalFetchWrite(DWORD unk, DWORD unk2, DWORD unk3, DWORD unk4, PBYTE out, const char* text, DWORD size) { return true; }	// 0047AEA0
	virtual ~CDataStore() {}																													// 004038A0
	virtual bool IsRead() { return false; }																										// 004010D0
	virtual void Reset() {}																														// 004010E0
	virtual void Finalize() {}																													// 00401130
	virtual void GetBufferParams(PBYTE buffer, PBYTE size, PBYTE allocated) {}																	// 0047ADE0
	virtual void DetachBuffer(PBYTE buffer, PBYTE size, PBYTE allocated) {}																		// 0047AE10
	virtual bool apparentlyDoNothing3() { return false; }																						// 004899F0

	CDataStore* Initialize(); 							// 00401050
	void Destroy();										// 00665CF0

	CDataStore& PutInt8(INT8 value);					// 0047AFE0
	CDataStore& PutInt16(INT16 value);					// 0047B040
	CDataStore& PutInt32(INT32 value);					// 0047B0A0
	CDataStore& PutInt64(INT64 value);					// 0047B100
	CDataStore& PutFloat(float value);					// 0047B160
	CDataStore& PutString(const char* str);				// 0047B300
	CDataStore& PutBytes(PBYTE bytes, UINT32 size);		// 0047B1C0
	CDataStore& PutVec3(Vec3* vec);						// 00406DA0

	INT8 GetInt8();										// 0047B340
	INT16 GetInt16();									// 0047B380
	INT32 GetInt32();									// 00401170
	INT64 GetInt64();									// 0047B400
	float GetFloat();									// 0047B440
	void GetString(char* str, UINT32 maxChars);			// 0047B480
	void GetBytes(PBYTE bytes, UINT32 size);			// 0047B560
	Vec3 GetVec3();										// 00401190

	CDataStore& operator<<(INT8 value) { return PutInt8(value); }
	CDataStore& operator<<(INT16 value) { return PutInt16(value); }
	CDataStore& operator<<(INT32 value) { return PutInt32(value); }
	CDataStore& operator<<(INT64 value) { return PutInt64(value); }
	CDataStore& operator<<(float value) { return PutFloat(value); }
	CDataStore& operator<<(const char* value) { return PutString(value); }
	CDataStore& operator<<(std::string value) { return PutString(value.c_str()); }
	CDataStore& operator<<(Vec3& value) { return PutVec3(&value); }

	//void GetInt32();									// 0047B3C0
	//void* Alloc(UINT32 size);							// 00401010
	//void Free(CDataStore* data);						// 00401030
	//void GetInt8_2();									// 00401140
	//void Release();									// 00403880
	//void InitPacket2();								// 00403EC0
	//void ReleasePacket2();							// 00403F10
	//void CreateFromData();							// 004669A0
	//void PutInt8AtPos();								// 0047AEF0
	//void PutInt16AtPos();								// 0047AF40
	//void PutInt32AtPos();								// 0047AF90
	//void PutCString_3();								// 0047B280
	//void CanRead();									// 0047B290
	//void GetIntArray();								// 0047B5F0
	//void GetCString_2();								// 0047B6A0
	//void ReadBytes();									// 0047B6B0
	//void GetInt8_3();									// 004D3870
	//void ReadInt32();									// 0050F420
	//void ReadAddonInfoPacket();						// 005F79A0
	//void Reset_0();									// 00636C00
	//void Load();										// 006490B0
	//void ReadPackedVector3();							// 007152B0
	//void GetWowGUID();								// 0076DC20
	//void PutPackedGuid();								// 0076DD00
	//void CanReadNumBytes();							// 008CBBF0
	//void dtor();										// 008CCF50
	//void DetachBufferProxy();							// 008CCFC0
	//void New();										// 008CD0B0
	//void Free_0();									// 008CD160

private:
	PBYTE buffer;		// 0x04
	DWORD base;			// 0x08
	DWORD allocated;	// 0x0C
	DWORD size;			// 0x10
	DWORD read;			// 0x14

	CDataStoreInitializeFunc fpInitialize;
	CDataStoreDestroyFunc fpDestroy;

	CDataStorePutInt8Func fpPutInt8;
	CDataStorePutInt16Func fpPutInt16;
	CDataStorePutInt32Func fpPutInt32;
	CDataStorePutInt64Func fpPutInt64;
	CDataStorePutFloatFunc fpPutFloat;
	CDataStorePutStringFunc fpPutString;
	CDataStorePutBytesFunc fpPutBytes;
	CDataStorePutVec3Func fpPutVec3;

	CDataStoreGetInt8Func fpGetInt8;
	CDataStoreGetInt16Func fpGetInt16;
	CDataStoreGetInt32Func fpGetInt32;
	CDataStoreGetInt64Func fpGetInt64;
	CDataStoreGetFloatFunc fpGetFloat;
	CDataStoreGetStringFunc fpGetString;
	CDataStoreGetBytesFunc fpGetBytes;
	CDataStoreGetVec3Func fpGetVec3;
};
