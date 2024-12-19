//
// Created by eds on 12/1/2024.
//

#include "player.h"

#include "../item/weapon.h"


void player::set_weapon(weapon* wp) {
  if (dbg_life) {
    std::cout << "Weapon picked!" << std::endl;
  }
  if (w != nullptr) {
    delete w;
    if (dbg_life) {
      std::cout << "Old weapon deleted!" << std::endl;
    }
  }
  w = wp;
}

weapon * player::get_weapon() const {
  if (w == nullptr) {
    // No weapon
    return nullptr;
  }else {
    return w;
  }
}

void player::print_status() const {
  std::cout << name << ", HitPoint: " << hit_point << std::endl;
  std::cout << "Weapon: ";
  if (w != nullptr) {
    w->weapon_status();
  }else {
    std::cout << "None" << std::endl;
  }
}

bool player::is_dead() const {
  if (alive::is_dead()) {
    std::cout << "You are dead! You lose! " << std::endl;
    return true;
  }

  return false;
}
