#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

//How to: Creer une fenetre

int windowExample (int argc, char **argv) {
	SDL_Window *window;   		//pointeur window	

        SDL_Init (SDL_INIT_VIDEO);  	//Initialisation de la SDL

        window = SDL_CreateWindow(	//Methode creer fenetre
		"Yo",			//titre
		500,			//position x initiale
		500,			//position y initiale
		640,			//taille x
		480,			//taille y
		SDL_WINDOW_OPENGL	//flags
	);
	
	if (window == NULL) {		//fool proof
		cout << "Could not resolve" << endl;
	} else {
		SDL_Delay(3000);	//pause de 3 secondes
		SDL_DestroyWindow(window);//fermer la fenetre
		SDL_Quit();		//quitter SDL [Important!]
	}
}
