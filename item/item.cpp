//
// Created by eds on 12/1/2024.
//

#include "item.h"
#include "../player/player.h"
#include <iostream>

void medicine::benefit_player(player *p) {
  p->take_medicine(eff);
  std::cout << "You eat the medicine and gain " << eff << " hit point. " << std::endl;
}
