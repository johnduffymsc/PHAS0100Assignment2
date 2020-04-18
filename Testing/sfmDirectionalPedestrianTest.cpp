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
#include "sfmDirectionalPedestrian.h"


constexpr double DESIRED_SPEED {1.0};
constexpr double RELAXATION_TIME {0.5};


TEST_CASE("DirectionalPedestrian instantiation", "[DirectionalPedestrian]" ) {

  // Create a pedestrian at the origin.
  sfm::Pos2d origin;
  sfm::Pos2d destination(POS2D_XWRAP, 0.0);
  sfm::DirectionalPedestrian p(origin, destination, DESIRED_SPEED, RELAXATION_TIME);

  // Test the instantiation of the pedestrian.
  REQUIRE(typeid(p) == typeid(sfm::DirectionalPedestrian));

  // Test the initial velocity is the desired velocity.
  REQUIRE(p.GetVelocity().GetXLength() == 0.0);
  REQUIRE(p.GetVelocity().GetYLength() == 0.0);

  // Test the pedestrian is at the origin.
  REQUIRE(p.GetPosition().GetX() == 0.0);
  REQUIRE(p.GetPosition().GetY() == 0.0);

}

TEST_CASE("DirectionalPedestrian instantiation wrapping", "[DirectionalPedestrian]" ) {

  // Create a pedestrian outside of world.
  sfm::Pos2d origin(POS2D_XWRAP + 1.0, POS2D_YWRAP + 1.0);
  sfm::Pos2d destination(POS2D_XWRAP, 0.0);
  sfm::DirectionalPedestrian p(origin, destination, DESIRED_SPEED, RELAXATION_TIME);

  // Test the instantiation of the pedestrian.
  REQUIRE(typeid(p) == typeid(sfm::DirectionalPedestrian));

  // Test the initial velocity is the desired velocity.
  REQUIRE(p.GetVelocity().GetXLength() == 0.0);
  REQUIRE(p.GetVelocity().GetYLength() == 0.0);

  // Test the pedestrian is at (1.0, 1.0).
  REQUIRE(p.GetPosition().GetX() == 1.0);
  REQUIRE(p.GetPosition().GetY() == 1.0);

}

TEST_CASE("DirectionalPedestrian movement, including wrapping", "[DirectionalPedestrian]" ) {

  // Create a pedestrian at the origin.
  sfm::Pos2d origin;
  sfm::Pos2d destination(POS2D_XWRAP, POS2D_YWRAP);
  sfm::DirectionalPedestrian p(origin, destination, DESIRED_SPEED, RELAXATION_TIME);

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

TEST_CASE("DirectionalPedestrian velocity/position setters/getters", "[DirectionalPedestrian]" ) {

  // Create a pedestrian at the origin.
  sfm::Pos2d origin;
  sfm::Pos2d destination(POS2D_XWRAP, POS2D_YWRAP);
  sfm::DirectionalPedestrian p(origin, destination, DESIRED_SPEED, RELAXATION_TIME);

  // Create a velocity vector.
  sfm::Vec2d vec2d(2.0, 2.0);

  // Setter/Getter.
  p.SetVelocity(vec2d);
  REQUIRE(p.GetVelocity().GetXLength() == 2.0);
  REQUIRE(p.GetVelocity().GetYLength() == 2.0);

  // Create a position.
  sfm::Pos2d pos2d(4.0, 4.0);

  // Setter/Getter.
  p.SetPosition(pos2d);
  REQUIRE(p.GetPosition().GetX() == 4.0);
  REQUIRE(p.GetPosition().GetY() == 4.0);

}
