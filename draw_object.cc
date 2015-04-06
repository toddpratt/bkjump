#include "draw_object.h"

bool DrawObject::check_collision(const DrawObject& other) const {
  return ((get_x() >= other.get_x() && get_x() <= other.get_x2()) ||
           (get_x2() >= other.get_x() && get_x2() <= other.get_x2())) &&
         (((get_y() >= other.get_y() && get_y() <= other.get_y2()) ||
           (get_y2() >= other.get_y() && get_y2() <= other.get_y2())));
}

