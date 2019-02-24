#pragma once

#include <SDL2/SDL.h>

extern const SDL_Color FG_COLOR;
extern const SDL_Color BG_COLOR;
extern const SDL_Color TEXT_COLOR;
extern const SDL_Color WHITE;
extern const unsigned LINE_WIDTH;
extern const unsigned BORDER_WIDTH;

void render_surface(SDL_Surface *surface, SDL_Rect bound);
void draw_panels();
