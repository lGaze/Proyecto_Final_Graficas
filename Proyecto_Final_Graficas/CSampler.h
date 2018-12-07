#pragma once
#include <d3dx11.h>
#include <d3dcompiler.h>

class CSampler
{
public:
  CSampler();
  ~CSampler();

  void createSamperDesc();


  D3D11_SAMPLER_DESC sampler;
  ID3D11SamplerState*         m_pSamplerLinear = NULL;
};

