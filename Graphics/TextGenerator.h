class TextGenerator {
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
		SDL_Rect createRektTexture();
	public:
		TextGenerator(std::string message, std::string font, int fontSize, SDL_Color color, int x, int y, SDL_Renderer* renderer);
		~TextGenerator();
		std::string getMessage();
		int getPosX();
		int getPoxY();
		void setPosXY(int x, int y);
};
