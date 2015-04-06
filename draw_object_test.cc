#include "gtest/gtest.h"
#include "draw_object.h"

class TestObject : public DrawObject {

 public:

  TestObject(int new_x, int new_y, int new_w, int new_h) :
      DrawObject(new_x, new_y, new_w, new_h) {}

  virtual void update() {}
  virtual void draw() {}
  virtual void handle_collision(DrawObject& other) {}

};

TEST(DrawObjectTest, SettersAndGetters) {
  TestObject test(1, 2, 3, 4);
  EXPECT_EQ(test.get_x(), 1);
  EXPECT_EQ(test.get_y(), 2);
  EXPECT_EQ(test.get_w(), 3);
  EXPECT_EQ(test.get_h(), 4);
  EXPECT_EQ(test.get_x2(), 4);
  EXPECT_EQ(test.get_y2(), 6);

  test.set_xi(22);
  test.set_xd(23);
  test.set_yi(24);
  test.set_yd(25);

  EXPECT_EQ(test.get_xi(), 22);
  EXPECT_EQ(test.get_xd(), 23);
  EXPECT_EQ(test.get_yi(), 24);
  EXPECT_EQ(test.get_yd(), 25);
}

TEST(DrawObjectTest, CollidesWith) {
  TestObject test1(110, 100, 50, 50), test2(150, 100, 50, 50);
  EXPECT_TRUE(test1.check_collision(test2));
  EXPECT_TRUE(test2.check_collision(test1));
}

TEST(DrawObjectTest, NotCollidesWith) {
  TestObject test1(10, 10, 20, 20), test2(55, 55, 25, 25);
  EXPECT_TRUE(!test1.check_collision(test2));
  EXPECT_TRUE(!test2.check_collision(test1));
}
