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
	while (SDL_PollEvent(&event) != 0) {
		if (event.key.keysym.sym == SDLK_DOWN){return 0;} // Down arrow to quit
		else if (event.type == SDL_QUIT){return 0;}
	}
	return 1;
}