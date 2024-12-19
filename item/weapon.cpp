//
// Created by eds on 12/1/2024.
//

#include "weapon.h"
#include "../player/player.h"
void weapon::benefit_player(player* p) {
  p->set_weapon(this);
}
void melee::weapon_status() {
  std::cout << name  << "(melee), Attack Point: " << ap << std::endl;
}

std::string melee::get_weapon_type() {
  return std::string("melee");
}
// When opponent does not have weapon, the ap doubled
int melee::get_ap(weapon *w) const {
  int r1 = 0;
  if (w== nullptr) {
    r1 = ap * 2;
  }else if (w->get_weapon_type() == "melee") {
    r1 = ap;
  }
  return r1;
}


void long_range::weapon_status() {
  std::cout << name  << "(long range), Attack Point: " << ap << std::endl;
}

std::string long_range::get_weapon_type() {
  return std::string("long_range");
}
// When opponent does not have weapon, the ap doubled
int long_range::get_ap(weapon *w) const {
  int r1 = 0;
  if (w == nullptr) {
    r1 = ap * 2;
  }else
    if (w->get_weapon_type() == "melee") {
      r1 = ap;
    }else if (w->get_weapon_type() == "long_range") {
      r1 = ap / 2;
    }


  return r1;
}

