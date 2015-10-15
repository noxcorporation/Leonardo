#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Map {
	private:
		SDL_Window *window;
		SDL_Event event;
	public:
		Map();
};

Map::Map () {
    window = SDL_CreateWindow(
        "Leonardo",
        500,
        500,
        640,
        480,
	SDL_WINDOW_OPENGL
    );

    if (window == NULL)
	cout << "Couldn't resolve" << endl;
    else {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        while( SDL_PollEvent( &event ) ){
	    if (event.type == SDL_KEYDOWN)
		return 0;
  	}
    }            
}
