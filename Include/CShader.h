#pragma once
#include "CPixelShader.h"
#include "CVertexShader.h"
#include <D3DX11.h>

class CShader
{
public:
	CShader();
	~CShader();

	HRESULT CompileShaderFromFile(
		WCHAR* szFileName,
		LPCSTR szEntryPoint,
		LPCSTR szShaderModel, 
		ID3DBlob** ppBlobOut);

	void releasePS();
	void releaseVS();

	inline ID3D11VertexShader ** getVertexShaderInterface() 
	{return VS.getInterface();};
	inline ID3D11PixelShader ** getPixelshaderInterface() 
	{ return PS.getInterface();};

	//TODO: sacar esto de aqui.
	ID3DBlob * pPSBlob = NULL;
	ID3DBlob * pVSBlob = NULL;

private:

	CPixelShader PS;
	CVertexShader VS;


};

