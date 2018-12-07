#pragma once

#include "CShader.h"
#include "defines.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "defines.h"

class CShaderProgram
{
  struct ShaderParameters
  {
    glm::mat4x4 VM;
    glm::mat4x4 PM;

  };

public:
  CShaderProgram();
  ~CShaderProgram();

#ifdef DIRECTX

#else

  CShader m_vertexShader;
  CShader m_fragmentShader;

  GLuint shaderProgram;
  HRESULT setShaderParameters(ShaderParameters &shaderparam);
  void setDhader();
  HRESULT createShaderProgram(const std::string & VSFilePath, const std::string & PSFilePath);

#endif // DIRECTX
};

