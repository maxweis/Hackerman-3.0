#include "render.h"

#include <SDL2/SDL2_gfxPrimitives.h>
#include "game.h"

const SDL_Color FG_COLOR = {0, 255, 0, 255};
const SDL_Color BG_COLOR = {0, 0, 0, 255};
const SDL_Color TEXT_COLOR = {0, 255, 0, 255};
const SDL_Color WHITE = {255, 255, 255, 255};
const unsigned LINE_WIDTH = 3;
const unsigned BORDER_WIDTH = 6;

void clear_screen() {
    SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, 255);
    SDL_RenderClear(game.renderer);
}

void draw_hollow_rect(SDL_Rect rect, unsigned thickness, SDL_Color color) {
    thickLineRGBA(game.renderer, 
            rect.x, rect.y, rect.x + rect.w, rect.y, thickness,
            color.r, color.g, color.b, color.a); // top
    thickLineRGBA(game.renderer, rect.x, rect.y, rect.x, rect.y + rect.h, thickness, 
            color.r, color.g, color.b, color.a); // left
    thickLineRGBA(game.renderer, rect.x + rect.w, rect.y, rect.x + rect.w, rect.y + rect.h,
            thickness, color.r, color.g, color.b, color.a); // right
    thickLineRGBA(game.renderer, rect.x, rect.y + rect.h, rect.x + rect.w, rect.y + rect.h,
            thickness, color.r, color.g, color.b, color.a); // bottom
}

void render_surface(SDL_Surface *surface, SDL_Rect bound) {
    SDL_Texture *texture = SDL_CreateTextureFromSurface(game.renderer, surface);
    SDL_RenderCopy(game.renderer, texture, NULL, &bound);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void render_console_panel() {
    draw_hollow_rect(game.console.bound, LINE_WIDTH, FG_COLOR);

    std::string console_text = ">> " + game.console.current_command.str();
    SDL_Color render_color = game.console.has_focus ? WHITE : FG_COLOR;
    game.font.draw_bottom_left(console_text.c_str(), game.console.bound.x + BORDER_WIDTH,
            game.console.bound.y + game.console.bound.h - BORDER_WIDTH, render_color);

    for (unsigned i = 0; i < game.console.history.size() && i < game.console.rows; i++) {
        game.font.draw_bottom_left(game.console.history[i], game.console.bound.x + BORDER_WIDTH,
                game.console.bound.y + game.console.bound.h - BORDER_WIDTH - (i + 1) * game.font.height,
                FG_COLOR);
    }
}
