#include "player.h"

void Player::update_player() {
  if (!password_encrypted && !firewall_up) {
    defeated = true;
  }
}
