#pragma once

// System headers
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <d3d9.h>

// std headers
#include <memory>
using namespace std;

// WoW definitions
#include "WoW/MemoryAddresses.h"
#include "WoW/CGxDeviceD3d.h"
#include "WoW/CDataStore.h"

// Classes
#include "Classes/Engine.h"
#include "Classes/ObjectMgr.h"
#include "Classes/ClientServices.h"

// Fake Direct3D9
#include "FakeDirect3D9/fake_IDirect3D9.h"
#include "FakeDirect3D9/fake_IDirect3DDevice9.h"

// Application
#include "Application.h"
#include "WoWHook.h"
