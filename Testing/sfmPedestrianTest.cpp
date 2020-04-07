/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "sfmCatchMain.h"
//#include "sfmMyFunctions.h"
#include "sfmBasicTypes.h"
#include "sfmPedestrian.h"

//#include <iostream>
//#include <vector>


TEST_CASE("Pedestrian instantiation", "[pedestrian]" ) {

  // Create a pedestrian at the origin.
  sfm::pos2d origin(0.0, 0.0);
  sfm::pos2d destination(POS2D_XWRAP - 0.01, 0.0);
  double desired_speed {1.0};
  double relaxation_time {0.5};
  sfm::Pedestrian pedestrian(origin, destination, desired_speed, relaxation_time);

  // Test the instantiation of the pedestrian.
  REQUIRE(typeid(pedestrian) == typeid(sfm::Pedestrian));

  // Test the initial velocity is the desired velocity.
  //REQUIRE(pedestrian.get_velocity() == 1.0);

  // Test the pedestrian is at the origin.
  REQUIRE(pedestrian.get_position().x() == 0.0);
  REQUIRE(pedestrian.get_position().y() == 0.0);

}


TEST_CASE("Pedestrian movement, including wrapping", "[pedestrian]" ) {

  // Create a pedestrian at the origin.
  sfm::pos2d origin(0.0, 0.0);
  sfm::pos2d destination(POS2D_XWRAP - 0.01, 1.0);
  double desired_speed {1.0};
  double relaxation_time {0.5};
  sfm::Pedestrian pedestrian(origin, destination, desired_speed, relaxation_time);

  // Test the pedestrian is at the origin.
  REQUIRE(pedestrian.get_position().x() == 0.0);
  REQUIRE(pedestrian.get_position().y() == 0.0);

  // Create a movement direction half the world size in the x and y directions.
  sfm::dir2d halfworld_xy(POS2D_XWRAP / 2.0, POS2D_YWRAP / 2.0);
  
  // Move half the world size, and test the result.
  pedestrian.move(halfworld_xy);
  REQUIRE(pedestrian.get_position().x() == POS2D_XWRAP / 2.0);
  REQUIRE(pedestrian.get_position().y() == POS2D_YWRAP / 2.0);

  // Move half the world size, again, and test the pedestrian wraps back to the origin.
  pedestrian.move(halfworld_xy);
  REQUIRE(pedestrian.get_position().x() == 0.0);
  REQUIRE(pedestrian.get_position().y() == 0.0);
  
  // Create a unit movement direction in the x and y directions.
  sfm::dir2d unit_xy(1.0, 1.0);
  
  // Move half the world size, and test the result.
  pedestrian.move(halfworld_xy);
  REQUIRE(pedestrian.get_position().x() == POS2D_XWRAP / 2.0);
  REQUIRE(pedestrian.get_position().y() == POS2D_YWRAP / 2.0);

  // Move a unit move, and test the result.
  pedestrian.move(unit_xy);
  REQUIRE(pedestrian.get_position().x() == POS2D_XWRAP / 2.0 + 1.0);
  REQUIRE(pedestrian.get_position().y() == POS2D_YWRAP / 2.0 + 1.0);

  // Move half the world size, again, and test the pedestrian wraps to (1.0, 1.0).
  pedestrian.move(halfworld_xy);
  REQUIRE(pedestrian.get_position().x() == 1.0);
  REQUIRE(pedestrian.get_position().y() == 1.0);

}


//TEST_CASE( "My second test", "[pedestrian]" ) {
//  std::vector<int> a;
//  REQUIRE( a.size() == 0 );
//}

//TEST_CASE( "Simple add", "[MyFirstAddFunction]") {
//  REQUIRE( sfm::MyFirstAddFunction(1, 2) == 3);
//}
