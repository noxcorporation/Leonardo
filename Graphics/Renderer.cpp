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
	
	test = new TahjRenderTest(renderer);
}

Renderer::~Renderer() {
	delete test;
	
	SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Renderer::getRenderer() {
	return renderer;
}

void Renderer::drawScreen(GameScreen gameScreen) {
	// Clear the screen to black.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	switch (gameScreen) {
		case LEONARDO_SCREEN_1:
			test->red();
			break;
		
		default:
			break;
	}
}

void Renderer::updateFrame() {
	SDL_RenderPresent(renderer);
}
