#include "panel.h"

ConsolePanel::ConsolePanel(SDL_Rect bound) : Panel(bound), sh_enabled(false), user_prompted(false) {
    const int console_width = game.screen_width - game.enemy_panels[0].bound.w;
    const int console_height = game.screen_height * CONSOLE_PANEL_HEIGHT_RATIO;

    SDL_Rect console_bound = {game.enemy_panels[0].bound.w, (1 - CONSOLE_PANEL_HEIGHT_RATIO) * game.screen_height,
        console_width, console_height};

    bound = console_bound;
}
    
