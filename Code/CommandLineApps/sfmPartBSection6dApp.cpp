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
#include <sfmPedestrianSpawner.h>

#include <iostream>


constexpr double FINISH_TIME_S {15.0};
constexpr double DT {0.25};
constexpr int N {10};


int main(int argc, char** argv)
{
  // Empty vector of pedestrians. Polymorphic - Can hold TargetedPedestrians or DirectionalPedestrians.
  sfm::VP ps;
  
  // Add N TargetedPedestrian(s) in a box at the x = 0 end, targeting the mid position of the x = POS2D_XWRAP end.
  for (auto p : sfm::PedestrianSpawner::CreateDistributed(N,
							  sfm::targeted,
							  sfm::Pos2d(0.0, 4.0),
							  sfm::Pos2d(2.0, 6.0),
							  sfm::Pos2d(POS2D_XWRAP, POS2D_YWRAP / 2.0))) {
    ps.push_back(p);
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
    for (auto i = 0; i < ps.size(); ++i) { // Need index i!

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
