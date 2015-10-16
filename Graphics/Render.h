#include <SDL2/SDL.h>

class Window {
	private:
		SDL_Window* window;
		SDL_Event event;
	public:
		Window();
		~Window();
		int refresh();
};