// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"
#include "defines.h"

#if defined DIRECTX

#pragma comment(lib, "d3d11")
#pragma comment(lib, "d3dcompiler")
#pragma comment(lib, "d3dx11d")

#elif defined OPENGL

#pragma comment(lib, "glfw3")
#pragma comment(lib, "opengl32")
#pragma comment(lib, "glew32s")

#endif // 

// In general, ignore this file, but keep it around if you are using pre-compiled headers.
