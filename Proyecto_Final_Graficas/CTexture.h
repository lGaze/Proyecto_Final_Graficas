#pragma once
#include <d3dx11.h>
#include <d3dcompiler.h>


class CTexture
{
public:
  CTexture();
  ~CTexture();

  void CreateDesc(UINT Width,
  UINT Height,
  DXGI_FORMAT Format,
  D3D11_USAGE Usage);


  ID3D11Texture2D* tex;
  D3D11_TEXTURE2D_DESC Desc;

};

