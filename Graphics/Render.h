#ifndef RENDER_H
#define RENDER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define LEONARDO_WINDOW_WIDTH 640
#define LEONARDO_WINDOW_HEIGHT 480

#define LEONARDO_COLOR_WHITE {255, 255, 255, 255}
#define LEONARDO_COLOR_BLACK {0, 0, 0, 255}

#define LEONARDO_FONT_QUARMIC "../Assets/Qarmic_sans_Abridged.ttf"


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
		/*
		 * This function aswers user input accordingly.
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