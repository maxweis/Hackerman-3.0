#include "game.h"
#include <iostream>

Game game = Game();

void Game::init_SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cerr << SDL_GetError() << std::endl;
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
    window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED,
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
