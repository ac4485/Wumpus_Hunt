//
// Created by eds on 11/23/2024.
//

#ifndef MAP_H
#define MAP_H

#include "../event/event.h"
#include "../event/monster.h"
#include "../event/treasure.h"
/*
 * The class that handles all positional changes.
 */
class map final {
public:
  /*
   * col: column number of the map
   * row: row number of the map
   */
  map(const int col, const int row) {
    col_num = col;
    row_num = row;

    map_generator();
   // for debugging
   dbg_map = false;
  }

  ~map() {
   delete c;
  };
  /*
   * Generate a map randomly that fit the col and row.
   */
  void map_generator();
  /*
   * Print the current map. Dead monsters and picked treasured will show empty on the map, but it will show notification when pass.
   */
  void print_map() const;
  /*
   * Player go south a block.
   */
  void go_s(player* gg);
  /*
   * Player go north a block.
  */
  void go_n(player* gg);
 /*
   * Player go east a block.
   */
  void go_e(player* gg);
 /*
    * Player go west a block.
    */
  void go_w(player* gg);
 /*
   * Check whether the move is valid.
   */
  bool is_valid(int x, int y) const;
 /*
  * -1 monster_num
  */
  void monster_dies();
 /*
  * For print the monster_num to show the status.
  */
  int get_monster_num() const;
 /*
  * If all monster dies, the player wins.
  */
  bool is_won() const;

private:
 /*
  * Store the 2d array of the events.
  */
  event***c = nullptr;
 /*
  * The row number of the map.
  */
  int row_num ;
 /*
  * The column number of the map.
  */
  int col_num;
  // Player position, yy is opposite.
  int yy = 0;
 // Player position, xx is normal.
  int xx = 0;
 // Track the alive monster number on the map.
  int monster_num = 0;
 // For debugging the map
 bool dbg_map = false;
};



#endif //MAP_H
