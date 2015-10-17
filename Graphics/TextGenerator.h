class TextGenerator {
	private:
		int posX;
		int posY;
		String textMessage;
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
		TextGenerator(String message, String font, int fontSize, SDL_Color color, int x, int y, SDL_Renderer* renderer);
		~TextGenerator();
		String getMessage();
		int getPosX();
		int getPoxY();
		void setPosX();
		void setPoxT()
}
