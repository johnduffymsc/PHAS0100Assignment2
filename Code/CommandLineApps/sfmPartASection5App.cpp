/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  Author: John Duffy

=============================================================================*/

#include <sfmExceptionMacro.h>
#include <sfmTypes.h>
#include <sfmForces.h>
#include <sfmPedestrian.h>
#include <sfmTargetedPedestrian.h>

#include <iostream>
#include <memory>
#include <random>
#include <vector>


int main(int argc, char** argv)
{
  // Create random y positions on the closed interval [0, POS2D_YWRAP].
  std::random_device rd;
  std::mt19937 gen(rd());
  double a {0.0};
  double b {std::nextafter(POS2D_YWRAP, std::numeric_limits<double>::max())}; // For closed interval.
  std::uniform_real_distribution<double> y(a, b);

  // Number of pedestrians to create at each end of the corridor.
  int n {10};

  // Common initial parameters for all pedestrians.
  double desired_speed {1.3};
  double relaxation_time {0.5};
  
  // Empty vector of pedestrians.
  std::vector<std::shared_ptr<sfm::Pedestrian>> ps;

  // Add pedestrians with origin x = 0.0 and destination x = POS2D_XWRAP.
  for (auto i = 0; i < n; ++i) {
    sfm::Pos2d origin {0.0, y(gen)};
    sfm::Pos2d destination {POS2D_XWRAP, y(gen)};
    ps.push_back(std::make_shared<sfm::TargetedPedestrian>(origin,
							   destination,
							   desired_speed,
							   relaxation_time));
  }
  
  // Add pedestrians with origin x = POS2D_XWRAP and destination x = 0.0.
  for (auto i = 0; i < n; ++i) {
    sfm::Pos2d origin {POS2D_XWRAP, y(gen)};
    sfm::Pos2d destination {0.0, y(gen)};
    ps.push_back(std::make_shared<sfm::TargetedPedestrian>(origin,
							   destination,
							   desired_speed,
							   relaxation_time));
  }

  // Print velocities and positions at t = 0.0.
  std::cout << 0.0;
  for (auto &p : ps) {
    std::cout << " " << p->GetVelocity().GetXLength() << " " << p->GetVelocity().GetYLength();
    std::cout << " " << p->GetPosition().GetX() << " " << p->GetPosition().GetY();
  }
  std::cout << std::endl;

  // Time loop.
  double finish_time_s {40.0};
  double dt {0.25};
  for (auto t = dt; t < finish_time_s + dt; t += dt) {
    std::cout << t;
    // Pedestrians loop.
    for (auto i = 0; i < ps.size(); ++i) { // Need index i!
      // Create a vector of other pedestrians.
      std::vector<std::shared_ptr<sfm::Pedestrian>> other_ps = ps;
      other_ps.erase(other_ps.begin() + i);
      // Update each pedestrian's velocity.
      ps[i]->SetVelocity(ps[i]->GetVelocity() + (sfm::ResultantForce(ps[i], other_ps, dt) * dt));
      // Update each pedestrian's position.
      ps[i]->SetPosition(ps[i]->GetPosition() + (ps[i]->GetVelocity() * dt));
      // Print updated velocities and positions at time t.
      std::cout << " " << ps[i]->GetVelocity().GetXLength() << " " << ps[i]->GetVelocity().GetYLength();
      std::cout << " " << ps[i]->GetPosition().GetX() << " " << ps[i]->GetPosition().GetY();
    }
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}
