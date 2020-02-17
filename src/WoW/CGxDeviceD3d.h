#pragma once

class CGxDeviceD3d
{
public:
	virtual void Dummy006A3070(void* ptrForSomeClass);
	virtual void Dummy006A4C30(float unk);
	virtual void Dummy0068E900(DWORD unk);
	virtual void Dummy006A00C0();
	virtual void Dummy0068E810();
	virtual void Dummy006843B0();
	virtual void Dummy006843E0();
	virtual void Dummy00684410();
	virtual void Dummy0068FE80(bool bDestroy);
	virtual bool Dummy00690830(DWORD unk, DWORD unk2);
	virtual bool DeviceCreate(DWORD unk, DWORD unk2); // 00690750
	virtual void DeviceDestroy(); // 006905F0
	virtual void EvictManagedResources(); // 0068E450
	virtual bool DeviceSetFormat(void* someStructure); // 006904D0
	virtual void Dummy0068E4A0();
	virtual void Dummy0069FE80();
	virtual void Dummy0068E4C0(DWORD unk);
	virtual HWND GetWindowHandle(); // 0069FED0
	virtual void Dummy00682D30();
	virtual void Dummy00684260();
	virtual void Dummy0068FED0();
	virtual void Dummy006A1950();
	virtual void Dummy00690230();
	virtual void Dummy0068F770();
	virtual void Dummy0068E510();
	virtual void Dummy0068E540();
	virtual void Dummy0068F900();
	virtual void Dummy0068F950();
	virtual void Dummy0069FF40();
	virtual void Dummy006853B0();
	virtual void Dummy006853D0();
	virtual void Dummy00685460();
	virtual void Dummy00685480();
	virtual void Dummy00685510();
	virtual void Dummy00685530();
	virtual void Dummy006A5A00();
	virtual void Dummy006A9920();
	virtual void GetDeviceInfoStr(char* outPtr, unsigned int max_length); // 0068E570
	virtual void Dummy006A3450();
	virtual void Dummy006A74B0();
	virtual void Dummy006A9B40();
	virtual void Dummy006A9E00();
	virtual void Dummy006A3620();
	virtual void Dummy006855C0();
	virtual void Dummy006845B0();
	virtual void Dummy00685640();
	virtual void Dummy00682FA0();
	virtual void Dummy00682F70();
	virtual void Dummy00684590();
	virtual void Dummy00632050();
	virtual void Dummy00632050_2();
	virtual void Dummy00685EB0(DWORD unk, DWORD unk2);
	virtual void Dummy0069FF80();
	virtual void Dummy0068E720();
	virtual void Dummy0068FCE0();
	virtual void Dummy0068FAE0();
	virtual void Dummy0068FD00();
	virtual void Dummy00685C60();
	virtual void Dummy006A2BB0();
	virtual void Dummy006A30D0();
	virtual void Dummy006A31E0();
	virtual void Dummy00632050_3();
	virtual void Dummy0068E9C0();
	virtual void Dummy006A0190();
	virtual void Dummy0068EA10();
	virtual void Dummy006A0240();
	virtual void Dummy0068EA90();
	virtual void Dummy006A0310();
	virtual void Dummy006AA130();
	virtual void Dummy006AA190();
	virtual void Dummy006833E0();
	virtual void Dummy006A5D50();
	virtual void Dummy006A5E10();
	virtual void Dummy0068E750();
	virtual void Dummy00683650();
	virtual void Dummy0068E7E0();
	virtual void Dummy0068E980();
	virtual void Dummy006A0110();
	virtual void Dummy0068E9A0();
	virtual void Dummy006A0120();
	virtual void Dummy006A0130();
	virtual void Dummy00653A10();
	virtual void Dummy005EEB70();
	virtual void Dummy00653A10_2();
};
