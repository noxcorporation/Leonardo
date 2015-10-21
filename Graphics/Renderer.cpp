#include "Renderer.h"


Renderer::Renderer(SDL_Window* window, int driverIndex, Uint32 rendererFlags) {
	renderer = SDL_CreateRenderer(window, driverIndex, rendererFlags);
	test = new TahjTest(renderer);
}

Renderer::~Renderer() {
	delete test;
	SDL_DestroyRenderer(renderer);
}

void Renderer::drawScreen(int gameScreen) {
	// Clear the screen to black.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	switch (gameScreen) {
		case LEONARDO_SCREEN_1:
			test->orange();
			break;
		case LEONARDO_SCREEN_2:
			TahjTest::diamond(renderer);
			break;
		case LEONARDO_SCREEN_LEVEL:
			test->red();
			break;
	}
}


void Renderer::updateFrame() {
	SDL_RenderPresent(renderer);
	
	// Aim for 60 fps (17 ms frame time)
	// Replace later with a better implementation.
	SDL_Delay(17);
}
