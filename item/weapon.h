//
// Created by eds on 12/1/2024.
//

#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"
#include <iostream>

class player;
class melee;
class long_range;
/*
 * The weapon that the player and monsters will use.
 */
class weapon: public item {
public:
  /*
   * Init a new weapon with the attack point.
   */
  weapon(const int a): ap(a){};
 ~weapon() {
  if (dbg_item) {
   std::cout << "Weapon" << name << " erased. " <<std:: endl;
  }
  name.erase();
 }
  void benefit_player(player* p) override;
  /*
   * The attack point will be different based on the opponent's weapon.
   */
  virtual int get_ap(weapon* ) const=0;
  /*
   * Check the opponent's weapon type.
   */
  virtual std::string get_weapon_type()=0;
  /*
   * Print the weapon status on the terminal
   */
  virtual void weapon_status()=0;
protected:
 /*
  * The attack point
  */
  int ap;
 /*
  * Store the name of the weapon.
  */
  std::string name;
};

#endif //WEAPON_H


#ifndef MELEE_H
#define MELEE_H

/*
 * Melee weapons can't attack the enemy that holds a long range weapon.
 */
class melee:public weapon{
public:
 melee(const int a):weapon(a){};
 /* Show as a melee weapon */
 void weapon_status() override;
 /* Return the weapon typeas melee. */
 std::string get_weapon_type()override;
 /* Calculate the correct attack point */
 int get_ap(weapon* w) const override;

};



#endif //MELEE_H

#ifndef SWORD_H
#define SWORD_H



class long_range;
/*
 * The sword that the player can pick.
 */
class sword final :public melee{
public:
 sword(): melee(6) {
  name = std::string("sword");

 }
protected:
};



#endif //SWORD_H

#ifndef CRAW_H
#define CRAW_H

/*
 * Goblins' weapon.
 */
class craw final :public melee{
public:
 craw():melee(4) {
  name = std::string("craw");
 };
 ~craw(){};
};

#endif //CRAW_H


#ifndef LONG_RANGE_H
#define LONG_RANGE_H

/*
 * The attack point of long range weapon will decrease in half if the enemy is also using a long range weapon.
 */
class long_range:public weapon {
public:
 long_range(int a):weapon(a){};
 /* Show as a long range weapon */
 void weapon_status() override;
 /* Return the weapon type. */
 std::string get_weapon_type()override;
 /* Calculate the correct attack point */
 int get_ap(weapon* w) const override;

};



#endif //LONG_RANGE_H


#ifndef MAGIC_H
#define MAGIC_H

/*
 * The lakshmikanta will use magic.
 */
class magic final : public long_range{
public:
 magic():long_range(6) {
  name = std::string("magic");
 };
};



#endif //MAGIC_H

#ifndef ARROW_H
#define ARROW_H

/*
 * The long range weapon that the player can use.
 */
class arrow final : public long_range{
public:
 arrow(): long_range(5) {
  name = std::string("arrow");
 };
};



#endif //ARROW_H
