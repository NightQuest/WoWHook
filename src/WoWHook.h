#pragma once

#pragma data_seg(".wowhook_shared")
static HINSTANCE hInstance;
static HMODULE hDinput = 0, hD3d9 = 0;
static unsigned int instances = 0;
static Application app;
#pragma data_seg()
