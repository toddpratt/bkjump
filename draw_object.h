#ifndef _HAVE_BASE_OBJECT_H
#define _HAVE_BASE_OBJECT_H

class DrawObject {

 protected:
  int x;
  int y;
  int w;
  int h;

  int xi;  // increment
  int xd;  // decrement
  int yi;
  int yd;

  int old_x;
  int old_y;

 public:
  DrawObject(int new_x, int new_y, int new_w, int new_h) :
      x(new_x), y(new_y), w(new_w), h(new_h),
      xi(0), xd(0), yi(0), yd(0),
      old_x(0), old_y(0) {}

  int get_x() const { return x; }
  int get_y() const { return y; }
  int get_w() const { return w; }
  int get_h() const { return h; }
  int get_x2() const { return x + w; }
  int get_y2() const { return y + h; }

  int get_old_x() { return old_x; }
  int get_old_y() { return old_y; }
  int get_old_x2() { return old_x + w; }
  int get_old_y2() { return old_y + h; }

  int get_xi() const { return xi; }
  int get_xd() const { return xd; }
  int get_yi() const { return yi; }
  int get_yd() const { return yd; }

  void set_xi(int n) { xi = n; };
  void set_xd(int n) { xd = n; };
  void set_yi(int n) { yi = n; };
  void set_yd(int n) { yd = n; };

  bool check_collision(const DrawObject& other) const;

  virtual void update() = 0;
  virtual void draw() = 0;
  virtual void handle_collision(DrawObject& other) = 0;
};

#endif  // _HAVE_BASE_OBJECT_H
