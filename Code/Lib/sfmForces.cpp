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
#include "sfmForces.h"


namespace sfm {

  //dir2d PedestrianPedestrianReplusiveForce()
  //{
  //dir2d f;
  //return f;
  //}

  //dir2d ObstaclePedestrianRepulsiveForce()
  //{
  //dir2d f;
  //return f;
  //}

  //dir2d ResultantForce()
  //{
  //dir2d f;
  //return f;
  //}

  Vec2d ResultantForce(Pedestrian &p, std::vector<Pedestrian> pedestrians) {
    return p.PedestrianDestinationAttractiveForce();
  }

} // end namespace
