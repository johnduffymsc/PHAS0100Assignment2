/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef sfmForces_h
#define sfmForces_h

#include "sfmBasicTypes.h"
#include "sfmPedestrian.h"

#include <vector>


namespace sfm
{

  //dir2d PedestrianPedestrianRepulsiveForce();

  //dir2d ObstaclePedestrianRepulsiveForce();

  
  dir2d ResultantForce(Pedestrian p, std::vector<Pedestrian> others);
  
}

#endif
