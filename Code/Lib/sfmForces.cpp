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

  Vec2d PedestrianPedestrianRepulsiveForce(Pedestrian &p, std::vector<Pedestrian> other_ps) {
    return Vec2d();
  }

  Vec2d Grad(const Vec2d r) {
    //Vec2d grad {r * (1.0 / r.Length())};
    return Vec2d {r};
  }

  double U(const double r_length) {
    // Helbing & Molnar Equation 13.
    double U0 = 10.0;
    double R = 0.2;
    return -1.0 / R * U0 * exp(-1.0 * r_length / R);
  }    
    
  Vec2d BorderPedestrianRepulsiveForce(Pedestrian &p) {
    // Helbing & Molnar Equation 5.
    Vec2d r_top {p.GetPosition() - Pos2d(p.GetPosition().GetX(), POS2D_YWRAP)};
    Vec2d r_bottom {p.GetPosition() - Pos2d(p.GetPosition().GetX(), 0.0)};
    // Vector sum of top and bottom boundary forces.
    return Vec2d {Grad(r_bottom) * U(r_bottom.Length()) * -1.0 + Grad(r_top) * U(r_top.Length()) * -1.0};
  }

  Vec2d ResultantForce(Pedestrian &p, std::vector<Pedestrian> other_ps) {
    return
      p.PedestrianDestinationAttractiveForce() +
      PedestrianPedestrianRepulsiveForce(p, other_ps) +
      BorderPedestrianRepulsiveForce(p);
  }

} // end namespace
