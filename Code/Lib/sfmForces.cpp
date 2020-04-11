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

  /*
  double b(Vec2d r, double v, Vec2d e, double dt) {
    return 0.5 * std::sqrt(pow(r.Length() + (r - e * v * dt).Length(), 2.0) - pow(v * dt, 2.0));
  }

  double V(double b) {
    return 0.0;
  }
  */
  
  Vec2d PedestrianPedestrianForce(Pedestrian &p, Pedestrian &o, double dt) {
    /*
    double V0 {2.1}
    double Sigma {0.3};
    double b {B(p.GetPosition() - o.GetPosition(),
		o.GetVelocity().Length(),
		(o.GetDestination() - o.GetPosition()) * (1.0 / (o.GetDestination() - o.GetPosition()).Length()),
		dt)};
    Vec2d f = -1.0 * -1.0 * b / Sigma * V0 * exp(-1.0 * b / Sigma);

    Vec2d direction {}
    
    return direction * GradV(b());
    */
    return Vec2d();
  }

  double GradU(Vec2d r) {
    double U0 {10.0};
    double R {0.2};
    return 1.0 / R * U0 * exp(-1.0 * r.Length() / R);
  }
	   
  Vec2d PedestrianBorderForce(Pedestrian &p, double y) {
    Vec2d r{p.GetPosition() - Pos2d(p.GetPosition().GetX(), y)};
    Vec2d direction {r * (1.0 / r.Length())};
    return direction * GradU(r) * -1.0;
  }
 
  Vec2d ResultantForce(Pedestrian &p, std::vector<Pedestrian> &other_ps, double dt) {
    Vec2d f {p.PedestrianDestinationForce()};
    for (auto o : other_ps) {
      f = f + PedestrianPedestrianForce(p, o, dt);
    }
    
    //f = f + BorderPedestrianForce(p.GetPosition() - Pos2d(p.GetPosition().GetX(), 0.0));
    //f = f + BorderPedestrianForce(p.GetPosition() - Pos2d(p.GetPosition().GetX(), POS2D_YWRAP));
    f = f + PedestrianBorderForce(p, 0.0);
    f = f + PedestrianBorderForce(p, POS2D_YWRAP);

    return f;
  }

} // end namespace
