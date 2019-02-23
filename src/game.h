#pragma once

#include "panel.h"
#include <vector>
#include <list>
#include <string>
#include <SDL2/SDL.h>
#include "font.h"

class Game;
extern Game game;

#define GAME_NAME "Hackerman-3.0"
#define FONT_PATH "font/inconsolata.ttf"
#define FONT_SIZE 14

class Game {
    public:
        Game();
        ~Game();
        Game(unsigned screen_width, unsigned screen_height);

        SDL_Window *window;
        SDL_Renderer *renderer;
        Font font;

        std::vector<Enemy> enemies;

        Panel main;
        ConsolePanel console;
        std::list<EnemyPanel> enemy_panels;
        std::vector<UtilButton> util_buttons;

        unsigned screen_width;
        unsigned screen_height;

        Game& operator=(const Game &other) { return *this; };

    private:
        void init_SDL();
        void set_native_resolution();
        void set_resolution(unsigned screen_width, unsigned screen_height);
        void create_window(bool fullscreen);
        void create_renderer();
        void create_screen(bool fullscreen);
};
