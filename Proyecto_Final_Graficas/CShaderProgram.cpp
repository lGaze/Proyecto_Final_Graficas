#include "pch.h"
#include "CShaderProgram.h"
#include <gtc/matrix_access.hpp>


CShaderProgram::CShaderProgram()
{
}


CShaderProgram::~CShaderProgram()
{
}
#ifdef DIRECTX


#elif defined( OPENGL)

HRESULT CShaderProgram::setShaderParameters(ShaderParameters & shaderparam)
{
  
  GLuint loc;

  loc = glGetUniformLocation(shaderProgram, "View");
  glUniformMatrix4fv(loc, 1, false, &shaderparam.VM[0][0]);

  loc = glGetUniformLocation(shaderProgram, "Projection");
  glUniformMatrix4fv(loc, 1, false, &shaderparam.PM[0][0]);

  return S_OK;
}

void CShaderProgram::setDhader()
{
  glUseProgram(shaderProgram);
}

HRESULT CShaderProgram::createShaderProgram(const std::string & VSFilePath, const std::string & PSFilePath)
{
  m_vertexShader.CompileSFromFile(VSFilePath, GL_VERTEX_SHADER);
  m_fragmentShader.CompileSFromFile(PSFilePath, GL_VERTEX_SHADER);
  shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, m_vertexShader.Glshader);
  glAttachShader(shaderProgram, m_fragmentShader.Glshader);

  glBindAttribLocation(shaderProgram, 0, "Position");
  glBindAttribLocation(shaderProgram, 1, "Tex");

  glLinkProgram(shaderProgram);

  return S_OK;
}

#endif // DIRECTX