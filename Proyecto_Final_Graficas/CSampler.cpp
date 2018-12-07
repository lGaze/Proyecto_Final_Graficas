#include "pch.h"
#include "CSampler.h"


CSampler::CSampler()
{

}


CSampler::~CSampler()
{
}

void CSampler::createSamperDesc()
{
  sampler.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler.ComparisonFunc = D3D11_COMPARISON_NEVER;
  sampler.MinLOD = 0;
  sampler.MaxLOD = D3D11_FLOAT32_MAX;
}
