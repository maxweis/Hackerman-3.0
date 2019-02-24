#pragma once

#include <vector>
#include <string>
#include <deque>
#include <sstream>
#include <SDL2/SDL.h>
#include "render.h"
#include "image.h"

class Enemy;

enum UtilButtonType {
  CONNECT, //connect to enemies
  DISCONNECT, //disconnect from enemies
  FIREWALL_UP, //put up firewall
  ENCRYPT, //encrypt your password
  FILESYSTEM, //access your filesystem
  STORE, //purchase upgrades from store
  FIREWALL_ATTACK, //attack enemy's firewall
  DECRYPT, //decrypt enemy's password once firewall is down
};

enum MainPanelState {
  FILESYSTEM_STATE,
  STORE_STATE,
};

class Panel {
  public:
    Panel() : bg_color(BG_COLOR), text_color(TEXT_COLOR), has_focus(false) {}
    Panel(SDL_Rect bound) : 
      bound(bound), bg_color(BG_COLOR), text_color(TEXT_COLOR), has_focus(false) {}
    Panel(SDL_Rect bound, SDL_Color bg_color,
        SDL_Color text_color) : 
      bound(bound), bg_color(bg_color), 
      text_color(text_color), has_focus(false) {}

    unsigned state;

    SDL_Rect bound;
    SDL_Color bg_color;
    SDL_Color text_color;

    bool has_focus;
}; 

class UtilButton : public Panel {
  public:
    UtilButton() : Panel() {}
    UtilButton(SDL_Rect bound) : Panel(bound) {}
    UtilButton(SDL_Rect bound, std::string image_path) : Panel(bound), 
      image(Image(image_path)) {}
    UtilButton(SDL_Rect bound, SDL_Color bg_color,
        SDL_Color text_color, std::string image_path)
      : Panel(bound, bg_color, text_color), image(Image(image_path)) {}

    UtilButtonType type;
    Image image;

    int number, row, column;
};

class StatusBar : public Panel {
  public:
    StatusBar() : Panel(), fill(1) {}
    StatusBar(SDL_Rect bound, float fill) : Panel(bound), fill(fill) {}

    float fill;
};

class ConsolePanel : public Panel {
  public:
    ConsolePanel() {}
    ConsolePanel(SDL_Rect bound);

    std::deque<std::string> history;
    std::stringstream current_command;
    std::string prompt_answer;
    unsigned rows;

    //access sh shell
    bool sh_enabled;
    bool user_prompted;

    std::vector<std::string> sh_exec(std::string cmd);
};

class EnemyPanel : public Panel {
  public:
    EnemyPanel(SDL_Rect bound, Enemy *enemy)
      : Panel(bound), enemy(enemy) {}

    Enemy *enemy;
};

//percentage of screen enemy panel takes up horizontally
const float ENEMY_PANEL_WIDTH_RATIO = 1.0 / 5.0;

//percentage of screen console takes up vertically
const float CONSOLE_PANEL_HEIGHT_RATIO = 3.0 / 10.0;

const int UTIL_BUTTON_ROWS = 4;
const int UTIL_BUTTON_COLS = 2;
const int UTIL_BUTTON_AMOUNT = UTIL_BUTTON_ROWS * UTIL_BUTTON_COLS;
const float UTIL_BUTTON_WIDTH_RATIO = 1.0 / 5.0;
const std::vector<std::string> UTIL_BUTTON_ICON_PATHS = {"assets/icons/connect.png", "assets/icons/disconnect.png", "assets/icons/firewall_up.png", "assets/icons/encrypt.png",
"assets/icons/files.png", "assets/icons/bitcoin.png", "assets/icons/firewall_attack.png", "assets/icons/decrypt.png"};
