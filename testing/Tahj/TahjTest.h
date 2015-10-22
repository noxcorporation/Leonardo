#ifndef TAHJTEST_H
#define TAHJTEST_H

#include "Leonardo.h"
#include "Graphics/Sprite.h"
#include "Input/Time.h"


class TahjTest {
	private:
		Sprite* orangeSprite;
		AnimatedSprite* redSprite;
		Clock* redClock;
	public:
		TahjTest(SDL_Renderer*);
		~TahjTest();
		static void ruby(SDL_Renderer*);
		static void diamond(SDL_Renderer*);
		void orange();
		void red();
};

#endif