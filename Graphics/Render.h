#include <SDL2/SDL.h>


class Window {
	private:
		SDL_Window* window;
		/*
		 * This points to a renderer object
		 * which contains the draw data buffer 
		 * we will push to before updating each frame
		 **/
		SDL_Renderer* renderer;
		SDL_Event event;
	protected:
		bool processEventQueue();
		/*
		 * This function updates the window frame with the renderer buffer data.
		 **/
		void updateFrame();
	public:
		Window();
		~Window();
		int refresh();
};