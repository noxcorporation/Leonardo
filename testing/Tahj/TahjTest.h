#ifndef TAHJTEST_H
#define TAHJTEST_H

#include "../../Leonardo.h"
#include "../../Graphics/Sprite.h"
#include "../../Input/Time.h"


class TahjTest {
	private:
		StaticSprite* diamondSprite1;
		StaticSprite* diamondSprite2;
		StaticSprite* orangeSprite;
		AnimatedSprite* redSprite;
		Clock* redClock;
	public:
		TahjTest(SDL_Renderer*);
		~TahjTest();
//		static void ruby(SDL_Renderer*);
		void diamondRender();
		void orangeRender();
		void redRender();
		
		void diamondInput(SDL_Event, GameScreen*);
		void orangeInput(SDL_Event, GameScreen*);
		void redInput(SDL_Event, GameScreen*);
};

#endif
