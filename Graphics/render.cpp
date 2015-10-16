#include <SDL2/SDL.h>

class Window {
	private:
		SDL_Window* window;
		SDL_Event event;
	public:
		Window();
		~Window();
		//Add cycling function to refresh program and frame state.
};

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