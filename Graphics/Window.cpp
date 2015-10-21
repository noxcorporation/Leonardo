#include "Window.h"
#include "Input/Input.h"


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
	
	renderer = new Renderer(window);
	
	gameScreen = LEONARDO_SCREEN_NONE;
}

/*
 * This destructor closes the window and SDL to free memory.
 **/
Window::~Window() {
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
		renderer->drawScreen(gameScreen);
		renderer->updateFrame();
		
		Input::processQueue(&gameScreen);
		
		if	(gameScreen == LEONARDO_SCREEN_EXIT)
			break;
		
		if (gameScreen == LEONARDO_SCREEN_NONE)
			gameScreen = LEONARDO_SCREEN_1;
	} while (1);
	
	return 0;
}
