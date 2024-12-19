//
// Created by eds on 11/22/2024.
//

#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "menu.h"
#include "game_menu.h"
#include <iostream>
#include <ostream>
#include <string>

class main_menu final : menu{
public:
  main_menu()= default;
  ~main_menu() override {
    delete gm1;
  } ;
  /*
 * Print the descriptions on the terminal.
 */
  void menu_describe() override;
  /*
  * Loop the main menu.
  */
  void menu_loop() override;
  /*
   * Parse and execute the menu options.
  */
  void menu_opts(const std::string &s) override;
private:
  // player* g1 = nullptr;
  game_menu* gm1 = new game_menu();

};




#endif //MAIN_MENU_H
