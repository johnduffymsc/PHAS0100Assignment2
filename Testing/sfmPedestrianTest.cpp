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
//#include "sfmMyFunctions.h"
#include "sfmTypes.h"
#include "sfmPedestrian.h"

//#include <iostream>
//#include <vector>


TEST_CASE("Pedestrian instantiation", "[pedestrian]" ) {

  // Create a pedestrian at the origin.
  const sfm::Pos2d origin;
  const sfm::Pos2d destination(POS2D_XWRAP, 0.0);
  const double desired_speed {1.0};
  const double relaxation_time {0.5};
  sfm::Pedestrian p(origin, destination, desired_speed, relaxation_time);

  // Test the instantiation of the pedestrian.
  REQUIRE(typeid(p) == typeid(sfm::Pedestrian));

  // Test the initial velocity is the desired velocity.
  REQUIRE(p.GetVelocity().GetXLength() == 0.0);
  REQUIRE(p.GetVelocity().GetYLength() == 0.0);

  // Test the pedestrian is at the origin.
  REQUIRE(p.GetPosition().GetX() == 0.0);
  REQUIRE(p.GetPosition().GetY() == 0.0);

}

TEST_CASE("Pedestrian instantiation wrapping", "[pedestrian]" ) {

  // Create a pedestrian outside of world.
  const sfm::Pos2d origin(POS2D_XWRAP + 1.0, POS2D_YWRAP + 1.0);
  const sfm::Pos2d destination(POS2D_XWRAP, 0.0);
  const double desired_speed {1.0};
  const double relaxation_time {0.5};
  sfm::Pedestrian p(origin, destination, desired_speed, relaxation_time);

  // Test the instantiation of the pedestrian.
  REQUIRE(typeid(p) == typeid(sfm::Pedestrian));

  // Test the initial velocity is the desired velocity.
  REQUIRE(p.GetVelocity().GetXLength() == 0.0);
  REQUIRE(p.GetVelocity().GetYLength() == 0.0);

  // Test the pedestrian is at (1.0, 1.0).
  REQUIRE(p.GetPosition().GetX() == 1.0);
  REQUIRE(p.GetPosition().GetY() == 1.0);

}

TEST_CASE("Pedestrian movement, including wrapping", "[pedestrian]" ) {

  // Create a pedestrian at the origin.
  const sfm::Pos2d origin;
  const sfm::Pos2d destination(POS2D_XWRAP, POS2D_YWRAP);
  const double desired_speed {1.0};
  double relaxation_time {0.5};
  sfm::Pedestrian p(origin, destination, desired_speed, relaxation_time);

  // Test the pedestrian is at the origin.
  REQUIRE(p.GetPosition().GetX() == 0.0);
  REQUIRE(p.GetPosition().GetY() == 0.0);

  // Create a vector half the world size in the x and y directions.
  sfm::Vec2d halfworld_xy(POS2D_XWRAP / 2.0, POS2D_YWRAP / 2.0);
  
  // Move half the world size.
  p.SetPosition(p.GetPosition() + halfworld_xy);
  REQUIRE(p.GetPosition().GetX() == POS2D_XWRAP / 2.0);
  REQUIRE(p.GetPosition().GetY() == POS2D_YWRAP / 2.0);

  // Move half the world size, again.
  p.SetPosition(p.GetPosition() + halfworld_xy);
  REQUIRE(p.GetPosition().GetX() == POS2D_XWRAP);
  REQUIRE(p.GetPosition().GetY() == POS2D_YWRAP);
  
  // Create a unit movement direction in the x and y directions.
  sfm::Vec2d unit_xy(1.0, 1.0);
  
  // Move a unit move to test wrapping.
  p.SetPosition(p.GetPosition() + unit_xy);
  REQUIRE(p.GetPosition().GetX() == 1.0);
  REQUIRE(p.GetPosition().GetY() == 1.0);

}

TEST_CASE("Pedestrian velocity/position setters/getters", "[pedestrian]" ) {

  // Create a pedestrian at the origin.
  const sfm::Pos2d origin;
  const sfm::Pos2d destination(POS2D_XWRAP, POS2D_YWRAP);
  const double desired_speed {1.0};
  double relaxation_time {0.5};
  sfm::Pedestrian pedestrian(origin, destination, desired_speed, relaxation_time);

  // Create a velocity vector.
  sfm::Vec2d vec2d(2.0, 2.0);

  // Setter/Getter.
  pedestrian.SetVelocity(vec2d);
  REQUIRE(pedestrian.GetVelocity().GetXLength() == 2.0);
  REQUIRE(pedestrian.GetVelocity().GetYLength() == 2.0);

  // Create a position.
  sfm::Pos2d pos2d(4.0, 4.0);

  // Setter/Getter.
  pedestrian.SetPosition(pos2d);
  REQUIRE(pedestrian.GetPosition().GetX() == 4.0);
  REQUIRE(pedestrian.GetPosition().GetY() == 4.0);

}


//TEST_CASE( "My second test", "[pedestrian]" ) {
//  std::vector<int> a;
//  REQUIRE( a.size() == 0 );
//}

//TEST_CASE( "Simple add", "[MyFirstAddFunction]") {
//  REQUIRE( sfm::MyFirstAddFunction(1, 2) == 3);
//}
