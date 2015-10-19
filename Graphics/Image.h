#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>

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
        
        void createTexture(SDL_Renderer* renderer, SDL_Surface* surface);
    public:
        SDL_Texture* getTexture();
        
        int getW();
        int getH();
};

/*
 * SDL_Texture object from a file
 **/
class FromFiles : public Image {
    public:
        /*
         * renderer is a pointer to the current renderer object,
         * imageFile is the path to the source File.
         **/
        FromFiles(SDL_Renderer* renderer, std::string imageFile);
        ~FromFiles();
};

/*
 * SDL_Texture object from a string.
 **/
class FromText : public Image {
    private:
        std::string text;
        TTF_Font* font;
        SDL_Color color;
    public:
        /*
         * renderer must the pointer to the current renderer object
         * textIn is the string to display, fontIn must be the path to the font.ttf file, colorIn is an SDL_Color struct
         **/
        FromText(SDL_Renderer* renderer, std::string textIn, std::string fontIn, int fontSize, SDL_Color colorIn);
        ~FromText();
        std::string getText();
};
