//
// Created by eds on 12/1/2024.
//

#include "alive.h"

bool alive::is_dead() const {
  return hit_point < 1;
}

void alive::get_hit(int att_point) {
  hit_point = hit_point - att_point;
}

void alive::take_medicine(int eff) {
  hit_point = hit_point + eff;
}

std::string alive::get_name() const {
  return name;
}
