#include <SDL2/SDL.h>

class Window {
	private:
		SDL_Window* window;
		SDL_Event event;
	public:
		Window();
		~Window();
};

Window::Window() {
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