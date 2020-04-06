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

TEST_CASE("Pedestrian instance", "[pedestrian]" ) {
  const sfm::pos2d origin(0.0, 1.0);
  const sfm::pos2d destination(POS2D_XWRAP - 0.01, 1.0);
  const double desired_speed {1.3};
  const double relaxation_time {0.5};
  sfm::Pedestrian pedestrian(origin, destination, desired_speed, relaxation_time);
  REQUIRE(1 == 1);
  //REQUIRE(pedestrian.get_y_wrap == );
  //REQUIRE(pedestrian.get_x_wrap == );
  //REQUIRE(pedestrian.get_x_wrap == );
  //REQUIRE(pedestrian.get_x_wrap == );
  //REQUIRE(pedestrian.relaxation == );
}

//TEST_CASE( "My second test", "[pedestrian]" ) {
//  std::vector<int> a;
//  REQUIRE( a.size() == 0 );
//}

//TEST_CASE( "Simple add", "[MyFirstAddFunction]") {
//  REQUIRE( sfm::MyFirstAddFunction(1, 2) == 3);
//}
