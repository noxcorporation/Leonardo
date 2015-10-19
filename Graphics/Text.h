#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text {
	private:
		int width;
                int height;
            
                char* textMessage;
		TTF_Font* font;
		SDL_Color color;
		
		SDL_Texture* message;
	protected:
	public:
		Text(char* messageIn, char* fontIn, int fontSize, SDL_Color colorIn, int x, int y, SDL_Renderer* renderer);
                ~Text();
		char* getMessage();
                
                int getW();
                int getH();
};
