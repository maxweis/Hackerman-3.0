#include "enemy.h"
#include <string>
#include <sstream>
#include <iostream>
#include "maths.h"

//std::string get_random_living_enemy_name() {
  //std::string name;
  //int random_enemy_number;

  //do {
    //random_enemy_number = ofRandom(0, enemy_panels.size());
    //name = enemy_panels[random_enemy_number].enemy.name;
  //} while (enemy_panels[random_enemy_number].enemy.defeated);

  //return enemy_panels[random_enemy_number].enemy.name;
//}

//generate unique random name from name list
std::string get_random_enemy_name() {
  static bool name_used[kEnemyNamesAmount] = { false };

  if (kEnemyAmount > kEnemyNamesAmount) {
    std::cerr << "Not enough enemy names for enemy amount" << std::endl;
    exit(1);
  }

  int random_index;
  //attempt to access unique enemy name
  do {
    random_index = (int) random_int(0, kEnemyNamesAmount);
  } while (name_used[random_index]);

  //set name as used
  name_used[random_index] = true;

  return kEnemyNames[random_index];
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
