//
// Created by eds on 11/23/2024.
//

#ifndef MONSTER_H
#define MONSTER_H
#include <utility>
#include "../item/weapon.h"
#include "event.h"
#include "../alive/alive.h"
#include "../menu/menu.h"


class map;

class monster : public event, public alive{
public:
  monster(const std::string& name,weapon* w,int hp,map* m):alive(name,hp),w{w},ma{m} {
    if (dbg_life) {
      std::cout << "Monster ";
    }
  };
  ~monster() override {
    delete w;
  }
  bool can_go() override{return true;};
  void interaction(player* p) override;
  weapon* get_weapon() const override;

protected:
  weapon* w = nullptr;
  map* ma;
private:
  static void menu_describe();

};

#endif //MONSTER_H

#ifndef GOBLIN_H
#define GOBLIN_H


/*
 * Simulate a goblin.
 */
class goblin final : public monster {
public:
  goblin(map* m) : monster("goblin",new craw(),25,m) {
    if (dbg_life) {
      std::cout << "goblin created" << std::endl;
    }
  };
  ~goblin() override {};
  // alive: $
  void show_on_map() override;
};
#endif //GOBLIN_H

#ifndef LAKSHMIKANTA_H
#define LAKSHMIKANTA_H

class lakshmikanta final : public monster{
public:
  lakshmikanta(map* p): monster("lakshmikanta",new magic(),30,p) {
    if (dbg_life) {
      std::cout << "lakshmikanta created" << std::endl;
    }
  }
  ~lakshmikanta()override {};
  // alive: ~
  void show_on_map() override;

};



#endif //LAKSHMIKANTA_H

