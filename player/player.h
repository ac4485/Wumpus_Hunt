//
// Created by eds on 12/1/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../alive/alive.h"
#include "../item/weapon.h"
class item;

class player : public alive {
  public:
  player(): alive(std::string("player"),200) {
  };
  ~player() {
    if (w != nullptr) {
      delete w;
    }
  };
  /*
   * Pick the weapon. The current weapon will disappear.
   */
  void set_weapon(weapon* w);
  weapon* get_weapon()const override;
  void print_status() const;
  bool is_dead() const override;
private:
  weapon* w = nullptr;
};



#endif //PLAYER_H
