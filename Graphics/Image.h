#include "Window.h"


/*
 * Abstract class, Text and ImageFiles will extends from it. 
 **/
class Image {
    protected:
        /*
         * End product is the SDL_Texture object.
         **/
        SDL_Texture* texture;

        int sizeW;
        int sizeH;
        
        void convertSurface(SDL_Renderer* renderer, SDL_Surface* surface);
	public:
		/*
		 * Make this class astract.
		 * Any derived class must use it's own destructor and method to produce a texture.
		 **/
		virtual ~Image() = 0;
		
        SDL_Texture* getTexture();
        
        int getW();
        int getH();
};

/*
 * SDL_Texture object from a file
 **/
class ImageFromFile : public Image {
    public:
        /*
         * renderer is a pointer to the current renderer object,
         * imageFile is the path to the source File.
         **/
        ImageFromFile(SDL_Renderer* renderer, std::string imageFile);
        ~ImageFromFile();
};

/*
 * SDL_Texture object from a string.
 **/
class ImageFromText : public Image {
    private:
        std::string text;
        TTF_Font* font;
        SDL_Color color;
    public:
        /*
         * renderer must the pointer to the current renderer object
         * textIn is the string to display, fontIn must be the path to the font.ttf file, colorIn is an SDL_Color struct
		 * TODO: Add default values.
         **/
        ImageFromText(SDL_Renderer* renderer, std::string textIn = "Sample Text", SDL_Color colorIn = LEONARDO_COLOR_BLACK, int fontSize = 14, std::string fontIn = LEONARDO_FONT_QUARMIC);
        ~ImageFromText();
        std::string getText();
};
