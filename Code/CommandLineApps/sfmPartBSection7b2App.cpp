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

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

#include <omp.h>


constexpr double FINISH_TIME_S {15.0};
constexpr double DT {0.25};
constexpr int N {20};


int main(int argc, char** argv)
{
  // Start benchmark timers.
  auto t_start = std::chrono::high_resolution_clock::now();
  auto c_start = std::clock();
  
  // Empty vector of pedestrians.
  sfm::VP ps;
  
  // Add N TargetedPedestrian(s) in a box at the x = 0 end, targeting the mid point of the x = POS2D_XWRAP end.
  for (auto p : sfm::PedestrianSpawner::CreateDistributed(N,
							  sfm::targeted,
							  sfm::Pos2d(0.0, 4.0),
							  sfm::Pos2d(2.0, 6.0),
							  sfm::Pos2d(POS2D_XWRAP, POS2D_XWRAP / 2.0))) {
    ps.push_back(p);
  }

  // Add n DirectionalPedestrian(s) in a box at the x = POS2D_XWRAP end, targeting the mid point of the x = 0 end.
  for (auto p : sfm::PedestrianSpawner::CreateDistributed(N,
							  sfm::directional,
							  sfm::Pos2d(POS2D_XWRAP - 2.0, 4.0),
							  sfm::Pos2d(POS2D_XWRAP, 6.0),
							  sfm::Pos2d(0.0, POS2D_YWRAP / 2.0))) {
    ps.push_back(p);
  }
  
  // Time loop.
  for (auto t = DT; t < FINISH_TIME_S + DT; t += DT) {

    // Create a vector to store the resultant forces.
    std::vector<sfm::Vec2d> rs(ps.size());
    
    # pragma omp parallel for firstprivate(ps) firstprivate(DT)
    for (auto i = 0; i < ps.size(); ++i) {
      
      // Create a vector of other pedestrians.
      sfm::VP other_ps = ps;
      other_ps.erase(other_ps.begin() + i);
      
      // Update each pedestrian's velocity.
      rs[i] = sfm::ResultantForce(ps[i], other_ps, DT);

    }

    # pragma omp parallel for firstprivate(ps) firstprivate(DT) firstprivate(rs)
    for (auto i = 0; i < ps.size(); ++i) {

      // Update each pedestrian's velocity.
      ps[i]->SetVelocity(ps[i]->GetVelocity() + rs[i] * DT);
      
      // Update each pedestrian's position.
      ps[i]->SetPosition(ps[i]->GetPosition() + (ps[i]->GetVelocity() * DT));
      
    }

  }

  // Stop benchmark timers.
  auto t_stop = std::chrono::high_resolution_clock::now();
  auto c_stop = std::clock();

  // Determine Wall and CPU runtimes.
  std::cout << std::fixed
	    << std::setprecision(3)
	    << "CPU time:  "
	    << 1000.0 * (c_stop - c_start) / CLOCKS_PER_SEC << "ms"
	    << std::endl
	    << "Wall time: "
	    << std::chrono::duration<double, std::milli>(t_stop - t_start).count() << "ms"
	    << std::endl;

  return EXIT_SUCCESS;
}
