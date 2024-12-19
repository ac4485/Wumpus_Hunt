//
// Created by eds on 11/23/2024.
//

#include "event.h"
#include "../player/player.h"
// Default block
void event::show_on_map(){
  std::cout << '#';
}

void event::interaction(player *p) {
  std::cout << "You smells danger!" << std::endl;
}

// hazard &
void hazard::show_on_map(){
  std::cout << '@';
}

void hazard::interaction(player *p) {
  std::cout << "You fall into a hazard!" << std::endl;
  p->get_hit(10);
}

void wall::show_on_map() {
  std::cout << '!';
}