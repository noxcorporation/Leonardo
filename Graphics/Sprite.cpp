#include "Render.h"
#include "Sprite.h"


/*
 * Creates a new sprite object from imageFile. Coords are optional.
 **/
Sprite::Sprite(SDL_Renderer* renderer, std::string imageFile, int X, int Y) {
	image = new ImageFromFile(renderer, imageFile);
	coordX = X;
	coordY = Y;
}

Sprite::~Sprite() {
	delete image;
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
	coordX = (LEONARDO_WINDOW_WIDTH - image->getW()) / 2;
	coordY = (LEONARDO_WINDOW_HEIGHT - image->getH()) / 2;
}

void Sprite::render(SDL_Renderer* renderer) {
	SDL_Rect DestinRektion = {coordX, coordY, image->getW(), image->getH()};
	SDL_RenderCopy(renderer, image->getTexture(), NULL, &DestinRektion);		//Renderer got SDL_Rect.
}





Animation::Animation(SDL_Renderer* renderer, std::string animationFolder, int fileNumber, float animTime) {
	for (int i=1; i <= fileNumber; i++) {
		images[i] = new ImageFromFile(renderer, animationFolder + std::to_string(i) + ".png");
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