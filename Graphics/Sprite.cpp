#include "Sprite.h"

Sprite::~Sprite(){}
int Sprite::getX(){}
int Sprite::getY(){}
int Sprite::getW(){}
int Sprite::getH(){}
void Sprite::setCoords(int x, int y) {}
void Sprite::center() {}
void Sprite::render() {}

/*
 * Creates a new sprite object from imageFile. Coords are optional.
 **/
StaticSprite::StaticSprite(SDL_Renderer* rendererIn, string imageFile) {
	renderer = rendererIn;
	image = new ImageFromFile(renderer, imageFile);
	coordX = 0;
	coordY = 0;
}
StaticSprite::StaticSprite(SDL_Renderer* rendererIn, string text, SDL_Color color) {
	renderer = rendererIn;
	image = new ImageFromText(renderer, text, color);
	coordX = 0;
	coordY = 0;
}

StaticSprite::~StaticSprite() {
	delete image;
}

int StaticSprite::getX() {
	return coordX;
}

int StaticSprite::getY() {
	return coordY;
}

int StaticSprite::getW() {
	return image->getW();
}

int StaticSprite::getH() {
	return image->getH();
}

void StaticSprite::setCoords(int X, int Y) {
	coordX = X;
	coordY = Y;
}

void StaticSprite::center() {
	coordX = (LEONARDO_WINDOW_WIDTH - image->getW()) / 2;
	coordY = (LEONARDO_WINDOW_HEIGHT - image->getH()) / 2;
}

void StaticSprite::render() {
	SDL_Rect DestinRektion = {coordX, coordY, image->getW(), image->getH()};
	SDL_RenderCopy(renderer, image->getTexture(), NULL, &DestinRektion);
	//Renderer got SDL_Rect.
}





/*// Initializes Animation from specified parameters as an array.
Animation::Animation(SDL_Renderer* renderer, string animationFolder, int fileNumber, float animTime) {
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
Animation::Animation(SDL_Renderer* renderer, string animationFolder, int fileNumber) {
	MetaDataFile metaFile(animationFolder + "0.txt");
	animationTime = std::stof(metaFile.getValue());
	
	metaFile.openFile(animationFolder + "1.txt");
	int centerX = std::stoi(metaFile.getValue());
	int centerY = std::stoi(metaFile.getValue());
	
	currentImage = new ChainedImage(renderer, animationFolder + "1.png", centerX, centerY);
	
	// Used for chain initialization.
	ChainedImage* current = currentImage;
	ChainedImage* next;
	
	for (int i=1; i <= fileNumber; i++) {
		if (i < fileNumber) {
			metaFile.openFile(animationFolder + std::to_string(i+1) + ".txt");
			centerX = std::stoi(metaFile.getValue());
			centerY = std::stoi(metaFile.getValue());
			
			next = new ChainedImage(renderer, animationFolder + std::to_string(i+1) + ".png", centerX, centerY);
			current->setNext(next);
			current = next;
		} else if (i == fileNumber)
			current->setNext(currentImage);
	}
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

int Animation::getNextW() {
	return currentImage->getNext()->getW();
}

int Animation::getH() {
	return currentImage->getH();
}

int Animation::getCenterX() {
	return currentImage->getCenterX();
}

int Animation::getNextCenterX() {
	return currentImage->getNext()->getCenterX();
}

int Animation::getCenterY() {
	return currentImage->getCenterY();
}

int Animation::getNextCenterY() {
	return currentImage->getNext()->getCenterY();
}

float Animation::getTime() {
	return animationTime;
}

void Animation::next() {
	currentImage = currentImage->getNext();
}





AnimatedSprite::AnimatedSprite(SDL_Renderer* rendererIn, string animationFolder, int fileNumber) {
	renderer = rendererIn;
	idleAnimation = new Animation(renderer, animationFolder, fileNumber);
	baseDirection = LEFT;
	renderDirection = LEFT;
	coordX = 0;
	coordY = 0;
}

AnimatedSprite::~AnimatedSprite() {
	delete idleAnimation;
}

float AnimatedSprite::getTime() {
	return idleAnimation->getTime();
}

int AnimatedSprite::getX() {
	return coordX;
}

int AnimatedSprite::getY() {
	return coordY;
}

int AnimatedSprite::getW() {
	return idleAnimation->getW();
}

int AnimatedSprite::getH() {
	return idleAnimation->getH();
}

void AnimatedSprite::setCoords(int X, int Y) {
	coordX = X;
	coordY = Y;
}

void AnimatedSprite::center() {
	coordX = (LEONARDO_WINDOW_WIDTH - idleAnimation->getW()) / 2;
	coordY = (LEONARDO_WINDOW_HEIGHT - idleAnimation->getH()) / 2;
}

void AnimatedSprite::setDirection(SpriteDirection direction) {
	if (direction != renderDirection) {
		int offsetX;
		
		switch (renderDirection) {
			case LEFT:
				offsetX = idleAnimation->getCenterX() - (idleAnimation->getW() - idleAnimation->getCenterX());
				coordX += offsetX;
				break;
			case RIGHT:
				offsetX = (idleAnimation->getW() - idleAnimation->getCenterX()) - idleAnimation->getCenterX();
				coordX += offsetX;
				break;
		}
		
		renderDirection = direction;
	}
}

void AnimatedSprite::next() {
	int offsetX;
	int offsetY;
	
	switch (renderDirection) {
		case LEFT:
			offsetX = idleAnimation->getCenterX() - idleAnimation->getNextCenterX();
			offsetY = idleAnimation->getCenterY() - idleAnimation->getNextCenterY();
			coordX += offsetX;
			coordY += offsetY;
			break;
		case RIGHT:
			offsetX = (idleAnimation->getW() - idleAnimation->getCenterX()) - (idleAnimation->getNextW() -  idleAnimation->getNextCenterX());
			offsetY = idleAnimation->getCenterY() - idleAnimation->getNextCenterY();
			coordX += offsetX;
			coordY += offsetY;
			break;
	}
	
	idleAnimation->next();
}

void AnimatedSprite::render() {
	SDL_Rect DestinRektion = {coordX, coordY, idleAnimation->getW(), idleAnimation->getH()};
	
	if (renderDirection != baseDirection)
		SDL_RenderCopyEx(renderer, idleAnimation->getTexture(), NULL, &DestinRektion, 0, NULL, SDL_FLIP_HORIZONTAL);
	else
		SDL_RenderCopy(renderer, idleAnimation->getTexture(), NULL, &DestinRektion);
	//Renderer got SDL_Rect.
}
