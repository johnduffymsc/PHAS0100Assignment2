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
#include "sfmTargetedPedestrian.h"

#include <iostream>


namespace sfm {

  TargetedPedestrian::TargetedPedestrian(Pos2d origin, Pos2d destination, double desired_speed, double relaxation_time)
    : Pedestrian(origin, destination, desired_speed, relaxation_time) {}

  TargetedPedestrian::~TargetedPedestrian() {}

  /*
  Pos2d Pedestrian::GetOrigin(void) {
    return origin;
  }

  Pos2d Pedestrian::GetDestination(void) {
    return destination;
  }

  Vec2d Pedestrian::GetVelocity(void)  {
    return velocity;
  }
  
  Pos2d Pedestrian::GetPosition(void) {
    return position;
  }

  void Pedestrian::SetVelocity(Vec2d v) {
    velocity = v;
  }

  void Pedestrian::SetPosition(Pos2d p) {
    position = p;
  }

  Vec2d Pedestrian::PedestrianDestinationForce(void) {
    // Helbing & Molnar Equation 2.
    Vec2d direction {(destination - position) * (1.0 / (destination - position).Length())};
    return Vec2d {(direction * desired_speed - velocity) * (1.0 / relaxation_time)};
  }
  */

  Pos2d TargetedPedestrian::GetTarget(void) {
    return Pos2d();
  }

} // end namespace
