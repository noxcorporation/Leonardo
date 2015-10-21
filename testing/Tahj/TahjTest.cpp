#include "TahjTest.h"


/*
 * Testing code to display basic things on screen.
 **/
void TahjTest::orange() {
	orangeSprite->center();
	orangeSprite->render();
}

void TahjTest::ruby(SDL_Renderer* renderer) {
	string text = "Press DOWN ARROW to close.";
	SDL_Color color = LEONARDO_COLOR_WHITE;
	
	Sprite sprite(renderer, text, color);
	sprite.center();
	sprite.render();
}

void TahjTest::diamond(SDL_Renderer* renderer) {
	string text1 = "Haha! You activated my trap card!";
	string text2 = "It's actually ENTER to close.";
	SDL_Color color = LEONARDO_COLOR_WHITE;
	
	Sprite sprite1(renderer, text1, color);
	sprite1.center();
	Sprite sprite2(renderer, text2, color);
	sprite2.center();
	
	sprite1.setCoords(sprite1.getX(), sprite1.getY() - sprite1.getH() / 2);
	sprite2.setCoords(sprite2.getX(), sprite2.getY() + sprite2.getH() / 2);
	
	sprite1.render();
	sprite2.render();
}

TahjTest::TahjTest(SDL_Renderer* renderer) {
	redSprite = new AnimatedSprite(renderer, "../Assets/Lloyd/", 6);
	orangeSprite = new Sprite(renderer, "../Assets/Text.png");
}

TahjTest::~TahjTest() {
	delete orangeSprite;
	delete redSprite;
}

void TahjTest::red() {
	// This implementation can only read anim fps at compile-time for now.
	using animFrameDuration = std::chrono::duration<float, std::ratio<1,6>>; //6fps
	
	auto now = std::chrono::steady_clock::now();
	std::chrono::duration<float> diff = now - redLastRender;
	
	if (std::chrono::duration_cast<animFrameDuration>(diff).count() >= 1) {
		redSprite->next();
		redSprite->center();
		redLastRender = now;
	}
	
	redSprite->render();
}
