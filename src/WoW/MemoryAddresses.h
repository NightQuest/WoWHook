#pragma once

// Globals
#define EngineIsPlayerInGameAddr				0x007CF792
#define DBItemCache								0x0085C828

// Classes
#define CGxDeviceD3dPtrAddr						0x0085CF88
#define CGxDeviceOpenGlPtrAddr					0x0022C198

// Functions
#define EngineIsPlayerInGameOrOnInitialLoadAddr	0x004C5330
#define ObjectMgrGetActivePlayerGUIDAddr		0x000D2790
#define ObjectMgrGetActivePlayerObjectAddr		0x000028F0
#define ObjectMgrGetObjectAddr					0x00005FD5
#define ClientServicesFormatAndLoginAddr		0x000D7A30

#define CDataStoreInitializeAddr				0x00000050
#define CDataStoreDestroyAddr					0x00264CF0

#define CDataStorePutByteAddr					0x00079FE0
#define CDataStorePutInt16Addr					0x0007A040
#define CDataStorePutInt32Addr					0x0007A0A0
#define CDataStorePutInt64Addr					0x0007A100
#define CDataStorePutFloatAddr					0x0007A160
#define CDataStorePutStringAddr					0x0007A300
#define CDataStorePutBytesAddr					0x0007A1C0
#define CDataStorePutVec3Addr					0x00005DA0

#define CDataStoreGetByteAddr					0x0007A340
#define CDataStoreGetInt16Addr					0x0007A380
#define CDataStoreGetInt32Addr					0x0007A3C0
#define CDataStoreGetInt64Addr					0x0007A400
#define CDataStoreGetFloatAddr					0x0007A440
#define CDataStoreGetStringAddr					0x0007A480
#define CDataStoreGetBytesAddr					0x0007A560
#define CDataStoreGetVec3Addr					0x00000190

#define CDataStoreAllocAddr						0x00000010
#define CDataStoreFreeAddr						0x00000030
#define CDataStoreGetInt8_2Addr					0x00000140
#define CDataStoreGetInt32_ReturnInt32Addr		0x00000170
#define CDataStoreReleaseAddr					0x00002880
#define CDataStoreInitPacket2Addr				0x00002EC0
#define CDataStoreReleasePacket2Addr			0x00002F10
#define CDataStoreCreateFromDataAddr			0x000659A0
#define CDataStorePutInt8AtPosAddr				0x00079EF0
#define CDataStorePutInt16AtPosAddr				0x00079F40
#define CDataStorePutInt32AtPosAddr				0x00079F90

#define CDataStorePutCString_3Addr				0x0007A280
#define CDataStoreCanReadAddr					0x0007A290
#define CDataStoreGetIntArrayAddr				0x0007A5F0
#define CDataStoreGetCString_2Addr				0x0007A6A0
#define CDataStoreReadBytesAddr					0x0007A6B0
#define CDataStoreGetInt8_3Addr					0x000D2870
#define CDataStoreReadInt32Addr					0x0010E420
#define CDataStoreReadAddonInfoPacketAddr		0x001F69A0
#define CDataStoreReset_0Addr					0x00235C00
#define CDataStoreLoadAddr						0x002480B0
#define CDataStoreReadPackedVector3Addr			0x003142B0
#define CDataStoreGetWowGUIDAddr				0x0036CC20
#define CDataStorePutPackedGuidAddr				0x0036CD00
#define CDataStoreCanReadNumBytesAddr			0x004CABF0
#define CDataStoredtorAddr						0x004CBF50
#define CDataStoreDetachBufferProxyAddr			0x004CBFC0
#define CDataStoreNewAddr						0x004CC0B0
#define CDataStoreFree_0Addr					0x004CC160

#define CItemGetSafeInventoryItemArtAddr		0x00309A00
#define CItemGetRightClickFunctionAddr			0x00306280
#define CItemGetCacheEntryAddr					0x00306360
#define DBCacheGetInfoBlockByIDAddr				0x0027BA30
#define GetInventoryArtAddr						0x00309910

// Patch addresses
#define Direct3DLibraryNameAddr					0x0028DD92
#define Direct3DExLibraryNameAddr				0x0029FAB2
#define SigCompareLoopAddr						0x004156DA
#define UnderstandAnyLanguageAddr				0x00104955
