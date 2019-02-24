#include "image.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include "game.h"
#include "render.h"

Image::Image(const std::string path) {
    surface = IMG_Load(path.c_str());
    if (!surface) {
        std::cerr << IMG_GetError() << std::endl;
    }
}

void Image::draw(SDL_Rect *bound) {
    if (!bound) {
        return;
    }
    render_surface(surface, *bound);
}

Image::~Image() {
    SDL_FreeSurface(surface);
}
