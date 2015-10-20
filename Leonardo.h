#ifndef LEONARDO_H
#define LEONARDO_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define LEONARDO_COLOR_WHITE {255, 255, 255, 255}
#define LEONARDO_COLOR_BLACK {0, 0, 0, 255}

#define LEONARDO_FONT_QUARMIC "../Assets/Qarmic_sans_Abridged.ttf"

#define LEONARDO_WINDOW_WIDTH 640
#define LEONARDO_WINDOW_HEIGHT 480

//Maybe use an enum instead to describe the current game screen?
#define LEONARDO_SCREEN_EXIT -1
#define LEONARDO_SCREEN_NONE 0
#define LEONARDO_SCREEN_1 1
#define LEONARDO_SCREEN_2 2

#endif