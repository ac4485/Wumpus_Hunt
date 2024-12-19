//
// Created by eds on 11/22/2024.
//

#include "game_menu.h"

using namespace std;
void game_menu::menu_describe() {
  std::cout << "Type \"help\" for hint."<< std::endl;
  std::cout << "Type \"status\" to check status."<< std::endl;
  std::cout << "Type \"map\" to show the map."<< std::endl;
  std::cout << "Type \"exit\" to go back to the main menu." << std::endl;
  std::cout << "map: $: goblin, ~: lakshmikanta, @: hazard, !: wall, -: sword treasure, ";
  std::cout << "^: medicine treasure, =: arrow treasure, #: empty, +: player" << std::endl;
  std::cout << "When a new weapon is picked, the old one will be replaced." << std::endl;
  std::cout << "Kill all the monster to win the game!." << std::endl;
  cout << "When opponent does not have weapon, the attack point doubled! "<< endl;
};
void game_menu::menu_loop() {
  string inp1;
  std::cout << "Game start!" << std::endl;
  menu_describe();
  std::cin >> inp1;
  while (cin) {
    if (inp1 == "exit" || g1->is_dead() || m->is_won()) {
      cout << "Back to main menu!" << std::endl;
      break;
    } else {
      menu_opts(inp1);
    };
    cin >> inp1;
  }
};
void game_menu::menu_opts(const std::string &s){
  if (dbg_menu) {
    cout << "game menu: menu opt" << endl;
  }
  if (s == "status") {
    g1->print_status();
    cout << "Monster number: " << m->get_monster_num() << endl;
  } else if (s == "help") {
    menu_describe();
  } else if (s == "e") {
  m->go_e(g1);
  } else if (s == "n") {
  m->go_n(g1);
  } else if (s == "s") {
  m->go_s(g1);
  } else if (s == "w") {
  m->go_w(g1);
  } else if (s == "map" ){
  m->print_map();
  } else {
    cout << "Please type valid command only!"<< endl;
  }
  cout << "Type 'e' to go east, 's' to go south, 'w' to go west, 'n' to go north." << endl;
  cout << "Type \"help\" for hint"<< endl;
  cout << "Type \"map hint\" for map help."<< endl;

};
