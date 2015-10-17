#include "Render.h"

/*
 * This constructor initializes SDL and opens a window.
 **/
Window::Window() {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
		"Leonardo",
		/*
		 * Default window position should be center screen.
		 **/
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	// We must call SDL_CreateRenderer in order for draw calls to affect this window.
	renderer = SDL_CreateRenderer(window, -1, 0);
}

/*
 * This destructor closes the window and SDL to free memory.
 **/
Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/*
 * No arguments. Returns program exit code.
 * Main program method.
 * This function cycles to update the frame and listen to user input.
 * One cycle is one frame?
 **/
int Window::refresh() {
	bool quit = false; //Don't need it as class variable
	do{
		if (processEventQueue()) {quit = true;}
		SDL_Delay(17); //aim for 60 fps (17 ms frame time)
	}while(!quit);
	return 0;
}

/*
 * No arguments. Returns input queue state.
 * This function aswers user input accordingly.
 **/
bool Window::processEventQueue() {
	while (SDL_PollEvent(&event) != 0) {	//Clear the event queue
		if (event.key.keysym.sym == SDLK_DOWN)
			return true	// Down arrow to quit
		else if (event.type == SDL_QUIT)
			return true;
	}
	return false;
}
