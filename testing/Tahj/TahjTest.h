#ifndef TAHJTEST_H
#define TAHJTEST_H

#include <chrono>

#include "Leonardo.h"
#include "Graphics/Sprite.h"


class TahjTest {
	private:
		Sprite* orangeSprite;
		AnimatedSprite* redSprite;
		std::chrono::time_point<std::chrono::steady_clock> redLastRender;
	public:
		TahjTest(SDL_Renderer*);
		~TahjTest();
		void orange();
		static void ruby(SDL_Renderer*);
		static void diamond(SDL_Renderer*);
		void red();
};

#endif