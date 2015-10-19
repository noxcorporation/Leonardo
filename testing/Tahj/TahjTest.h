#ifndef TAHJTEST_H
#define TAHJTEST_H


class TahjTest {
	private:
		int programStep;
	protected:
		void orange(SDL_Renderer*);
		void ruby(SDL_Renderer*);
		void diamond(SDL_Renderer*);
	public:
		TahjTest();
		int getStep();
		void drawScreen1(SDL_Renderer*);
		void drawScreen2(SDL_Renderer*);
};

#endif