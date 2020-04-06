/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "sfmBasicTypes.h"
#include "sfmPedestrian.h"

#include <iostream>


// A class that implements a pedestrian.

namespace sfm {

  Pedestrian::Pedestrian(const pos2d origin,
			 const pos2d destination,
			 const double desired_speed,
			 const double relaxation_time)
    : origin(origin),
      destination(destination),
      desired_speed(desired_speed),
      relaxation_time(relaxation_time)
  {
    velocity = desired_speed;
    position = origin;
  }

  Pedestrian::~Pedestrian() {
  }

  void Pedestrian::print_velocity_and_position() {
    std::cout << velocity << std::endl;
  }

  void Pedestrian::move(dir2d& direction) {
    position = position + direction;
  }

  double Pedestrian::get_velocity(void) {
    return velocity;
  }
  
  pos2d Pedestrian::get_position(void) {
    return position;
  }

} // end namespace
