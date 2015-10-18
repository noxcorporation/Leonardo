#include <string>
#include <SDL2/SDL.h>


class Image {
	private:
		SDL_Texture* texture;
		int sizeW;
		int sizeH;
	protected:
	public:
		Image(SDL_Renderer*, std::string);
		~Image();
		SDL_Texture* getTexture();
		int getW();
		int getH();
};