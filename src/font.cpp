#include "font.h"

#include <iostream>
#include "render.h"

Font::Font(std::string font_path, unsigned font_size) {
    if (TTF_Init() == -1) {
        std::cerr << TTF_GetError() << std::endl;
        exit(2);
    }

    ttf_font = TTF_OpenFont(font_path.c_str(), font_size);
    if (!ttf_font) {
        std::cerr << TTF_GetError() << std::endl;
        exit(2);
    }
    height = TTF_FontHeight(ttf_font);
}

SDL_Rect Font::draw(std::string text, int x, int y, SDL_Color color) {
    SDL_Surface *surface = TTF_RenderText_Solid(ttf_font, text.c_str(), color);
    SDL_Rect bound = {x, y, x + surface->w, y + surface->h};
    render_surface(surface, bound);
    SDL_FreeSurface(surface);

    return bound;
}

SDL_Rect Font::draw(std::string text, int x, int y, SDL_Color color, int border) {
    return draw(text, x + border, y + border, color);
}

SDL_Rect Font::draw_center(std::string text, int x, int y, SDL_Color color) {
    int w, h;
    TTF_SizeText(ttf_font, text.c_str(), &w, &h);

    draw(text, x - (w / 2), y + (h / 2), color);

    return {x - (w / 2), y + (h / 2), w, h};
}

SDL_Rect Font::draw_center(std::string text, int x, int y, SDL_Rect bound, SDL_Color color) {
    return draw_center(text, x + (bound.w / 2), y + (bound.h / 2), color);
}

SDL_Rect Font::draw_align_x(std::string text, SDL_Rect bound, double y_ratio, SDL_Color color) {
    return draw_center(text, bound.x + (bound.w / 2), bound.y + (y_ratio * bound.h), color);
}

SDL_Rect Font::draw_bottom_left(std::string text, int x, int y, SDL_Color color) {
    SDL_Surface *surface = TTF_RenderText_Solid(ttf_font, text.c_str(), color);
    SDL_Rect bound = {x, y, x + surface->w, y + surface->h};
    render_surface(surface, bound);
    SDL_FreeSurface(surface);

    return bound;
}

Font::~Font() {
    TTF_CloseFont(ttf_font);
}
