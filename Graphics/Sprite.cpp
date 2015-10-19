#include "Render.h"
#include "Sprite.h"


/*
 * Creates a new sprite object from imageFile. Coords are optional.
 **/
Sprite::Sprite(SDL_Renderer* renderer, std::string imageFile, int X, int Y) {
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

void Sprite::center() {
	coordX = (LEONARDO_WINDOW_WIDTH - sprite->getW()) / 2;
	coordY = (LEONARDO_WINDOW_HEIGHT - sprite->getH()) / 2;
}

void Sprite::render(SDL_Renderer* renderer) {
	SDL_Rect DestinRektion = {coordX, coordY, sprite->getW(), sprite->getH()};
	SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &DestinRektion);		//Renderer got SDL_Rect.
}





Animation::Animation(SDL_Renderer* renderer, std::string animationFolder, int fileNumber, float animTime) {
	for (int i=1; i <= fileNumber; i++) {
		images[i] = new Image(renderer, animationFolder + std::to_string(i) + ".png");
	}
	imageIndex = fileNumber;
	imageCursor = 1;
	animationTime = animTime;
}

Animation::~Animation() {
	for (int i=1; i <= imageIndex; i++) {
		delete images[i];
	}
}

SDL_Texture* Animation::getTexture() {
	return images[imageCursor]->getTexture();
}

float Animation::getTime() {
	return animationTime;
}

void Animation::next() {
	imageCursor++;
}