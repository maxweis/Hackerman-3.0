#include "panel.h"

#include "game.h"

ConsolePanel::ConsolePanel(SDL_Rect bound) : Panel(bound), sh_enabled(false), user_prompted(false) {
    const int console_width = game.screen_width - game.enemy_panels[0].bound.w;
    const int console_height = game.screen_height * CONSOLE_PANEL_HEIGHT_RATIO;
    const int console_x = game.enemy_panels[0].bound.w;
    const int console_y = 1 - CONSOLE_PANEL_HEIGHT_RATIO * game.screen_height;

    SDL_Rect console_bound = {console_x, console_y, console_width, console_height};

    bound = console_bound;
}
