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

#include <cmath>
#include <vector>


namespace sfm {

  Vec2d PedestrianPedestrianForce(const Vec2d r) {
    return Vec2d();
  }

  Vec2d BorderPedestrianForce(const Vec2d r) {
    // Helbing & Molnar Equation 5.
    double U0 = 10.0;
    double R = 0.2;
    return Vec2d(0, -1.0 / R * U0 * exp(-1.0 * r.Length() / R)) * -1.0;
  }    
    
  Vec2d ResultantForce(Pedestrian &p, std::vector<Pedestrian> &other_ps) {
    Vec2d f {p.PedestrianDestinationForce()};
    for (auto o : other_ps) {
      f = f + PedestrianPedestrianForce(p.GetPosition() - o.GetPosition());
    }
    f = f + BorderPedestrianForce(p.GetPosition() - Pos2d(p.GetPosition().GetX(), 0.0));
    f = f + BorderPedestrianForce(p.GetPosition() - Pos2d(p.GetPosition().GetX(), POS2D_YWRAP));
    return f;
  }

} // end namespace
