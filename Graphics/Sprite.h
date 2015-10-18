#include "Image.h"


class Sprite {
	private:
		Image* sprite;
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

class SpriteAnimationSet {
		/* 
		 * Total time the anim should take place for rendering.
		 * Either float secs or int msecs.
		 **/
		float animationTime;
};

class AnimatedSprite {};

class ParticleEffect: AnimatedSprite {};

class Character: AnimatedSprite {};

class PlayerCharacter: Character {};