/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  Author: John Duffy

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

  Vec2d Pedestrian::GetVelocity(void) const {
    return velocity;
  }
  
  Pos2d Pedestrian::GetPosition(void) const {
    return position;
  }

  void Pedestrian::SetVelocity(const Vec2d v) {
    velocity = v;
  }

  void Pedestrian::SetPosition(const Pos2d p) {
    position = p;
  }

  Vec2d Pedestrian::PedestrianDestinationAttractiveForce(void) {
    // Helbing & Molnar Equation 2.
    Vec2d direction {(destination - position) * (1.0 / (destination - position).Length())};
    return Vec2d {(direction * desired_speed - velocity) * (1.0 / relaxation_time)};
  }

} // end namespace
