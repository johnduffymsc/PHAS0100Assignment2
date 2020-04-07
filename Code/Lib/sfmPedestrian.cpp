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

  Pedestrian::Pedestrian(pos2d &origin, pos2d &destination, double &desired_speed, double &relaxation_time)
    : origin{origin},
      destination{destination},
      desired_speed{desired_speed},
      relaxation_time{relaxation_time},
      velocity{(destination - origin)},
      position{origin}
  {}

  Pedestrian::~Pedestrian() {}

  void Pedestrian::move(dir2d &direction) {
    position = position + direction;
  }

  dir2d Pedestrian::get_velocity(void) {
    return velocity;
  }
  
  pos2d Pedestrian::get_position(void) {
    return position;
  }

  void Pedestrian::print_velocity_and_position() {
    //std::cout << velocity << " " << get_position().x() << " " << get_position().y() << std::endl;
    ;
  }

} // end namespace
