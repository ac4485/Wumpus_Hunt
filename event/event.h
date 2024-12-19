//
// Created by eds on 11/23/2024.
//

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class player;
// Responsible for the default event, empty floor.
class event {
public:
  virtual ~event() = default;
  /*
   * Different event will show different notation on the map. For this empty one, show #
   */
  virtual void show_on_map();
  // The player can't pass the wall
  virtual bool can_go() {return true;};
  // default contains nothing but a sentence.
  virtual void interaction(player* p);
protected:
bool dbg_events = false;
};

#endif //EVENT_H

#ifndef HAZARD_H
#define HAZARD_H
// Responsible for hazard, -10 hp, won't disappear or die.
class hazard : public event{
public:
  hazard():event() {
    if (dbg_events) {
      std::cout << "hazard created" << std::endl;
    }

  };
  // Show @
  void show_on_map() override;
  void interaction(player* p) override;
protected:
};


#endif //HAZARD_H

#ifndef WALL_H
#define WALL_H

class wall :public event{
public:
  wall(): event() {
    if (dbg_events) {
      std::cout << "wall created" << std::endl;
    }
  };
  // Show !
  void show_on_map() override;
  bool can_go() override {return false;};
protected:

};



#endif //WALL_H
