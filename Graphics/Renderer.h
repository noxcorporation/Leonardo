#ifndef RENDERER_H
#define RENDERER_H

#include "Leonardo.h"
#include "testing/Tahj/TahjTest.h"


class Renderer {
	private:
		/*
		 * This points to a renderer structure.
		 * Contains the data buffer we will compose before updating each frame.
		 **/
		SDL_Renderer* renderer;
		TahjTest* test;

	public:
		// Calls a default renderer for the current window.
		Renderer(SDL_Window*, int = -1, Uint32 = SDL_RENDERER_PRESENTVSYNC);
		~Renderer();
		/*
		 * Fills the renderer buffer with the frame data.
		 * Input: current game screen value.
		 **/
		void drawScreen(int);
		/*
		 * This function updates the window frame to the renderer buffer.
		 **/
		void updateFrame();
};

#endif