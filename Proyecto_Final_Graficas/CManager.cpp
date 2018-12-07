#include "pch.h"
#include "CManager.h"
#include <vector>


CManager::CManager()
{
}

CManager::~CManager()
{
}

#ifdef DIRECTX

void CManager::CleanupDevice()
{
	device.ReleaseDevice();
	deviceContext.ReleaseDeviceContext();
	swapChain.ReleaseSwapChain();
}

HRESULT CManager::CreateRenderTargetView()
{
	return device.CreateRenderTargetView(texture.tex, NULL, &renderTarget.m_pRenderTargetView);
}

HRESULT CManager::CreateTexture2D()
{
	return device.CreateTexture2D(&texture.Desc, NULL, &depth.m_pDepthStencil);
}

HRESULT CManager::CreateDepthStencilView()
{
	return device.CreateDepthStencilView(depth.m_pDepthStencil, &depth.descDSV, &depth.m_pDepthStencilView);
}

HRESULT CManager::CreateVertexShader()
{
	return device.CreateVertexShader(
		shader.pVSBlob->GetBufferPointer(),
		shader.pVSBlob->GetBufferSize(),
		NULL,
		shader.getVertexShaderInterface());

}

HRESULT CManager::CreateInputLayout()
{
	return device.CreateInputLayout(
		layout.lay,
		layout.numElements,
		shader.pVSBlob->GetBufferPointer(),
		shader.pVSBlob->GetBufferSize(),
		&layout.m_pVertexLayout);
}

HRESULT CManager::CreatePixelShader()
{
	return device.CreatePixelShader(
		shader.pPSBlob->GetBufferPointer(),
		shader.pPSBlob->GetBufferSize(),
	  NULL,
		shader.getPixelshaderInterface());
}


HRESULT CManager::CreateBuffer(const D3D11_SUBRESOURCE_DATA * pInitialData,std::string type)
{
	
	if (type == "vertex")
	{
		return device.CreateBuffer(&buffer.bd, pInitialData, &buffer.m_pVertexBuffer);
	}
	if (type == "index")
	{
		return device.CreateBuffer(&buffer.bd, pInitialData, &buffer.m_pIndexBuffer);
	}
	if (type == "NC")
	{
		return device.CreateBuffer(&buffer.bd, pInitialData, &buffer.m_pCBNeverChanges);
	}
	if (type == "CEF")
	{
		return device.CreateBuffer(&buffer.bd, pInitialData, &buffer.m_pCBChangesEveryFrame);
	}
	if (type == "COR")
	{
		return device.CreateBuffer(&buffer.bd, pInitialData, &buffer.m_pCBChangeOnResize);
	}
}

HRESULT CManager::CreateSamplerState()
{
	return device.CreateSamplerState(&sampler.sampler, &sampler.m_pSamplerLinear);

}

HRESULT CManager::GetBuffer(UINT Buffer)
{
	return swapChain.GetBuffer(Buffer, __uuidof(ID3D11Texture2D), (LPVOID*)&texture.tex);
}

HRESULT CManager::Present(UINT SyncInterval, UINT Flags)
{
	return swapChain.Present(SyncInterval, Flags);
}

void CManager::OMSetRenderTargets(UINT NumViews)
{
	deviceContext.OMSetRenderTargets(NumViews, &renderTarget.m_pRenderTargetView, depth.m_pDepthStencilView);
}

void CManager::RSSetViewports(
	UINT NumViewports)
{
	deviceContext.RSSetViewports(NumViewports, &viewport.vp);
}

void CManager::IASetInputLayout()
{
	deviceContext.IASetInputLayout(layout.m_pVertexLayout);
}

void CManager::IASetVertexBuffers(
UINT StartSlot, 
UINT NumBuffers,
	const UINT * pStrides,
	const UINT * pOffsets)
{
	deviceContext.IASetVertexBuffers(StartSlot, NumBuffers, &buffer.m_pVertexBuffer, pStrides, pOffsets);
}

void CManager::IASetIndexBuffer(DXGI_FORMAT Format, UINT Offset)
{
	deviceContext.IASetIndexBuffer(buffer.m_pIndexBuffer, Format, Offset);
}

void CManager::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology)
{
	deviceContext.IASetPrimitiveTopology(Topology);
}

void CManager::UpdateSubresource(
	std::string type,
	UINT DstSubresource,
	const D3D11_BOX * pDstBox,
	const void * pSrcData,
	UINT SrcRowPitch,
	UINT SrcDepthPitch)
{

	if (type == "NC")
	{
		deviceContext.UpdateSubresource(buffer.m_pCBNeverChanges, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
	}
	if (type == "COR")
	{
		deviceContext.UpdateSubresource(buffer.m_pCBChangeOnResize, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
	}
	if (type == "CEF")
	{
		deviceContext.UpdateSubresource(buffer.m_pCBChangesEveryFrame, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
	}

}

void CManager::ClearRenderTargetView(const FLOAT ColorRGBA[4])
{
	deviceContext.ClearRenderTargetView(renderTarget.m_pRenderTargetView, ColorRGBA);
}

void CManager::ClearDepthStencilView(
	UINT ClearFlags,
	FLOAT Depth,
	UINT8 Stencil)
{
	deviceContext.ClearDepthStencilView(
		depth.m_pDepthStencilView,
		ClearFlags,
		Depth,
		Stencil);
}

void CManager::VSSetShader(
	ID3D11ClassInstance * const * ppClassInstances,
	UINT NumClassInstances)
{
	deviceContext.VSSetShader(
		*shader.getVertexShaderInterface(),
		ppClassInstances,
		NumClassInstances);
}

void CManager::VSSetConstantBuffers(
	UINT StartSlot,
	UINT NumBuffers,
	std::string type)
{
	
	if (type == "NC")
	{
		deviceContext.VSSetConstantBuffers(StartSlot, NumBuffers, &buffer.m_pCBNeverChanges);
	}
	if (type == "COR")
	{
		deviceContext.VSSetConstantBuffers(StartSlot, NumBuffers, &buffer.m_pCBChangeOnResize);
	}
	if (type == "CEF")
	{
		deviceContext.VSSetConstantBuffers(StartSlot, NumBuffers, &buffer.m_pCBChangesEveryFrame);
	}
}

void CManager::PSSetShader(
	ID3D11ClassInstance * const * ppClassInstances,
	UINT NumClassInstances)
{
	deviceContext.PSSetShader(*shader.getPixelshaderInterface(), ppClassInstances, NumClassInstances);
}

void CManager::PSSetConstantBuffers(
	UINT StartSlot,
	UINT NumBuffers)
{
	deviceContext.PSSetConstantBuffers(StartSlot, NumBuffers, &buffer.m_pCBChangesEveryFrame);
}

void CManager::PSSetShaderResources(
	UINT StartSlot,
	UINT NumViews)
{
	deviceContext.PSSetShaderResources(StartSlot, NumViews, &shader.m_pTextureRV);
}

void CManager::PSSetSamplers(
	UINT StartSlot,
	UINT NumSamplers)
{
	deviceContext.PSSetSamplers(StartSlot, NumSamplers, &sampler.m_pSamplerLinear);
}

void CManager::DrawIndexed(
	UINT IndexCount,
	UINT StartIndexLocation,
	INT BaseVertexLocation)
{
	deviceContext.DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
}

HRESULT CManager::CreateDeviceAndSwapChain()
{


	HRESULT hr;
	for (UINT driverTypeIndex = 0; driverTypeIndex < device.numFeatureLevels; driverTypeIndex++)
	{

		*device.getDriverType() = device.driverTypes[driverTypeIndex];

		hr = D3D11CreateDeviceAndSwapChain(
			NULL,
			*device.getDriverType(),
			NULL,
			device.deviceFlags,
			device.featureLevels,
			device.numFeatureLevels,
			device.sdk,
			&swapChain.sd,
			swapChain.getSwapChainPointer(),
			device.getDevicePointer(),
			device.getFeatureLevel(),
			deviceContext.getDeviceContext());

		if (SUCCEEDED(hr))
			break;
	}
	if (FAILED(hr))
		return hr;
}

void CManager::CreateDescTexture(UINT Width, UINT Height,  DXGI_FORMAT Format, D3D11_USAGE Usage)
{

  texture.CreateDesc(
    Width,
    Height,
    Format,
    Usage
  );

}

void CManager::CreateDescDSV()
{
  depth.CreateDescDSV(texture.Desc);
}

void CManager::CreateSamplerDesc()
{
  sampler.createSamperDesc();
}

HRESULT CManager::Init(UINT width, UINT height, HWND  g_hWnd)
{
	HRESULT hr = S_OK;

	hr = device.Init();
	if (FAILED(hr))
		return hr;

	deviceContext.Init();

	hr = swapChain.Init(width, height, g_hWnd);
	if (FAILED(hr))
		return hr;

	hr = CreateDeviceAndSwapChain();
	if (FAILED(hr))
		return hr;

	hr = viewport.init(width, height);

	hr = layout.Init();

	return hr;
}

void CManager::CreateDescBuffer(std::string usage, UINT bytewidth, std::string buffertype, UINT cpuflags)
{
	buffer.CreateDescBuffer(usage, bytewidth, buffertype, cpuflags);
}

HRESULT CManager::CompileShaderFromFile(const wchar_t * szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel)
{
	if (szEntryPoint == "VS")
	{
		return shader.CompileShaderFromFile(szFileName, szEntryPoint, szShaderModel, &shader.pVSBlob);
	}	
	if (szEntryPoint == "PS")
	{
		return shader.CompileShaderFromFile(szFileName, szEntryPoint, szShaderModel, &shader.pPSBlob);
	}
}

void CManager::releasePS()
{
	shader.releasePS();
}

void CManager::releaseVS()
{
	shader.releaseVS();
}

HRESULT CManager::loadTexture(LPCWSTR pSrcFile)
{
  return D3DX11CreateShaderResourceViewFromFile(*device.getDevicePointer(), pSrcFile, NULL, NULL, &shader.m_pTextureRV , NULL);
}

#else

void CManager::createRenderTarget(GLFWwindow * window)
{
  renderTarget.creteRenderTarget(window);
}

void CManager::CreateDSV()
{
  depth.createDSV(renderTarget.width, renderTarget.height);
}

void CManager::createViewport()
{
  viewport.createViewport(renderTarget.width, renderTarget.height);
}

void CManager::createVertexBuffer(std::vector<GLfloat> vertices)
{
    buffer.vertex.createVertexBuffer(vertices);
}

void CManager::createIndexBuffer(std::vector<short> indices)
{
  buffer.index.createIndexBuffer(indices);
}

HRESULT CManager::createShaderProgram(const std::string & VSFilePath, const std::string & PSFilePath)
{
  return shaderprogram.createShaderProgram(VSFilePath, PSFilePath);
}


#endif // DIRECTX
