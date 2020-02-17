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

// Classes
#include "Classes/Engine.h"

// Fake Direct3D9
#include "FakeDirect3D9/fake_IDirect3D9.h"
#include "FakeDirect3D9/fake_IDirect3DDevice9.h"

// Application
#include "Application.h"
#include "WoWHook.h"