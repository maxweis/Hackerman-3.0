#include "main.h"

#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
#include "render.h"

Game game;

void set_window_opts(int argc, char *argv[]) {
    if (argc > 1) {
        if (!strcmp(argv[1], "-f")) {
            game = Game();
        }
        else if (!strcmp(argv[1], "-w")) {
            game = Game(atoi(argv[2]), atoi(argv[3]));
        }
    } else {
        game = Game();
    }
}

int main(int argc, char *argv[]) {
    set_window_opts(argc, argv);

    bool done = true;

    //while (!done) {
        //SDL_Event event;
        //while (SDL_PollEvent(&event)) {
            //if (event.type == SDL_QUIT) {
                //return 0;
            //}
        //}
        //draw_panels();
    //}

    SDL_Quit();
    return 0;
}
