#include "Image.h"


class Sprite {
	private:
		Image* image;
		int coordX;
		int coordY;
	public:
		/*
		 * Converts specified image file into a sprite.
		 **/
		Sprite(SDL_Renderer*, std::string);
		/*
		 * Creates a sprite from input text and color.
		 **/
		Sprite(SDL_Renderer*, std::string, SDL_Color);
		/*
		 * Creates a sprite from input text, color and font size.
		 **/
		Sprite(SDL_Renderer*, std::string, SDL_Color, int);
		~Sprite();
		int getX();
		int getY();
		int getW();
		int getH();
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