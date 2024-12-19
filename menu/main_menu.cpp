//
// Created by eds on 11/22/2024.
//

#include "main_menu.h"

#include "game_menu.h"
using namespace std;

void main_menu::menu_describe() {
  std::cout << "Type \"help\" for hint."<< std::endl;
  std::cout << "Type \"start\" to start the player."<< std::endl;
  std::cout << "Type \"exit\" to go back to the main menu." << endl;

};
void main_menu::menu_loop() {
  std::cout <<  "Welcome to Wumpus Hunt!" << endl;
  menu_describe();
  string a;
  cin >> a;
  while (cin) {
    std::cout << "Main menu" << endl;
    if (a == "exit") {
      break;
    }else {
      menu_opts(a);
    }
    cin>>a;
  }


};
void main_menu::menu_opts(const std::string &s){
  if (s == "help") {
    menu_describe();
  } else if (s == "start") {
    gm1->menu_loop();
  } else {
    cout << "Invalid input! Type \"help\" to get hints." << endl;

  }
} ;
