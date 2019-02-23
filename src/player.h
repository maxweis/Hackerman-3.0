#pragma once

#include <string>

std::string GetRandomPassword(int length);

class Player {
  public:
    Player() : bitcoin(0), password(GetRandomPassword(10)), connected(false),
    firewall_up(true), password_encrypted(false), sh_unlocked(false), defense(1){}

    void update_player();

    unsigned bitcoin;
    std::string password;

    //connected to enemies
    bool connected;
    bool firewall_up;
    bool password_encrypted;
    bool defeated;
    //sh mode bought from store or unlocked via cheat code
    bool sh_unlocked;
    bool attacked_firewall;

    int defense;

    int enemies_defeated;
};
