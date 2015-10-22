#include "Renderer.h"


Renderer::Renderer(SDL_Window* window, Rendering renderSettings) {
	switch (renderSettings) {
		case DEFAULT:
			renderer = SDL_CreateRenderer(window, -1, 0);
			break;
		case VSYNC:
			// Using vsync-ed accelerated settings.
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC or SDL_RENDERER_ACCELERATED);
			break;
	}
	
	test = new TahjTest(renderer);
}

Renderer::~Renderer() {
	delete test;
	
	SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Renderer::getRenderer() {
	return renderer;
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
			test->diamond();
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
