#include "gtest/gtest.h"
#include "player.h"
#include "platform.h"

TEST(PlayerTest, LeftToRightCollision) {
  Player player(145, 200, 50, 50);
  Platform platform(200, 200, 50, 50);
  player.set_xi(10);
  player.update();
  EXPECT_EQ(155, player.get_x());
  EXPECT_EQ(200, player.get_y());
  EXPECT_TRUE(player.check_collision(platform));
  player.handle_collision(platform);
  EXPECT_EQ(150, player.get_x());
  EXPECT_EQ(200, player.get_y());
}

TEST(PlayerTest, RightToLeftCollision) {
  Player player(255, 200, 50, 50);
  Platform platform(200, 200, 50, 50);
  player.set_xd(10);
  player.update();
  EXPECT_EQ(245, player.get_x());
  EXPECT_EQ(200, player.get_y());
  EXPECT_TRUE(player.check_collision(platform));
  player.handle_collision(platform);
  EXPECT_EQ(250, player.get_x());
  EXPECT_EQ(200, player.get_y());
}

TEST(PlayerTest, TopDownCollision) {
  Player player(200, 145, 50, 50);
  Platform platform(200, 200, 50, 50);
  player.set_yi(10);
  player.update();
  EXPECT_EQ(200, player.get_x());
  EXPECT_EQ(155, player.get_y());
  EXPECT_TRUE(player.check_collision(platform));
  player.handle_collision(platform);
  EXPECT_EQ(150, player.get_y());
}

TEST(PlayerTest, BottomUpCollision) {
  Player player(200, 255, 50, 50);
  Platform platform(200, 200, 50, 50);
  player.set_yd(10);
  player.update();
  EXPECT_EQ(200, player.get_x());
  EXPECT_EQ(245, player.get_y());
  EXPECT_TRUE(player.check_collision(platform));
  player.handle_collision(platform);
  EXPECT_EQ(250, player.get_y());
}

TEST(PlayerTest, LeftDownCollision) {
  Player player(145, 145, 50, 50);
  Platform platform(200, 200, 50, 50);
  player.set_xi(10);
  player.set_yi(10);
  player.update();
  EXPECT_EQ(155, player.get_x());
  EXPECT_EQ(155, player.get_y());
  EXPECT_TRUE(player.check_collision(platform));
  player.handle_collision(platform);
  EXPECT_EQ(155, player.get_x());
  EXPECT_EQ(150, player.get_y());
}

TEST(PlayerTest, RightDownCollision) {
  Player player(255, 145, 50, 50);
  Platform platform(200, 200, 50, 50);
  player.set_xd(10);
  player.set_yi(10);
  player.update();
  EXPECT_EQ(245, player.get_x());
  EXPECT_EQ(155, player.get_y());
  EXPECT_TRUE(player.check_collision(platform));
  player.handle_collision(platform);
  EXPECT_EQ(245, player.get_x());
  EXPECT_EQ(150, player.get_y());
}

TEST(PlayerTest, LeftUpCollision) {
  Player player(145, 255, 50, 50);
  Platform platform(200, 200, 50, 50);
  player.set_xi(10);
  player.set_yd(10);
  player.update();
  EXPECT_EQ(155, player.get_x());
  EXPECT_EQ(245, player.get_y());
  EXPECT_TRUE(player.check_collision(platform));
  player.handle_collision(platform);
  EXPECT_EQ(155, player.get_x());
  EXPECT_EQ(250, player.get_y());
}

TEST(PlayerTest, RightUpCollision) {
  Player player(255, 255, 50, 50);
  Platform platform(200, 200, 50, 50);
  player.set_xd(10);
  player.set_yd(10);
  player.update();
  EXPECT_EQ(245, player.get_x());
  EXPECT_EQ(245, player.get_y());
  EXPECT_TRUE(player.check_collision(platform));
  player.handle_collision(platform);
  EXPECT_EQ(245, player.get_x());
  EXPECT_EQ(250, player.get_y());
}
