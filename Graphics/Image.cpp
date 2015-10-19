#include "Image.h"

//class Image
SDL_Texture* Image::getTexture() {
    return texture;
}

int Image::getW() {
    return sizeW;
}

int Image::getH() {
    return sizeH;
}

void Image::createTexture(SDL_Renderer* renderer, SDL_Surface* surface) {
    sizeW = surface->w;
    sizeH = surface->h;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

//class FromFiles
FromFiles::FromFiles(SDL_Renderer* renderer, std::string imageFile) {
    SDL_Surface* surface;
    surface = IMG_Load(imageFile.c_str());
    createTexture(renderer, surface);    
}

FromFiles::~FromFiles() {
    SDL_DestroyTexture(texture);
}

//Class FromText
FromText::FromText(SDL_Renderer* renderer, std::string textIn, std::string fontIn, int fontSize, SDL_Color colorIn) {
    font = TTF_OpenFont(fontIn.c_str(), fontSize);
    color = colorIn;
    text = textIn;
    SDL_Surface* surface;
    surface = TTF_RenderText_Blended(font, text.c_str(), color);
    createTexture(renderer, surface);
}

FromText::~FromText() {
    TTF_CloseFont (font);
    SDL_DestroyTexture(texture);
}

std::string FromText::getText() {
    return text;
}
