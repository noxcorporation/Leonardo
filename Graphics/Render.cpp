#include "Render.h"

Window::Window() {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
		"Leonardo",
		/*
		 * TO CHANGE:
		 * Default window position should be center screen.
		 **/
		500,
		500,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
}

Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/*
 * No arguments. Returns program exit code.
 * Main program method.
 * This function cycles to update the frame and listen to user input.
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
	while (SDL_PollEvent(&event) != 0) { //Clear the event queue
		if (event.key.keysym.sym == SDLK_DOWN) {return true;} // Down arrow to quit
		else if (event.type == SDL_QUIT) {return true;}
	}
	return false;
}