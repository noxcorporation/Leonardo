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

void Window::refresh() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN)
			delete this;
	}
}
