#include <SDL2/SDL_ttf.h>
#include <iostream>

class Text {
	private:
		int posX;
		int posY;
		std::string textMessage;
		TTF_Font* font;
		SDL_Color color;
		
		SDL_Rect messageRekt;
		SDL_Texture* message;
		SDL_Renderer* renderer;
	protected:
		/*
		 * Pushes The text into the renderer buffer
		 **/
		void renderText();
		SDL_Rect createRektTexture(SDL_Renderer* renderer);
	public:
		Text(std::string messageIn, char* fontIn, int fontSize, SDL_Color colorIn, int x, int y, SDL_Renderer* renderer);
                ~Text();
		std::string getMessage();
		int getPosX();
		int getPoxY();
		void setPosXY(int x, int y);
};
