//
// Created by eds on 12/1/2024.
//

#ifndef MENU_H
#define MENU_H
#include <string>


class menu {
public:
 menu(){}
 /*
  * Descructor.
  */
  virtual ~menu(){};
  /*
   * Print the descriptions on the terminal.
   */
  virtual void menu_describe()=0;
  /*
   * Loop the menu.
   */
  virtual void menu_loop()=0;
  /*
   * Parse and execute the menu options.
   */
  virtual void menu_opts(const std::string &s) =0;

 protected:
 // For debug the menu.
  bool dbg_menu = false;
};



#endif //MENU_H
