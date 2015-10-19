#include "Image.h"


class Sprite {
	private:
		Image* image;
		int coordX;
		int coordY;
	public:
		Sprite(SDL_Renderer*, std::string, int = 0, int = 0);
		~Sprite();
		int getX();
		int getY();
		void setCoords(int, int);
		void center();
		void render(SDL_Renderer*);
};

class Animation {
	private:
		Image* images[];		// Array of Images
		int imageIndex; 		// Number of Images
		int imageCursor;		// Current anim frame indicator.
		/* 
		 * Total time the anim should take place for rendering.
		 * Either float secs or int msecs.
		 **/
		float animationTime;
	public:
		Animation(SDL_Renderer*, std::string, int, float);
		~Animation();
		SDL_Texture* getTexture();
		float getTime();
		void next();
};

class AnimatedSprite {};

class ParticleEffect: AnimatedSprite {};

class Character: AnimatedSprite {};

class PlayerCharacter: Character {};