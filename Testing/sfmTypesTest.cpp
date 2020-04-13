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

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <limits>

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
  REQUIRE(v.GetXLength() == -1.0 * half_world_x);
  REQUIRE(v.GetYLength() == -1.0 * half_world_y);

  v = half_world - full_world;
  REQUIRE(v.GetXLength() == half_world_x);
  REQUIRE(v.GetYLength() == half_world_y);

}
