#include "pch.h"
#include "CApp_Opengl.h"
#include <vector>


#ifdef OPENGL


CApp_Opengl::CApp_Opengl()
{
}


CApp_Opengl::~CApp_Opengl()
{
}

bool CApp_Opengl::Init()
{
  

    m_Manager.createRenderTarget(window);
    m_Manager.CreateDSV();
    m_Manager.createViewport();


     std::vector<GLfloat>vertices =
      {
       -1.0f, -1.0f, -1.0f,
       -1.0f, -1.0f,  1.0f,
       -1.0f,  1.0f, -1.0f,
       -1.0f,  1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f,  1.0f,  1.0f
      };

      m_Manager.createVertexBuffer(vertices);

    
          std::vector<short> indices =
        {
          0, 1, 2,
          1, 3, 2,

          4, 6, 5,
          5, 6, 7,

          0, 5, 1,
          0, 4, 5,

          2, 7, 6,
          2, 3, 7,

          0, 6, 4,
          0, 2, 6,

          1, 7, 3,
          1, 5, 7
        };

        m_Manager.createIndexBuffer(indices);

        m_Manager.createShaderProgram("Tutorial07VS.glsl","Tutorial07PS.glsl");



        //Camara
        m_view = glm::lookAt(glm::vec3(0.0f, 3.0f, -6.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        m_projection = glm::perspective(0.785398163f, (float)(640 / 480), 0.01f, 100.0f);


  return true;

}

bool CApp_Opengl::InitWindow()
{

	/* Initialize the library */
	if (!glfwInit())
		return false;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Proyeycto_Final", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
  glewInit();

  return true;
}

int CApp_Opengl::run()
{

	if (!InitWindow())
	{
		std::cout << "InitWindow Failed!" << std::endl;
	}
	if (!Init())
	{
    std::cout << "Init Failed" << std::endl;
	}

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		Render();
	}

	glfwTerminate();

	return 0;
}

void CApp_Opengl::Render()
{
	/* Render here */
	glClearColor(0.0f, 0.0, 0.15f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();

}

#endif // OPENGL