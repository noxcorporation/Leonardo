#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Window {
	private:
		SDL_Window *window;
		SDL_Event event;
	public:
		Window();
};

Window::Window () {
    window = SDL_CreateWindow(
        "Leonardo",
        500,
        500,
        640,
        480,
	SDL_WINDOW_OPENGL
    );
}