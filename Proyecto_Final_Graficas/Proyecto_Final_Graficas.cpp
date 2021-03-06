#include "pch.h"
#include <iostream>
#include <memory>
#include "CApp_Directx.h"
#include "CApp_Opengl.h"
#include "CApp_gen.h"


/************************************************************************/
/* Entry point to the program.                                          */
/* Initializes everything and goes into a message processing.           */
/* loop. Idle time is used to render the scene.                         */
/************************************************************************/
int main()
{
#ifdef DIRECTX

	std::shared_ptr<CApp> direts(new CApp_Directx());
	return direts->run();

#elif defined(OPENGL)

  std::shared_ptr<CApp> Opengl(new CApp_Opengl());
	return Opengl->run();

#else

  std::shared_ptr<CApp> gen(new CApp_gen());
  return gen->run();

#endif
}