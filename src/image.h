#pragma once

#include <string>
#include <SDL2/SDL.h>

class Image {
    public:
        Image();
        ~Image();
        Image(const std::string path);

        void draw(SDL_Rect *bound);

        SDL_Surface *surface;
};
