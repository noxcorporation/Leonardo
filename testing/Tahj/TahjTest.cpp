#include "Graphics/Sprite.h"
#include "TahjTest.h"


/*
 * Testing code to display basic things on screen.
 **/
void TahjTest::drawScreen(SDL_Renderer* renderer) {
	ruby(renderer);
}

void TahjTest::orange(SDL_Renderer* renderer) {
	//Loading test image.
	Sprite sprite(renderer, std::string("../Assets/Text.png"));
	sprite.center();
	sprite.render(renderer);
}

void TahjTest::ruby(SDL_Renderer* renderer) {
	std::string text = "Press DOWN ARROW to close.";
	SDL_Color color = LEONARDO_COLOR_WHITE;
	
	Sprite sprite(renderer, text, color);
	sprite.center();
	sprite.render(renderer);
}
