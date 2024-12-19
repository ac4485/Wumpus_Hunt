//
// Created by eds on 12/1/2024.
//

#ifndef ALIVE_H
#define ALIVE_H
#include <string>
#include <iostream>

class weapon;
/*
 * The class that handles the hit point related interactions, and pick the weapon.
 */
class alive {
public:
  alive(const std::string &nn, int hp):name(nn),hit_point(hp){}

  virtual ~alive() {
   if (dbg_life) {
    std::cout << "alive " << name << " erased. " <<std:: endl;
   }
   name.erase();
  }
  /*
   * Check if the player or the monsters are dead.
   */
  virtual bool is_dead() const;
  /*
   * Reduce the hit point during the battle.
   */
  void get_hit(int att_point);
  /*
   * For the player takes the medicine and gain hit point.
   */
  void take_medicine(int eff);
 /*
  * For show status on the terminal.
  */
  std::string get_name() const;
 /*
  * For the calculate the correct attack point during the battle. Return the current weapon.
  */
  virtual weapon* get_weapon() const=0;
protected:
 /*
  * Store the name.
  */
  std::string name;
 /*For tracking the hit point. */
  int hit_point;
 bool dbg_life = false;

};



#endif //ALIVE_H
