#include "Image.h"


//class Image
void Image::convertSurface(SDL_Renderer* renderer, SDL_Surface* surface) {
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    sizeW = surface->w;
    sizeH = surface->h;
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
ImageFromFile::ImageFromFile(SDL_Renderer* renderer, string imageFile, int centerX, int centerY) {
    SDL_Surface* surface;
    surface = IMG_Load(imageFile.c_str());
    convertSurface(renderer, surface);
	
	centerCoordX = centerX;
	centerCoordY = centerY;
}

int ImageFromFile::getCenterX() {
	return centerCoordX;
}

int ImageFromFile::getCenterY() {
	return centerCoordY;
}





//Class ImageFromText
ImageFromText::ImageFromText(SDL_Renderer* renderer, string textIn, SDL_Color colorIn, int fontSize, string fontIn) {
    font = TTF_OpenFont(fontIn.c_str(), fontSize);
    color = colorIn;
    text = textIn;
	
    SDL_Surface* surface;
    surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    convertSurface(renderer, surface);
}

ImageFromText::~ImageFromText() {
    TTF_CloseFont(font);
}

string ImageFromText::getText() {
    return text;
}





ChainedImage* ChainedImage::getNext() {
	return nextImage;
}

// WARNING! Not secure. TODO: throw exception when trying to override previously set reference.
void ChainedImage::setNext(ChainedImage* next) {
	nextImage = next;
}





MetaDataFile::MetaDataFile() {
	file = new ifstream;
}

MetaDataFile::MetaDataFile(string fileName) {
	file = new ifstream(fileName);
}

MetaDataFile::~MetaDataFile() {
	delete file;
}

void MetaDataFile::openFile(string fileName) {
	if (file->is_open())
		file->close();
	file->open(fileName);
}

string MetaDataFile::getValue() {
	string line;
	std::getline(*file, line);
//	unsigned int length = line.length();
	
	string delimiter = ": ";
	
//	line.erase(0, line.find(delimiter));
//	if (line.length() != length)
//		line.erase(0, delimiter.length());
	if (line.find(delimiter) != std::string::npos)
		return line.substr(line.find(delimiter) + delimiter.length());
	
	return line;
}
