#include "Render.h"

Window::Window() {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
		"Leonardo",
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

int Window::refresh() {
	bool quit = false; //Don't need it as class variable
	do{
		if (clearEventQueue()) {quit = true;}
		SDL_Delay(17); //aim for 60 fps (17 ms frame time)
	}while(!quit);
	return 0;
}

bool Window::clearEventQueue() {
	while (SDL_PollEvent(&event) != 0) { //Clear the event queue
		if (event.key.keysym.sym == SDLK_DOWN) {return true;} // Down arrow to quit
		else if (event.type == SDL_QUIT) {return true;}
	}
	return false;
}
	
