#ifndef WINDOW_H
#define WINDOW_H

#include "../Leonardo.h"
#include "Renderer.h"


class Window {
	private:
		SDL_Window* window;
		Renderer* renderer;
		//Describes the current game screen.
		GameScreen gameScreen;
		Clock* cycleClock;
		TahjTest* test;
	public:
		Window();
		~Window();
		int cycle();
};

#endif
