#include <iostream>

#include "player.h"
#include "draw_object.h"

using std::cout;
using std::endl;

void Player::update() {
  old_x = x;
  x += get_xi() - get_xd();
  old_y = y;
  y += get_yi() - get_yd();
}

void Player::draw() {
}

void Player::handle_collision(DrawObject& other) {
  if(get_old_y2() < other.get_y()) {
    y = other.get_y() - h;
    set_yi(0);
    set_yd(0);
  } else if(old_y > other.get_y2()) {
    y = other.get_y2();
    int old_yi = yi;
    yi = yd;
    yd = old_yi;
  } else {
    int old_xi = xi;
    xi = xd;
    xd = old_xi;
    if(get_old_x2() < other.get_x()) {
      x = other.get_x() - w;
    } else if(old_x > other.get_x2()) {
      x = other.get_x() + other.get_w();
    }
  }
}
