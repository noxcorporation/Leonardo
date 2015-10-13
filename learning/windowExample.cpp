#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main (int argc, char **argv) {
	SDL_Window *window;

        SDL_Init (SDL_INIT_VIDEO);

        window = SDL_CreateWindow(
		"Yo",
		500,
		500,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	
	if (window == NULL) {
		cout << "Could not resolve" << endl;
	} else {
		SDL_Delay(3000);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}
