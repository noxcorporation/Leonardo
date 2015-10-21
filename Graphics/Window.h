#ifndef RENDER_H
#define RENDER_H

#include "Leonardo.h"
#include "Renderer.h"


class Window {
	private:
		SDL_Window* window;
		Renderer* renderer;
		/*
		 * Describes the current game screen.
		 **/
		int gameScreen;
	public:
		Window();
		~Window();
		int cycle();
};

#endif