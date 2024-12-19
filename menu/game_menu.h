//
// Created by eds on 11/22/2024.
//
// $: goblin, ~: lakshmikanta, @: hazard, #:empty, !: wall, -: sword treasure, ^: medicine treasure, =: arrow treasure
#ifndef GAME_MENU_H
#define GAME_MENU_H


#include "menu.h"
#include "../player/player.h"
#include "../map/map.h"

#include <iostream>
#include <ostream>
#include <string>

class game_menu final : menu
{
public:
  /*
   * Initialize the player and the map
   */
  game_menu() {

    g1 = new player();
    m = new map(5,5);
  };
  /*
   * Descructor
   */
  ~game_menu() override {
    delete g1;
    if (dbg_menu) {
      std::cout << "Game deleted!";
    }

    delete m;
    if (dbg_menu) {
      std::cout << "map deleted!";
    }
  };
  /*
   * Print the descriptions on the terminal.
   */
  void menu_describe() override;
  void menu_loop() override;
  void menu_opts(const std::string &s) override;
private:
  player* g1;
  map* m;

};




#endif //GAME_MENU_H
