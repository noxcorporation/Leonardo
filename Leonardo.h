#ifndef LEONARDO_H
#define LEONARDO_H

#include <string>
#include <fstream>
#include <chrono>
#include <vector>
#include <glm/vec2.hpp>

using std::string;
using std::ifstream;
using glm::vec2;
using namespace std::chrono;

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define LEONARDO_COLOR_WHITE SDL_Color {255, 255, 255, 255}
#define LEONARDO_COLOR_BLACK SDL_Color {0, 0, 0, 255}

#define LEONARDO_FONT_QUARMIC "../Assets/Qarmic_sans_Abridged.ttf"

#define LEONARDO_WINDOW_WIDTH 640
#define LEONARDO_WINDOW_HEIGHT 480

#define LEONARDO_FRAMECAP 60

enum Rendering {
	DEFAULT,
	VSYNC
};

enum GameScreen {
	LEONARDO_SCREEN_EXIT = -1,
	LEONARDO_SCREEN_NONE,
	LEONARDO_SCREEN_1,
	LEONARDO_SCREEN_2,
	LEONARDO_SCREEN_3
};

enum SpriteDirection {
	LEFT,
	RIGHT
};

#endif
