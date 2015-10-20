#include "Input.h"


/*
 * This function aswers user input accordingly.
 **/
void Input::processQueue(int* gameScreen) {
	/*
	 * For each event, input is managed according to the current game screen.
	 **/
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		
		if (event.key.state == SDL_PRESSED)
			switch (*gameScreen) {
				case LEONARDO_SCREEN_1:
					if (event.key.keysym.sym == SDLK_BACKSPACE)	// Backspace to go back.
						*gameScreen = LEONARDO_SCREEN_EXIT;
					if (event.key.keysym.sym == SDLK_DOWN)		// Down arrow to progress.
						*gameScreen = LEONARDO_SCREEN_2;
					break;
					
				case LEONARDO_SCREEN_2:
					if (event.key.keysym.sym == SDLK_BACKSPACE)	// Backspace to go back.
						*gameScreen = LEONARDO_SCREEN_1;
					if (event.key.keysym.sym == SDLK_RETURN)	// Enter to quit.
						*gameScreen = LEONARDO_SCREEN_EXIT;
					if (event.key.keysym.sym == SDLK_a)			// A to progress.
						*gameScreen = LEONARDO_SCREEN_LEVEL;
					break;
					
				case LEONARDO_SCREEN_LEVEL:
					if (event.key.keysym.sym == SDLK_BACKSPACE)	// Backspace to go back.
						*gameScreen = LEONARDO_SCREEN_2;
					if (event.key.keysym.sym == SDLK_ESCAPE)	// Escape to quit.
						*gameScreen = LEONARDO_SCREEN_EXIT;
					break;
			}
		
		if (event.type == SDL_QUIT)							// Close to quit.
			*gameScreen = LEONARDO_SCREEN_EXIT;
	}
}
