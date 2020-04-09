/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  Author: John Duffy

=============================================================================*/

#ifndef sfmForces_h
#define sfmForces_h

#include "sfmTypes.h"
#include "sfmPedestrian.h"

#include <vector>


namespace sfm
{

  Vec2d PedestrianPedestrianRepulsiveForce(Pedestrian &p, std::vector<Pedestrian> other_ps);

  Vec2d Grad(const Vec2d r);

  double U(const double r_length);
    
  Vec2d BorderPedestrianRepulsiveForce(Pedestrian &p);

  Vec2d ResultantForce(Pedestrian &p, std::vector<Pedestrian> other_ps);

} // End namespace.

#endif
