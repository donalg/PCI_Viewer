// Required Headers External Headers:
#include <iostream>
#include <string>
#include <thread>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

// Required Local Headers:
#include "../includes/display/display.h"
#include "../includes/shader/shader.h"
#include "../includes/mesh/mesh.h"
#include "../includes/texture/texture.h"
#include "../includes/transform/transform.h"
#include "../includes/camera/camera.h"
#include "../includes/model/model.h"


// Window shape definition
#define windowWidth 1000
#define windowHeight 800

/* /////////////////////// Program information:



*/

bool displayUpdater(transform& Transform, camera &Cam); // Function definition

void main(int argc, char* argv[])
{
  // Obtain *.pci path for opening:
  std::string filename;
  std::ifstream fileAccess;

  std::cout << "Please enter file name of PCI: ";
  std::getline( std::cin, filename);
  std::endl;

  fileAccess.open( filename.c_str() );

  if (!fileAccess)
  {
    std::cout << "Unable to open file: " << filename << std::endl;
    return -1
  }

  // Read File here

  std::string currentExecName = argv[0];

  // Initalise the SDL display window:
  display myDisplay(windowWidth, windowHeight, " Point Cloud Intensity (PCI) Viewer  ")

  // initalise and define the location of orthographic projection camera
  camera myCamera(glm::vec(0, 0, -10), (float) windowWidth, (float) windowHeight, 10.0f)

  // Initalise model reader
  model myModel(filename);

  // Initalise mesh
	mesh myMesh(Model);

  transform myTransform;
  myTransform.getPos().y = -10;
  myTransform.getRot().z = -90.0f;
  myTransform.getRot().x = -90.0f;

  bool isRunning = true;

  while(isRunning)
  {
    myDisplay.clear(0.0f, 0.15f, 0.25f, 0.8f);

    isRunning = displayUpdater(myTansform, myCamera);

    mesh.draw(meshPoints);

    myDisplay.swapBuffers();

  }

}

/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// Update display:
/////////////////////////////////////////////////////////

bool displayUpdater(transform &TransformMAT, camera &Cam)
{
  bool mouseMotion = false; unsigned int mouseMotionIndex = 0;
	bool zoom = false, translate = false, rotate = false;
	float zoomFloat = Cam.getZoom();
	bool RUNNING = true;
  std::vector <SDL_Event> events;
  SDL_Event e;
  // Pole and store events:
  while (SDL_PollEvent(&e) != 0)
  {
    events.push_back(e);
  }

  // Read events and set flags:
  for (unsigned int i = 0; i < events.size(); i++)
  {
    switch (events[i].type)
    {
      case SDL_QUIT:
          RUNNING = false;
					break;
      case SDL_MOUSEMOTION:
						mouseMotion = true;
						mouseMotionIndex = i;
			case SDL_KEYDOWN:
						switch (events[i].key.keysym.sym)
						 {
							case SDLK_t:
									translate = true;
									break;
							case SDLK_r:
									rotate = true;
									break;
							case SDLK_z:
									zoom = true;
									break;
						}
    }
  }
	if (mouseMotion)
	{
			if(translate)
			{
				TransformMAT.getPos().x += -1.5*events[mouseMotionIndex].motion.xrel;
		    TransformMAT.getPos().y += -1.5*events[mouseMotionIndex].motion.yrel;
			}
			if(zoom)
			{
				zoomFloat += events[mouseMotionIndex].motion.yrel;
				if (zoomFloat < 0.5) {zoomFloat = 0.5; }
				Cam.upDateZoom(zoomFloat);
			}
			if (rotate)
			{
				TransformMAT.getRot().x += 0.2*events[mouseMotionIndex].motion.xrel;
				TransformMAT.getRot().y += 0.2*events[mouseMotionIndex].motion.yrel;
			}
	}
	// Clear events Buffer:
	events.clear();
	return RUNNING;
}
