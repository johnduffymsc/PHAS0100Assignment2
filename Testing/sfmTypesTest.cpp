/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  Author: John Duffy

=============================================================================*/

#include "catch.hpp"
#include "sfmCatchMain.h"
#include "sfmTypes.h"


// Convenience variables.
double full_world_x {POS2D_XWRAP};
double full_world_y {POS2D_YWRAP};
double half_world_x {POS2D_XWRAP / 2.0};
double half_world_y {POS2D_YWRAP / 2.0};

TEST_CASE("Pos2d constructor", "[Pos2d]") {

  sfm::Pos2d origin;
  REQUIRE(typeid(origin) == typeid(sfm::Pos2d));
  REQUIRE(origin.GetX() == 0.0);
  REQUIRE(origin.GetY() == 0.0);

  sfm::Pos2d half_world(half_world_x, half_world_y);
  REQUIRE(typeid(half_world) == typeid(sfm::Pos2d));
  REQUIRE(half_world.GetX() == half_world_x);
  REQUIRE(half_world.GetY() == half_world_y);

  sfm::Pos2d full_world(full_world_x, full_world_y);
  REQUIRE(typeid(full_world) == typeid(sfm::Pos2d));
  REQUIRE(full_world.GetX() == full_world_x);
  REQUIRE(full_world.GetY() == full_world_y);

}

TEST_CASE("Pos2d constructor wrapping", "[Pos2d]") {

  // X positive wrap
  sfm::Pos2d x_positive_wrap(full_world_x + 1.0, 0.0);
  REQUIRE(typeid(x_positive_wrap) == typeid(sfm::Pos2d));
  REQUIRE(x_positive_wrap.GetX() == 1.0);
  REQUIRE(x_positive_wrap.GetY() == 0.0);

  // X negative wrap
  sfm::Pos2d x_negative_wrap(-1.0, 0.0);
  REQUIRE(typeid(x_negative_wrap) == typeid(sfm::Pos2d));
  REQUIRE(x_negative_wrap.GetX() == full_world_x - 1.0);
  REQUIRE(x_negative_wrap.GetY() == 0.0);

  // Y positive wrap
  sfm::Pos2d y_positive_wrap(0.0, full_world_y + 1.0);
  REQUIRE(typeid(y_positive_wrap) == typeid(sfm::Pos2d));
  REQUIRE(y_positive_wrap.GetX() == 0.0);
  REQUIRE(y_positive_wrap.GetY() == 1.0);

  // Y negative wrap
  sfm::Pos2d y_negative_wrap(0.0, -1.0);
  REQUIRE(typeid(y_negative_wrap) == typeid(sfm::Pos2d));
  REQUIRE(y_negative_wrap.GetX() == 0.0);
  REQUIRE(y_negative_wrap.GetY() == full_world_y - 1.0);

  // XY positive wrap
  sfm::Pos2d xy_positive_wrap(full_world_x + 1.0, full_world_y + 1.0);
  REQUIRE(typeid(xy_positive_wrap) == typeid(sfm::Pos2d));
  REQUIRE(xy_positive_wrap.GetX() == 1.0);
  REQUIRE(xy_positive_wrap.GetY() == 1.0);

  // XY negative wrap
  sfm::Pos2d xy_negative_wrap(-1.0, -1.0);
  REQUIRE(typeid(xy_negative_wrap) == typeid(sfm::Pos2d));
  REQUIRE(xy_negative_wrap.GetX() == full_world_x - 1.0);
  REQUIRE(xy_negative_wrap.GetY() == full_world_y - 1.0);

}

TEST_CASE("Pos2d + operator", "[Pos2d]") {

  sfm::Pos2d origin;
  sfm::Pos2d result;
  
  result = origin + sfm::Vec2d(1.0, 1.0);
  REQUIRE(result.GetX() == 1.0);
  REQUIRE(result.GetY() == 1.0);

  result = result + sfm::Vec2d(2.0, 2.0) * -1.0;
  REQUIRE(result.GetX() == full_world_x - 1.0);
  REQUIRE(result.GetY() == full_world_y - 1.0);

  result = result + sfm::Vec2d(1.0, 1.0);
  REQUIRE(result.GetX() == full_world_x);
  REQUIRE(result.GetY() == full_world_y);

}

TEST_CASE("Pos2d - operator", "[Pos2d]") {

  sfm::Pos2d full_world(full_world_x, full_world_y);
  sfm::Pos2d half_world(half_world_x, half_world_y);
  sfm::Vec2d v;
  
  v = full_world - half_world;
  REQUIRE(v.GetXLength() == half_world_x);
  REQUIRE(v.GetYLength() == half_world_y);

  v = half_world - full_world;
  REQUIRE(v.GetXLength() == -1.0 * half_world_x);
  REQUIRE(v.GetYLength() == -1.0 * half_world_y);

}

TEST_CASE("Vec2d constructor", "[Vec2d]") {

  sfm::Vec2d v_zero;
  REQUIRE(typeid(v_zero) == typeid(sfm::Vec2d));
  REQUIRE(v_zero.GetXLength() == 0.0);
  REQUIRE(v_zero.GetYLength() == 0.0);

  sfm::Vec2d x_unit(1.0, 0.0);
  REQUIRE(typeid(x_unit) == typeid(sfm::Vec2d));
  REQUIRE(x_unit.GetXLength() == 1.0);
  REQUIRE(x_unit.GetYLength() == 0.0);

  sfm::Vec2d y_unit(0.0, 1.0);
  REQUIRE(typeid(y_unit) == typeid(sfm::Vec2d));
  REQUIRE(y_unit.GetXLength() == 0.0);
  REQUIRE(y_unit.GetYLength() == 1.0);

  sfm::Vec2d xy_ones(1.0, 1.0);
  REQUIRE(typeid(xy_ones) == typeid(sfm::Vec2d));
  REQUIRE(xy_ones.GetXLength() == 1.0);
  REQUIRE(xy_ones.GetYLength() == 1.0);

  sfm::Vec2d xy_negative_ones(-1.0, -1.0);
  REQUIRE(typeid(xy_ones) == typeid(sfm::Vec2d));
  REQUIRE(xy_negative_ones.GetXLength() == -1.0);
  REQUIRE(xy_negative_ones.GetYLength() == -1.0);

}

TEST_CASE("Vec2d +/- operators", "[Vec2d]") {

  sfm::Vec2d a(3.0, 0.0);
  sfm::Vec2d b(0.0, 4.0);
  sfm::Vec2d c;

  c = a + b;
  REQUIRE(c.Length() == 5.0);
  REQUIRE(c.GetXLength() == 3.0);
  REQUIRE(c.GetYLength() == 4.0);

  c = c - a;
  REQUIRE(c.Length() == 4.0);
  REQUIRE(c.GetXLength() == 0.0);
  REQUIRE(c.GetYLength() == 4.0);

  c = c - b;
  REQUIRE(c.Length() == 0.0);
  REQUIRE(c.GetXLength() == 0.0);
  REQUIRE(c.GetYLength() == 0.0);

}

TEST_CASE("Vec2d * operator", "[Vec2d]") {

  sfm::Vec2d a(3.0, 4.0);
  REQUIRE(a.Length() == 5.0);

  a = a * 2.0;
  REQUIRE(a.Length() == 10.0);
  REQUIRE(a.GetXLength() == 6.0);
  REQUIRE(a.GetYLength() == 8.0);
  
  a = a * -0.5;
  REQUIRE(a.Length() == 5.0);
  REQUIRE(a.GetXLength() == -3.0);
  REQUIRE(a.GetYLength() == -4.0);

}
