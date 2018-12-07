#include "pch.h"
#include "CShader.h"
#include "D3Dcompiler.h"
#include <iostream>
#include <fstream>



CShader::CShader()
{
}


CShader::~CShader()
{
}

#ifdef DIRECTX

HRESULT CShader::CompileShaderFromFile(
	const wchar_t * szFileName,
	LPCSTR szEntryPoint,
	LPCSTR szShaderModel,
	ID3DBlob ** ppBlobOut)
{
	HRESULT hr = S_OK;

	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

	ID3DBlob* pErrorBlob;
	hr = D3DX11CompileFromFile(szFileName, NULL, NULL, szEntryPoint, szShaderModel,
		dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL);
	if (FAILED(hr))
	{
		if (pErrorBlob != NULL)
			OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
		if (pErrorBlob) pErrorBlob->Release();
		return hr;
	}
	if (pErrorBlob) pErrorBlob->Release();

	return S_OK;
}

void CShader::releasePS()
{
	pPSBlob->Release();
}

void CShader::releaseVS()
{
	pVSBlob->Release();
}

#else

HRESULT CShader::LoadShaderSourceFile(const char * _FilePath)
{
 
    std::ifstream fin;
    int fileSize;
    char input;

  
    fin.open(_FilePath);

    if (fin.fail())
    {
      std::cout << "Failed to open file" << std::endl;
      return E_FAIL;
    }

    fileSize = 0;

    fin.get(input);

    while (!fin.eof())
    {
      fileSize++;
      fin.get(input);
    }

    fin.close();

    m_ShaderBuffer =  new char[fileSize + 1];
    if (!m_ShaderBuffer)
    {
      return E_FAIL;
    }


    fin.open(_FilePath);

    fin.read(m_ShaderBuffer, fileSize);

    fin.close();

    m_ShaderBuffer[fileSize] = '\0';

    return S_OK;
}

HRESULT CShader::CompileSFromFile(const std::string &filepah, GLuint GLShaderTypeFlag)
{
  LoadShaderSourceFile(filepah.c_str());

  Glshader = glCreateShader(GLShaderTypeFlag);
  glShaderSource(Glshader, 1, &m_ShaderBuffer, NULL);
  glCompileShader(Glshader);
  return S_OK;

}

#endif // DIRECTX