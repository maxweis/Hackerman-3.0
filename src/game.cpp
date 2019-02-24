#include "game.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include "font.h"

void init_SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cerr << SDL_GetError() << std::endl;
    }
}

void init_SDL_image() {
    if (IMG_Init(IMG_INIT_PNG)) {
        std::cerr << IMG_GetError() << std::endl;
        exit(3);
    }
}

void Game::init_enemy_panels() {
    const int enemy_panel_width = screen_width * ENEMY_PANEL_WIDTH_RATIO;
    const int enemy_panel_height = screen_height / ENEMY_AMOUNT;

    for (int i = 0; i < ENEMY_AMOUNT; i++) {
        SDL_Rect panel_rect = {0, enemy_panel_height * i, enemy_panel_width,
            enemy_panel_height};
        Enemy enemy = Enemy(i);
        enemies.push_back(enemy);
        enemy_panels.push_back(EnemyPanel(panel_rect, &enemies[i]));
    }
}

void Game::init_util_buttons() {
    const int util_button_w = (screen_width * UTIL_BUTTON_WIDTH_RATIO) / UTIL_BUTTON_COLS;
    const int util_button_h = (screen_height - console.bound.h) / UTIL_BUTTON_ROWS;

    for (int row = 0; row < UTIL_BUTTON_ROWS; row++) {
        for (int col = 0; col < UTIL_BUTTON_COLS; col++) {
            const int util_button_x = screen_width - (screen_width * UTIL_BUTTON_WIDTH_RATIO) +
                util_button_w * col;
            const int util_button_y = row * util_button_h;
            int button_number = row * UTIL_BUTTON_COLS + col;
            SDL_Rect bound = {util_button_x, util_button_y, util_button_w, util_button_h};
            std::string icon_path = UTIL_BUTTON_ICON_PATHS[button_number];
            Image image(icon_path);
            util_buttons.push_back(UtilButton(bound, icon_path));
        }
    }
}

void Game::init_main_panel() {
    const int panel_width = screen_width - enemy_panels[0].bound.w -
        (util_buttons[0].bound.w * UTIL_BUTTON_COLS);
    const int panel_height = screen_height - console.bound.h;

    SDL_Rect bound = {enemy_panels[0].bound.w, 0, panel_width, panel_height};
    main = Panel(bound);
}

void Game::init_panels() {
    init_enemy_panels();
    init_util_buttons();
    init_main_panel();
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
    init_SDL_image();
    set_native_resolution();
    create_screen(true);
    font = Font(FONT_PATH, FONT_SIZE);
    console.rows = (console.bound.h - font.height) / font.height;
    init_panels();
}

Game::Game(unsigned screen_width, unsigned screen_height) {
    init_SDL();
    init_SDL_image();
    set_resolution(screen_width, screen_height);
    create_screen(false);
    font = Font(FONT_PATH, FONT_SIZE);
    console.rows = (console.bound.h - font.height) / font.height;
    init_panels();
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
