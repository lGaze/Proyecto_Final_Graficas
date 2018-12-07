#include "pch.h"
#include "CBuffer.h"


CBuffer::CBuffer()
{
}


CBuffer::~CBuffer()
{
}

#ifdef DIRECTX

void CBuffer::CreateDescBuffer(std::string usage, UINT bytewidth, std::string buffertype, UINT cpuflags)
{

	if (usage == "default")
	{
		bd.Usage = D3D11_USAGE_DEFAULT;
	}
	if (usage == "inmutable")
	{
		bd.Usage = D3D11_USAGE_IMMUTABLE;
	}
	if (usage == "dynamic")
	{
		bd.Usage = D3D11_USAGE_DYNAMIC;
	}
	if (usage == "staging")
	{
		bd.Usage = D3D11_USAGE_STAGING;
	}

	bd.ByteWidth = bytewidth;

	if (buffertype == "constant")
	{
		bd.BindFlags = constant.flag;
	}
	if (buffertype == "vertex")
	{
		bd.BindFlags = vertex.flag;

	}
	if (buffertype == "index")
	{
		bd.BindFlags = index.flag;
	}

	bd.CPUAccessFlags = cpuflags;
}

#else

#endif // DIRECTX