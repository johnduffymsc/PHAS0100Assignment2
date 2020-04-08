/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "sfmTypes.h"
#include "sfmPedestrian.h"

#include <iostream>


namespace sfm {

  Pedestrian::Pedestrian(const Pos2d origin,
			 const Pos2d destination,
			 const double desired_speed,
			 const double relaxation_time)
    : origin{origin},
      destination{destination},
      desired_speed{desired_speed},
      relaxation_time{relaxation_time},
      velocity{Vec2d()},
      position{origin}
  {}

  Pedestrian::~Pedestrian() {}

  Vec2d Pedestrian::GetVelocity(void) {
    return velocity;
  }
  
  Pos2d Pedestrian::GetPosition(void) {
    return position;
  }

  void Pedestrian::SetVelocity(const Vec2d velocity) {
    this->velocity = velocity;
  }

  void Pedestrian::SetPosition(const Pos2d position) {
    this->position = position;
  }

  /*
  Vec2d Pedestrian::PedestrianDestinationAttractiveForce(void) {
    // Helbing & Molnar Equation 2.
    Vec2d e {(destination - position) * (1.0 / (destination - position).length())};
    Vec2d f {1.0 / relaxation_time * (desired_speed * e - velocity)};
    return f;
  }
  */

} // end namespace
