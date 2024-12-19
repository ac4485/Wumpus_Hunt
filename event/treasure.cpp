//
// Created by eds on 11/23/2024.
//

#include "treasure.h"
#include "../player/player.h"
#include "../item/weapon.h"
bool treasure::can_go() {
  return true;
}


void arrow_treasure::show_on_map() {

  if (is_picked) {

    std::cout << '#';
  } else {

    std::cout << '=';
  }
}

void arrow_treasure::interaction(player *p) {
  if (is_picked) {
    std::cout<<"You see an empty box. ";

  } else {
    std::cout<<"You open a box and get some arrow. ";
    p->set_weapon(dynamic_cast<weapon *>(this->its));
    is_picked = true;

  }
  std::cout << std::endl;
}


void medicine_treasure::show_on_map() {
  if (is_picked) {
    std::cout << '#';
  } else {
    std::cout << '^';
  }
}

void medicine_treasure::interaction(player *p) {
  if (is_picked) {
    std::cout<<"You see an empty box. ";
  } else {
    std::cout<<"You find and take some medicine. ";
    dynamic_cast<medicine *>(this->its)->benefit_player(p);
    is_picked = true;
  }
  std::cout << std::endl;
}


void sword_treasure::show_on_map() {
  if (is_picked) {
    std::cout<<"#";
  }else {
    std::cout<<"-";
  }

}

void sword_treasure::interaction(player *p) {
  if (is_picked) {
    std::cout<<"You see an empty box. ";
  } else {
    std::cout<<"You open a box and get a sword. ";
    p->set_weapon(dynamic_cast<weapon *>(this->its));
    is_picked = true;
  }
  std::cout << std::endl;
}
