#include "TahjTest.h"


/*
 * Testing code to display basic things on screen.
 **/
//void TahjRenderTest::ruby(SDL_Renderer* renderer) {
//	string text = "Press DOWN ARROW to close.";
//	SDL_Color color = LEONARDO_COLOR_WHITE;
//	
//	Sprite sprite(renderer, text, color);
//	sprite.center();
//	sprite.render();
//}

TahjTest::TahjTest(SDL_Renderer* renderer) {
	diamondSprite1 = new Sprite(renderer, "Haha! You activated my trap card!", LEONARDO_COLOR_WHITE);
	diamondSprite2 = new Sprite(renderer, "It's actually ENTER to close.", LEONARDO_COLOR_WHITE);
	diamondSprite1->center();
	diamondSprite2->center();
	diamondSprite1->setCoords(diamondSprite1->getX(), diamondSprite1->getY() - diamondSprite1->getH() / 2);
	diamondSprite2->setCoords(diamondSprite2->getX(), diamondSprite2->getY() + diamondSprite2->getH() / 2);
	orangeSprite = new Sprite(renderer, "../Assets/Text.png");
	redSprite = new AnimatedSprite(renderer, "../Assets/Lloyd/", 6);
	redSprite->center();
	redClock = new Clock(6);
}

TahjTest::~TahjTest() {
	delete redClock;
	delete redSprite;
	delete orangeSprite;
	delete diamondSprite2;
	delete diamondSprite1;
}

void TahjTest::diamondRender() {
	diamondSprite1->render();
	diamondSprite2->render();
}

void TahjTest::orangeRender() {
	orangeSprite->center();
	orangeSprite->render();
}

void TahjTest::redRender() {
	if (redClock->update()) {
		redSprite->next();
		redSprite->center();
	}
	
	redSprite->render();
}



void TahjTest::diamondInput(SDL_Event event, GameScreen* gameScreen) {
	if (event.key.keysym.sym == SDLK_BACKSPACE)	// Backspace to exit.
		*gameScreen = LEONARDO_SCREEN_EXIT;
	if (event.key.keysym.sym == SDLK_ESCAPE)	// Escape to exit.
		*gameScreen = LEONARDO_SCREEN_EXIT;
	if (event.key.keysym.sym == SDLK_DOWN)		// Down arrow to progress.
		*gameScreen = LEONARDO_SCREEN_2;
}

void TahjTest::orangeInput(SDL_Event event, GameScreen* gameScreen) {
	if (event.key.keysym.sym == SDLK_BACKSPACE)	// Backspace to go back.
		*gameScreen = LEONARDO_SCREEN_1;
	if (event.key.keysym.sym == SDLK_RETURN)	// Enter to quit.
		*gameScreen = LEONARDO_SCREEN_EXIT;
	if (event.key.keysym.sym == SDLK_a)			// A to progress.
		*gameScreen = LEONARDO_SCREEN_3;
}

void TahjTest::redInput(SDL_Event event, GameScreen* gameScreen) {
	if (event.key.keysym.sym == SDLK_ESCAPE)	// Escape to quit.
		*gameScreen = LEONARDO_SCREEN_EXIT;
	if (event.key.keysym.sym == SDLK_LEFT)
		redSprite->setDirection(LEFT);
	if (event.key.keysym.sym == SDLK_RIGHT)
		redSprite->setDirection(RIGHT);
}
