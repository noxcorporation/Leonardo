#include "Input.h"
#include "../testing/Tahj/TahjTest.h"


/*
 * This function aswers user input accordingly.
 **/
void Input::processQueue(GameScreen* gameScreen) {
	/*
	 * For each event, input is managed according to the current game screen.
	 **/
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		
		if (event.key.state == SDL_PRESSED)
			switch (*gameScreen) {
				
				case LEONARDO_SCREEN_1:
					TahjInputTest::diamond(event, gameScreen);
					break;
					
				case LEONARDO_SCREEN_2:
					TahjInputTest::orange(event, gameScreen);
					break;
					
				case LEONARDO_SCREEN_3:
					TahjInputTest::red(event, gameScreen);
					break;
				
				default:
					break;
			}
		
		if (event.type == SDL_QUIT)							// Close to quit.
			*gameScreen = LEONARDO_SCREEN_EXIT;
	}
}
