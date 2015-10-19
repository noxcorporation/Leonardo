#include "../Leonardo.h"
#include "Image.h"


class Sprite {
	private:
		Image* image;
		SDL_Renderer* renderer;
		int coordX;
		int coordY;
	public:
		/*
		 * Converts specified image file into a sprite.
		 **/
		Sprite(SDL_Renderer*, string);
		/*
		 * Creates a sprite from input text and color.
		 **/
		Sprite(SDL_Renderer*, string, SDL_Color);
		/*
		 * Creates a sprite from input text, color and font size.
		 **/
		Sprite(SDL_Renderer*, string, SDL_Color, int);
		~Sprite();
		int getX();
		int getY();
		int getW();
		int getH();
		void setCoords(int, int);
		void center();
		void render();
};

class Animation {
	private:
		ChainedImage* currentImage;
		/* 
		 * Total time the anim should take place for rendering.
		 * Either float secs or int msecs.
		 **/
		float animationTime;
	public:
		Animation(SDL_Renderer*, string, int, float = 1);
		~Animation();
		SDL_Texture* getTexture();
		int getW();
		int getH();
		float getTime();
		void next();
};

class AnimatedSprite {
	private:
		Animation* animation;
		SDL_Renderer* renderer;
		int coordX;
		int coordY;
	public:
		AnimatedSprite(SDL_Renderer*, string, int);
		~AnimatedSprite();
		int getX();
		int getY();
		int getW();
		int getH();
		void setCoords(int, int);
		void center();
		void next();
		void render();
};

class ParticleEffect: public AnimatedSprite {};

class Character: public AnimatedSprite {};

class PlayerCharacter: public Character {};
