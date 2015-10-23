#include "Input.h"
#include "../testing/Tahj/TahjTest.h"


/*
 * This function aswers user input accordingly.
 **/
void Input::processQueue(GameScreen* gameScreen, TahjTest* test) {
	/*
	 * For each event, input is managed according to the current game screen.
	 **/
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		
		if (event.key.state == SDL_PRESSED)
			switch (*gameScreen) {
				case LEONARDO_SCREEN_1:
					test->redInput(event, gameScreen);
					break;
				
				default:
					break;
			}
		
		if (event.type == SDL_QUIT)							// Close to quit.
			*gameScreen = LEONARDO_SCREEN_EXIT;
	}
}
