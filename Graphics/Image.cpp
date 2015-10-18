#include <SDL2/SDL_image.h>
#include "Image.h"


/*
 * This constructor loads an image from a file to a texture.
 **/
Image::Image(SDL_Renderer* renderer, std::string imageFile) {
	SDL_Surface* surface;
	surface = IMG_Load(imageFile.c_str());
	sizeW = surface->w;
	sizeH = surface->h;
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

Image::~Image() {
	SDL_DestroyTexture(texture);
}

SDL_Texture* Image::getTexture() {
	return texture;
}

int Image::getW() {
	return sizeW;
}

int Image::getH() {
	return sizeH;
}