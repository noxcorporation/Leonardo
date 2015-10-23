#ifndef TAHJTEST_H
#define TAHJTEST_H

#include "../../Leonardo.h"
#include "../../Graphics/Sprite.h"
#include "../../Input/Time.h"


class TahjRenderTest {
	private:
		Sprite* diamondSprite1;
		Sprite* diamondSprite2;
		Sprite* orangeSprite;
		AnimatedSprite* redSprite;
		Clock* redClock;
	public:
		TahjRenderTest(SDL_Renderer*);
		~TahjRenderTest();
//		static void ruby(SDL_Renderer*);
		void diamond();
		void orange();
		void red();
};

class TahjInputTest {
	public:
		static void diamond(SDL_Event, GameScreen*);
		static void orange(SDL_Event, GameScreen*);
		static void red(SDL_Event, GameScreen*);
};

#endif
