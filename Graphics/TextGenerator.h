class TextGenerator {
	private:
		String message;
		TTF_Font* font;
		SDL_Color color;
		SDL_Surface* surfaceMessage;
		SDL_Texture* message;
		int posX;
		int posY;
	public:
		TextGenerator(String font, int size, SDL_Color color, int x, int y);
		~TextGenerator();
		/*
		 * Pushes The text into the renderer buffer
		 **/
		void renderText(SDL_Renderer renderer);
		String getMessage();
		int getPosX();
		int getPoxY();
		void setPosX();
		void setPoxT()
}
