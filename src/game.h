#pragma once

#include "panel.h"
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include "font.h"
#include "enemy.h"

class Enemy;
class Panel;

const std::string GAME_NAME = "Hackerman-3.0";
const std::string FONT_PATH = "font/inconsolata.ttf";
const unsigned FONT_SIZE = 14;

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
        std::vector<EnemyPanel> enemy_panels;
        std::vector<UtilButton> util_buttons;

        unsigned screen_width;
        unsigned screen_height;

        Game& operator=(const Game &other) { return *this; };

    private:
        void init_enemy_panels();
        void init_util_buttons();
        void init_main_panel();
        void init_panels();
        void set_native_resolution();
        void set_resolution(unsigned screen_width, unsigned screen_height);
        void create_window(bool fullscreen);
        void create_renderer();
        void create_screen(bool fullscreen);
};
