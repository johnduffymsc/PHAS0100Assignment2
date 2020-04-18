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


constexpr double DESIRED_SPEED {1.3};
constexpr double RELAXATION_TIME {0.5};
constexpr double FINISH_TIME_S {40.0};
constexpr double DT {0.25};
constexpr int N {10};


int main(int argc, char** argv)
{
  // Create random y positions.
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> y(0.0, POS2D_YWRAP);

  // Empty vector of pedestrians.
  sfm::VP ps;

  // Add pedestrians with origin x = 0.0 and destination x = POS2D_XWRAP.
  for (auto i = 0; i < N; ++i) {
    sfm::Pos2d origin {0.0, y(gen)};
    sfm::Pos2d destination {POS2D_XWRAP, y(gen)};
    ps.push_back(std::make_shared<sfm::TargetedPedestrian>(origin,
							   destination,
							   DESIRED_SPEED,
							   RELAXATION_TIME));
  }
  
  // Add pedestrians with origin x = POS2D_XWRAP and destination x = 0.0.
  for (auto i = 0; i < N; ++i) {
    sfm::Pos2d origin {POS2D_XWRAP, y(gen)};
    sfm::Pos2d destination {0.0, y(gen)};
    ps.push_back(std::make_shared<sfm::TargetedPedestrian>(origin,
							   destination,
							   DESIRED_SPEED,
							   RELAXATION_TIME));
  }

  // Print velocities and positions at t = 0.0.
  std::cout << 0.0;
  for (auto &p : ps) {
    std::cout << " " << p->GetVelocity().GetXLength() << " " << p->GetVelocity().GetYLength();
    std::cout << " " << p->GetPosition().GetX() << " " << p->GetPosition().GetY();
  }
  std::cout << std::endl;

  // Time loop.
  for (auto t = DT; t < FINISH_TIME_S + DT; t += DT) {
    std::cout << t;

    // Pedestrians loop.
    for (auto i = 0; i < ps.size(); ++i) {
      // Create a vector of other pedestrians.
      sfm::VP other_ps = ps;
      other_ps.erase(other_ps.begin() + i);
      
      // Update each pedestrian's velocity.
      ps[i]->SetVelocity(ps[i]->GetVelocity() + (sfm::ResultantForce(ps[i], other_ps, DT) * DT));
      
      // Update each pedestrian's position.
      ps[i]->SetPosition(ps[i]->GetPosition() + (ps[i]->GetVelocity() * DT));
      
      // Print updated velocities and positions at time t.
      std::cout << " " << ps[i]->GetVelocity().GetXLength() << " " << ps[i]->GetVelocity().GetYLength();
      std::cout << " " << ps[i]->GetPosition().GetX() << " " << ps[i]->GetPosition().GetY();
    }
    
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}
