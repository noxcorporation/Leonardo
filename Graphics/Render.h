#ifndef RENDER_H
#define RENDER_H

#include "Leonardo.h"
#include "testing/Tahj/TahjTest.h"


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
		
		TahjTest* testObject;
	protected:
		/*
		 * This function answers user input accordingly.
		 * NOTE(Tahj): We will probably migrate input management to it's own class eventually.
		 **/
		bool processEventQueue();
		/*
		 * This function updates the window frame with the renderer buffer data.
		 **/
		void updateFrame();
	public:
		Window();
		~Window();
		int cycle();
};

#endif