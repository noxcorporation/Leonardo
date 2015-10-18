#include "Sprite.h"


/*
 * Creates a new sprite object from imageFile. Coords are optional.
 **/
Sprite::Sprite(SDL_Renderer* renderer, std::string imageFile, int X = 0, int Y = 0) {
	sprite = new Image(renderer, imageFile);
	coordX = X;
	coordY = Y;
}

Sprite::~Sprite() {
	delete sprite;
}

int Sprite::getX() {
	return coordX;
}

int Sprite::getY() {
	return coordY;
}

void Sprite::setCoords(int X, int Y) {
	coordX = X;
	coordY = Y;
}

void Sprite::render(SDL_Renderer* renderer) {
	
}