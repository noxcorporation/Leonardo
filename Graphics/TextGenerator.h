class TextGenerator {
	private:
		int posX;
		int posY;
		String message;
		TTF_Font* font;
		SDL_Color color;
		
		SDL_Surface* surfaceMessage;
		SDL_Texture* message;
	protected:
		/*
		 * Pushes The text into the renderer buffer
		 **/
		void renderText(SDL_Renderer renderer);
	public:
		TextGenerator(String font, int fontSize, SDL_Color color, int x, int y);
		~TextGenerator();
		String getMessage();
		int getPosX();
		int getPoxY();
		void setPosX();
		void setPoxT()
}