#include "TahjTest.h"
#include "Graphics/Sprite.h"


/*
 * Testing code to display basic things on screen.
 **/
void TahjTest::orange(SDL_Renderer* renderer) {
	//Loading test image.
	Sprite sprite(renderer, "../Assets/Text.png");
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

void TahjTest::diamond(SDL_Renderer* renderer) {
	std::string text1 = "Haha! You activated my trap card!";
	std::string text2 = "It's actually ENTER to close.";
	SDL_Color color = LEONARDO_COLOR_WHITE;
	
	Sprite sprite1(renderer, text1, color);
	sprite1.center();
	Sprite sprite2(renderer, text2, color);
	sprite2.center();
	
	sprite1.setCoords(sprite1.getX(), sprite1.getY() - sprite1.getH() / 2);
	sprite2.setCoords(sprite2.getX(), sprite2.getY() + sprite2.getH() / 2);
	
	sprite1.render(renderer);
	sprite2.render(renderer);
}
