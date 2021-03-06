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

  Pos2d TargetedPedestrian::GetTarget(void) {
    return destination;
  }

} // end namespace
