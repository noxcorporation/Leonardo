#ifndef LEONARDO_H
#define LEONARDO_H

#include <string>
#include <chrono>

using std::string;
using namespace std::chrono;

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define LEONARDO_COLOR_WHITE SDL_Color {255, 255, 255, 255}
#define LEONARDO_COLOR_BLACK SDL_Color {0, 0, 0, 255}

#define LEONARDO_FONT_QUARMIC "../Assets/Qarmic_sans_Abridged.ttf"

#define LEONARDO_WINDOW_WIDTH 640
#define LEONARDO_WINDOW_HEIGHT 480

enum Rendering {DEFAULT, VSYNC};

#define LEONARDO_FRAMECAP 60

//Maybe use an enum instead to describe the current game screen?
#define LEONARDO_SCREEN_EXIT -1
#define LEONARDO_SCREEN_NONE 0
#define LEONARDO_SCREEN_1 1
#define LEONARDO_SCREEN_2 2
#define LEONARDO_SCREEN_LEVEL 3

#endif