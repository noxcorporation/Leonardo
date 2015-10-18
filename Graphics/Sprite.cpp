#include "Sprite.h"


Sprite::Sprite(SDL_Renderer* renderer, std::string imageFile, int X, int Y) {
	sprite = new Image(renderer, imageFile);
	coordX = X;
	coordY = Y;
}

Sprite::~Sprite() {
	delete sprite;
}