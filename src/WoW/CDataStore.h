#pragma once

class CDataStore
{
public:
	virtual bool apparentlyDoNothing();																							// 0047ADD0
	virtual void InternalDestroy(LPVOID unk, LPVOID unk2, LPVOID unk3);															// 0047AE50
	virtual bool apparentlyDoNothing2();																						// 00936900
	virtual bool InternalFetchWrite(DWORD unk, DWORD unk2, DWORD unk3, DWORD unk4, PBYTE out, const char* text, DWORD size);	// 0047AEA0
	virtual ~CDataStore();																										// 004038A0
	virtual bool IsRead();																										// 004010D0
	virtual void Reset();																										// 004010E0
	virtual void Finalize();																									// 00401130
	virtual void GetBufferParams(PBYTE out, PBYTE out2, PBYTE out3);															// 0047ADE0
	virtual void DetachBuffer(PBYTE buffer, PBYTE size, PBYTE allocated);														// 0047AE10
	virtual bool apparentlyDoNothing3();																						// 004899F0

private:
	PBYTE buffer;		// 0x04
	DWORD base;			// 0x08
	DWORD allocated;	// 0x0C
	DWORD size;			// 0x10
	DWORD read;			// 0x14
};
