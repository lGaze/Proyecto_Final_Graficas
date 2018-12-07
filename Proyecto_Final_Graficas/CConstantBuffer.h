#pragma once
#include <D3DX11.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class CConstantBuffer
{
public:
	CConstantBuffer();
	~CConstantBuffer();

	UINT flag = D3D11_BIND_CONSTANT_BUFFER;


};

