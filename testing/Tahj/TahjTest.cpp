#include "Graphics/Sprite.h"
#include "TahjTest.h"


/*
 * Testing code to display basic things on screen.
 **/
void TahjTest::drawScreen(SDL_Renderer* renderer) {
	//Loading test image.
	Sprite sprite(renderer, std::string("../Assets/Text.png"));
	sprite.center();
	sprite.render(renderer);
}