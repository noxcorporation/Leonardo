#include "Window.h"
#include "../Input/Input.h"


/*
 * This constructor initializes SDL and opens a window.
 **/
Window::Window() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	
	window = SDL_CreateWindow(
		"Leonardo",
		/*
		 * Default window position should be center screen.
		 **/
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		LEONARDO_WINDOW_WIDTH,
		LEONARDO_WINDOW_HEIGHT,
		SDL_WINDOW_OPENGL
	);
	
	renderer = new Renderer(window);		//Add VSYNC if needed. Eventually move this to a settings file.
	test = new TahjTest(renderer->getRenderer());
	renderer->setTest(test);
	
	cycleClock = new Clock(LEONARDO_FRAMECAP);
	gameScreen = LEONARDO_SCREEN_NONE;
}

/*
 * This destructor closes the window and SDL to free memory.
 **/
Window::~Window() {
	delete test;
	
	delete cycleClock;
	delete renderer;
	SDL_DestroyWindow(window);
	
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

/*
 * No arguments. Returns program exit code.
 * Main program method.
 * This function cycles to update the frame and listen to user input.
 * One cycle is one frame?
 **/
int Window::cycle() {
	do {
		if (cycleClock->update()) {
			Sprite frameCounter(renderer->getRenderer(), std::to_string(cycleClock->getActionsPerSecond()), LEONARDO_COLOR_WHITE);
			
			renderer->drawScreen(gameScreen);
			frameCounter.render();
			renderer->updateFrame();
			
			Input::processQueue(&gameScreen, test);
			
			if	(gameScreen == LEONARDO_SCREEN_EXIT)
				break;
			
			if (gameScreen == LEONARDO_SCREEN_NONE)
				gameScreen = LEONARDO_SCREEN_1;
			
			SDL_Delay(1000 / (LEONARDO_FRAMECAP + 10));
		}
	} while (1);
	
	return 0;
}
