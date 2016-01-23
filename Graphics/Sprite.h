#include "../Leonardo.h"
#include "../Input/Time.h"
#include "Image.h"

class Sprite {
    protected:
        int coordX;
        int coordY;    
    public:
        virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getW() = 0;
	virtual int getH() = 0;
	virtual void setCoords(int, int) = 0;
	virtual void center() = 0;
	virtual void render() = 0;
        virtual ~Sprite() = 0;
};

class StaticSprite: private Sprite {
    private:
        SDL_Renderer* renderer;
        Image* image;
    public:
        /*
         * Converts specified image file into a sprite.
         **/
        StaticSprite(SDL_Renderer*, string);
        /*
         * Creates a sprite from input text and color.
         **/
        StaticSprite(SDL_Renderer*, string, SDL_Color);
        /*
         * Creates a sprite from input text, color and font size.
         **/
        StaticSprite(SDL_Renderer*, string, SDL_Color, int);
        ~StaticSprite();
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
		Animation(SDL_Renderer*, string, int);
		~Animation();
		SDL_Texture* getTexture();
		int getW();
		int getNextW();
		int getH();
		int getCenterX();
		int getNextCenterX();
		int getCenterY();
		int getNextCenterY();
		float getTime();
		void next();
};

class AnimatedSprite: private Sprite{
	private:
		Animation* currentAnimation;
		Animation* idleAnimation;
		Animation* moveAnimation;
		SDL_Renderer* renderer;
		Clock* animClock;
		SpriteDirection baseDirection;
		SpriteDirection renderDirection;
	public:
                AnimatedSprite(SDL_Renderer*, string, int);
		~AnimatedSprite();
		float getTime();
		void setDirection(SpriteDirection);
                void setAnimation(AnimationType type);
		void next();
                int getX();
                int getY();
                int getW();
                int getH();
                void setCoords(int, int);
                void center();
                void render();

};

class ParticleEffect: public AnimatedSprite {};

class Character: public AnimatedSprite {};

class PlayerCharacter: public Character {};
