#include "Image.h"


//class Image
void Image::convertSurface(SDL_Renderer* renderer, SDL_Surface* surface) {
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





//class ImageFromFile
ImageFromFile::ImageFromFile(SDL_Renderer* renderer, std::string imageFile) {
    SDL_Surface* surface;
    surface = IMG_Load(imageFile.c_str());
    convertSurface(renderer, surface);
}

ImageFromFile::~ImageFromFile() {
    SDL_DestroyTexture(texture);
}





//Class ImageFromText
ImageFromText::ImageFromText(SDL_Renderer* renderer, std::string textIn, SDL_Color colorIn, int fontSize, std::string fontIn) {
    font = TTF_OpenFont(fontIn.c_str(), fontSize);
    color = colorIn;
    text = textIn;
    SDL_Surface* surface;
    surface = TTF_RenderText_Blended(font, text.c_str(), color);
    convertSurface(renderer, surface);
}

ImageFromText::~ImageFromText() {
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture);
}

std::string ImageFromText::getText() {
    return text;
}
