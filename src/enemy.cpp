#include "enemy.h"
#include <string>
#include <sstream>
#include <iostream>
#include "maths.h"
#include "game.h"

std::string get_random_living_enemy_name() {
    Enemy *random_enemy = nullptr;

    do {
        random_enemy = &game.enemies[random_int(0, game.enemies.size())];
    } while (random_enemy && !random_enemy->defeated);

    if (!random_enemy) {
        return nullptr;
    }

    return random_enemy->name;
}

//generate unique random name from name list
std::string get_random_enemy_name() {
  static bool name_used[ENEMY_NAMES_AMOUNT] = { false };

  if (ENEMY_AMOUNT > ENEMY_NAMES_AMOUNT) {
    std::cerr << "Not enough enemy names for enemy amount" << std::endl;
    exit(1);
  }

  int random_index;
  //attempt to access unique enemy name
  do {
    random_index = (int) random_int(0, ENEMY_NAMES_AMOUNT);
  } while (name_used[random_index]);

  //set name as used
  name_used[random_index] = true;

  return ENEMY_NAMES[random_index];
}

//return a fake ip string for enemies
std::string get_random_ip_string() {
  std::ostringstream ip_address;

  int ip_subsections = 4;
  //add random numbers in 0-255 range to stringstring to mock ip address
  for (int i = 0; i < ip_subsections - 1; i++) {
    ip_address << std::to_string(random_int(0, 255)) << ".";
  }
  ip_address << std::to_string(random_int(0, 255));

  return ip_address.str();
}
