#pragma once

#include <string>
#include <SDL2/SDL_ttf.h>

class Font {
    public:
        Font() {}
        Font(std::string font_path, unsigned font_size);
        ~Font();

        TTF_Font *ttf_font;
        unsigned height;
        
        SDL_Rect draw(std::string text, int x, int y, SDL_Color color);
        SDL_Rect draw(std::string text, int x, int y, SDL_Color color, int border);
        SDL_Rect draw_center(std::string text, int x, int y, SDL_Color color);
        SDL_Rect draw_center(std::string text, int x, int y, SDL_Rect bound, SDL_Color color);
        SDL_Rect draw_align_x(std::string text, SDL_Rect bound, double y_ratio, SDL_Color color);
        SDL_Rect draw_bottom_left(std::string text, int x, int y, SDL_Color color);
};
