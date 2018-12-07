#include "pch.h"
#include "CTexture.h"


CTexture::CTexture()
{
}


CTexture::~CTexture()
{
}

void CTexture::CreateDesc(
  UINT Width, 
  UINT Height,
  DXGI_FORMAT Format,
  D3D11_USAGE Usage)
{
  Desc.Width = Width;
  Desc.Height = Height;
  Desc.MipLevels = 1;
  Desc.ArraySize = 1;
  Desc.Format = Format;
  Desc.SampleDesc.Count = 1;
  Desc.SampleDesc.Quality = 0;
  Desc.Usage = Usage;
  Desc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
  Desc.CPUAccessFlags = 0;
  Desc.MiscFlags = 0;
}
