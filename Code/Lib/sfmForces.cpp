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
#include "sfmForces.h"
#include "sfmPedestrian.h"

#include <cmath>
#include <memory>
#include <vector>


namespace sfm {

  double B(Vec2d r, Vec2d e, double v, double dt) {
    return 0.5 * std::sqrt(pow(r.Length() + (r - e * v * dt).Length(), 2.0) - pow(v * dt, 2.0));
  }

  double GradV(double b) {
    double V0 {2.1};
    double Sigma {0.3};
    return -1.0 * b / Sigma * V0 * exp(-1.0 * b / Sigma);
  }
	   
  Vec2d PedestrianPedestrianForce(std::shared_ptr<Pedestrian> p,
				  std::shared_ptr<Pedestrian> o,
				  double dt) {
    Vec2d r {p->GetPosition() - o->GetPosition()};
    Vec2d e {(o->GetDestination() - o->GetPosition()) * (1.0 / (o->GetDestination() - o->GetPosition()).Length())};
    double v {o->GetVelocity().Length()};
    double b {B(r, e, v, dt)};
    Vec2d direction {r * (1.0 / r.Length())};
    return direction * GradV(b) * -1.0;
  }

  double GradU(Vec2d r) {
    double U0 {10.0};
    double R {0.2};
    return -1.0 / R * U0 * exp(-1.0 * r.Length() / R);
  }
	   
  Vec2d PedestrianBorderForce(std::shared_ptr<Pedestrian> p, double y) {
    Vec2d r {p->GetPosition() - Pos2d(p->GetPosition().GetX(), y)};
    Vec2d direction {r * (1.0 / r.Length())};
    return direction * GradU(r) * -1.0;
  }
 
  Vec2d ResultantForce(std::shared_ptr<Pedestrian> p,
		       std::vector<std::shared_ptr<Pedestrian>> other_ps,
		       double dt) {
    Vec2d f {p->PedestrianDestinationForce()};
    for (auto o : other_ps) {
      f = f + PedestrianPedestrianForce(p, o, dt);
    }
    f = f + PedestrianBorderForce(p, 0.0);
    f = f + PedestrianBorderForce(p, POS2D_YWRAP);
    return f;
  }

} // end namespace
