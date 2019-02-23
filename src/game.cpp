#include "game.h"
#include <iostream>
#include <SDL2/SDL_image.h>

Game game = Game();

void Game::init_SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cerr << SDL_GetError() << std::endl;
    }
}

void Game::init_enemy_panels() {
    const int enemy_panel_width = game.screen_width * ENEMY_PANEL_WIDTH_RATIO;
    const int enemy_panel_height = game.screen_height / ENEMY_AMOUNT;

    for (int i = 0; i < ENEMY_AMOUNT; i++) {
        SDL_Rect panel_rect = {0, enemy_panel_height * i, enemy_panel_width,
            enemy_panel_height};
        Enemy enemy = Enemy(i);
        game.enemies.push_back(enemy);
        game.enemy_panels.push_back(EnemyPanel(panel_rect, &game.enemies[i]));
    }
}

void Game::init_util_buttons() {
    const int util_button_w = (game.screen_width * UTIL_BUTTON_WIDTH_RATIO) / UTIL_BUTTON_COLS;
    const int util_button_h = (game.screen_height - game.console.bound.h) / UTIL_BUTTON_ROWS;

    for (int row = 0; row < UTIL_BUTTON_ROWS; row++) {
        for (int col = 0; col < UTIL_BUTTON_COLS; col++) {
            const int util_button_x = game.screen_width - (game.screen_width * UTIL_BUTTON_WIDTH_RATIO) +
                util_button_w * col;
            const int util_button_y = row * util_button_h;
            int button_number = row * UTIL_BUTTON_COLS + col;
            SDL_Rect bound = {util_button_x, util_button_y, util_button_w, util_button_h};
            std::string icon_path = UTIL_BUTTON_ICON_PATHS[button_number];

        }
    }
}

void Game::set_native_resolution() {
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    screen_width = DM.w;
    screen_height = DM.h;
}

void Game::set_resolution(unsigned screen_width, unsigned screen_height) {
    this->screen_width = screen_width;
    this->screen_height = screen_height;
}

void Game::create_window(bool fullscreen) {
    Uint32 flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_RESIZABLE;
    window = SDL_CreateWindow(GAME_NAME.c_str(), SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, screen_width, screen_height, flags);
}

void Game::create_renderer() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Game::create_screen(bool fullscreen) {
    create_window(fullscreen);
    create_renderer();
}

Game::Game() {
    init_SDL();
    set_native_resolution();
    create_screen(true);
    font = Font(FONT_PATH, FONT_SIZE);
    console.rows = (console.bound.h - font.height) / font.height;
}

Game::Game(unsigned screen_width, unsigned screen_height) {
    init_SDL();
    set_resolution(screen_width, screen_height);
    create_screen(false);
    font = Font(FONT_PATH, FONT_SIZE);
    console.rows = (console.bound.h - font.height) / font.height;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
