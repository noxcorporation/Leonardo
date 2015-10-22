#include "TahjTest.h"


/*
 * Testing code to display basic things on screen.
 **/
void TahjTest::ruby(SDL_Renderer* renderer) {
	string text = "Press DOWN ARROW to close.";
	SDL_Color color = LEONARDO_COLOR_WHITE;
	
	Sprite sprite(renderer, text, color);
	sprite.center();
	sprite.render();
}

TahjTest::TahjTest(SDL_Renderer* renderer) {
	diamondSprite1 = new Sprite(renderer, "Haha! You activated my trap card!", LEONARDO_COLOR_WHITE);
	diamondSprite2 = new Sprite(renderer, "It's actually ENTER to close.", LEONARDO_COLOR_WHITE);
	diamondSprite1->center();
	diamondSprite2->center();
	diamondSprite1->setCoords(diamondSprite1->getX(), diamondSprite1->getY() - diamondSprite1->getH() / 2);
	diamondSprite2->setCoords(diamondSprite2->getX(), diamondSprite2->getY() + diamondSprite2->getH() / 2);
	orangeSprite = new Sprite(renderer, "../Assets/Text.png");
	redSprite = new AnimatedSprite(renderer, "../Assets/Lloyd/", 6);
	redClock = new Clock(6);
}

TahjTest::~TahjTest() {
	delete redClock;
	delete redSprite;
	delete orangeSprite;
	delete diamondSprite2;
	delete diamondSprite1;
}

void TahjTest::diamond() {
	diamondSprite1->render();
	diamondSprite2->render();
}

void TahjTest::orange() {
	orangeSprite->center();
	orangeSprite->render();
}

void TahjTest::red() {
	if (redClock->update()) {
		redSprite->next();
		redSprite->center();
	}
	
	redSprite->render();
}
