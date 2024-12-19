//
// Created by eds on 11/23/2024.
//

#include "monster.h"

#include "../item/weapon.h"
#include "../map/map.h"
#include "../player/player.h"

// Battle menu
void monster::interaction(player* p) {
  if (this->is_dead()) {
    std::cout << "You see a " << name <<" corpse. " << std::endl;
  }else {
    std::cout << "You see a " << name <<". " << std::endl;
    std::string inp1;
    std::cout << "Please enter \"flee\" to flee!" << std::endl;
    std::cout << "Please enter \"a\" to attack!" << std::endl;
    std::cin >> inp1;
    while (std::cin) {
      if (inp1 == "flee" ) {
        std::cout << "You flee!" << std::endl;
        break;
      }
      if (inp1 == "a") {
        weapon*wp = p->get_weapon();
        if (wp == nullptr) {
          std::cout << "No weapon equiped!" << std::endl;
        }else {
          int player_ap = wp->get_ap(this->get_weapon());
          this->get_hit(player_ap);
          std::cout << " You cause "  << name << " lost "<< player_ap << "HP. "<< std::endl;
        }
        int monster_ap =  this->get_weapon()->get_ap(p->get_weapon());
        p->get_hit(monster_ap);
        std::cout << name << " fight back with magic and cause you lost " << monster_ap << " HP. " << std::endl;
      }
      if (inp1 == "status") {
        p->print_status();

        std::cout << "Monster: " << this->get_name() << ", HP: " << this->hit_point << ",  ";
        w->weapon_status();
        std::cout <<std::endl;
      }
      if (inp1 == "help") {
        void menu_describe();
      }
      if (p->is_dead()) {
        break;
      }
      if (this->is_dead()) {
        std::cout << "You win!" << std::endl;
        ma->monster_dies();
        break;
      }
      std::cout << "a or flee? Type \"help\" for hint" << std::endl;
      std::cin >> inp1;
    }
  }
}
// Return the weapon of the monster.
weapon * monster::get_weapon() const {
  if (w == nullptr) {
    return nullptr;
  }else {
    return w;
  }

}
// Show hint
void monster::menu_describe() {
  std::cout << "Type \"help\" for hint"<< std::endl;
  std::cout << "Please enter \"flee\" to flee!" << std::endl;
  std::cout << "Type \"a\" for attack"<< std::endl;
  std::cout << "Type \"status\" to check status"<< std::endl;


};
// Show $ when its alive.
void goblin::show_on_map() {
  if (this->is_dead()) {
    std::cout << '#';
  }else {
    std::cout << '$';
  }
}
// Show ~ when its alive.
void lakshmikanta::show_on_map() {
  if (this->is_dead()) {
    std::cout << '#';
  }else {
    std::cout << '~';
  }
};
