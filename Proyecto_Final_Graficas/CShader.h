#pragma once
#include "CPixelShader.h"
#include "CVertexShader.h"
#include <D3DX11.h>
#include <string>
#include "defines.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class CShader
{
public:
	CShader();
	~CShader();

#ifdef DIRECTX


	HRESULT CompileShaderFromFile(
		const wchar_t * szFileName,
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
  ID3D11ShaderResourceView*   m_pTextureRV = NULL;

private:

	CPixelShader PS;
	CVertexShader VS;
#else

  char * m_ShaderBuffer;
  GLuint Glshader;
  HRESULT LoadShaderSourceFile(const char * FilePath);
  HRESULT CompileSFromFile(const std::string &filepah, GLuint GLShaderTypeFlag);
 
#endif

};

