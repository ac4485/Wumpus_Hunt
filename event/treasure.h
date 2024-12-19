//
// Created by eds on 11/23/2024.
//

#ifndef TREASURE_H
#define TREASURE_H

#include "../item/weapon.h"
#include "event.h"

// class item;
class player;
// treasure, player can pick items from them.
class treasure : public event{
public:
  bool can_go() override;
  ~treasure() {
    delete its;
  };

protected:
  item* its = nullptr;
  bool is_picked = false;
};

#endif //TREASURE_H

#ifndef ARROW_TREASURE_H
#define ARROW_TREASURE_H
// Contain arrow.
class arrow_treasure: public treasure {
public:
  arrow_treasure() {
    its = new arrow();
  };
  // Unpicked: =
  void show_on_map() override;
  void interaction(player* p) override;

};



#endif //ARROW_TREASURE_H


#ifndef MEDICINE_TREASURE_H
#define MEDICINE_TREASURE_H


// Contain medicine
class medicine_treasure : public treasure{
public:
  medicine_treasure():treasure() {
    its = new medicine();
  };
  // Unpicked: ^
  void show_on_map() override;
  void interaction(player* p) override;

};



#endif //MEDICINE_TREASURE_H


#ifndef SWORD_TREASURE_H
#define SWORD_TREASURE_H
// Contain sword
class sword_treasure final : public treasure{
public:
  sword_treasure():treasure() {
    its = new sword();
  };
  // Unpicked: -
  void show_on_map() override;
  void interaction(player* p) override;
};



#endif //SWORD_TREASURE_H
