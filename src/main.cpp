#include "main.h"

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cerr << SDL_GetError();
    }

    bool done = true;

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
        }
    }
}
