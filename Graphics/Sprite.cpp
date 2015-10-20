#include "Sprite.h"


/*
 * Creates a new sprite object from imageFile. Coords are optional.
 **/
Sprite::Sprite(SDL_Renderer* rendererIn, std::string imageFile) {
	renderer = rendererIn;
	image = new ImageFromFile(renderer, imageFile);
	coordX = 0;
	coordY = 0;
}

Sprite::Sprite(SDL_Renderer* rendererIn, std::string text, SDL_Color color) {
	renderer = rendererIn;
	image = new ImageFromText(renderer, text, color);
	coordX = 0;
	coordY = 0;
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

int Sprite::getW() {
	return image->getW();
}

int Sprite::getH() {
	return image->getH();
}

void Sprite::setCoords(int X, int Y) {
	coordX = X;
	coordY = Y;
}

void Sprite::center() {
	coordX = (LEONARDO_WINDOW_WIDTH - image->getW()) / 2;
	coordY = (LEONARDO_WINDOW_HEIGHT - image->getH()) / 2;
}

void Sprite::render() {
	SDL_Rect DestinRektion = {coordX, coordY, image->getW(), image->getH()};
	SDL_RenderCopy(renderer, image->getTexture(), NULL, &DestinRektion);
	//Renderer got SDL_Rect.
}





/*// Initializes Animation from specified parameters as an array.
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
}*/

// Initializes Animation from specified parameters as a chain.
// fileNumber: Total number of animation frame files to load.
Animation::Animation(SDL_Renderer* renderer, std::string animationFolder, int fileNumber, float animTime) {
	currentImage = new ChainedImage(renderer, animationFolder + "1.png");
	
	// Used for chain initialization.
	ChainedImage* current = currentImage;
	ChainedImage* next;
	
	for (int i=1; i <= fileNumber; i++) {
		if (i < fileNumber) {
			next = new ChainedImage(renderer, animationFolder + std::to_string(i+1) + ".png");
			current->setNext(next);
			current = next;
		} else if (i == fileNumber)
			current->setNext(currentImage);
	}
	
	animationTime = animTime;
}

Animation::~Animation() {
	ChainedImage* current = currentImage;
	ChainedImage* next = currentImage->getNext();
	
	do {
		current = next;
		next = current->getNext();
		delete current;
	} while (current != currentImage);
}

SDL_Texture* Animation::getTexture() {
	return currentImage->getTexture();
}

int Animation::getW() {
	return currentImage->getW();
}

int Animation::getH() {
	return currentImage->getH();
}

float Animation::getTime() {
	return animationTime;
}

void Animation::next() {
	currentImage = currentImage->getNext();
}





AnimatedSprite::AnimatedSprite(SDL_Renderer* rendererIn, std::string animationFolder, int fileNumber) {
	renderer = rendererIn;
	animation = new Animation(renderer, animationFolder, fileNumber);
	coordX = 0;
	coordY = 0;
}

AnimatedSprite::~AnimatedSprite() {
	delete animation;
}

int AnimatedSprite::getX() {
	return coordX;
}

int AnimatedSprite::getY() {
	return coordY;
}

int AnimatedSprite::getW() {
	return animation->getW();
}

int AnimatedSprite::getH() {
	return animation->getH();
}

void AnimatedSprite::setCoords(int X, int Y) {
	coordX = X;
	coordY = Y;
}

void AnimatedSprite::center() {
	coordX = (LEONARDO_WINDOW_WIDTH - animation->getW()) / 2;
	coordY = (LEONARDO_WINDOW_HEIGHT - animation->getH()) / 2;
}

void AnimatedSprite::next() {
	animation->next();
}

void AnimatedSprite::render() {
	SDL_Rect DestinRektion = {coordX, coordY, animation->getW(), animation->getH()};
	SDL_RenderCopy(renderer, animation->getTexture(), NULL, &DestinRektion);
	//Renderer got SDL_Rect.
}
