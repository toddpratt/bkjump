#ifndef _HAVE_PLATFORM_H
#define _HAVE_PLATFORM_H

#include "draw_object.h"

class Platform : public DrawObject {
 public:
  Platform(int new_x, int new_y, int new_w, int new_h) :
      DrawObject(new_x, new_y, new_w, new_h) {}
  virtual void update();
  virtual void draw();
  virtual void handle_collision(DrawObject& other);
};

#endif  // _HAVE_PLATFORM_H
