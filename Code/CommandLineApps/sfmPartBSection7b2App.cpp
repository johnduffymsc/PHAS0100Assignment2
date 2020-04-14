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
#include <memory>
#include <string>
#include <vector>

#include <omp.h>


int main(int argc, char** argv)
{
  // Start benchmark timers.
  auto t_start = std::chrono::high_resolution_clock::now();
  auto c_start = std::clock();
  
  // Number of pedestrians to create at each end of the corridor.
  int n {20};

  // Empty vector of pedestrians.
  std::vector<std::shared_ptr<sfm::Pedestrian>> ps;
  
  // Add n TargetedPedestrian(s) in a box at the x = 0 end, targeting the x = POS2D_XWRAP end.
  for (auto p : sfm::PedestrianSpawner::Distributed(n, "targeted", 0.0, 2.0, 4.0, 6.0, POS2D_XWRAP)) {
    ps.push_back(p);
  }

  // Add n DirectionalPedestrian(s) in a box at the x = POS2D_XWRAP end, targeting the x = 0 end.
  for (auto p : sfm::PedestrianSpawner::Distributed(n, "directional", POS2D_XWRAP - 2.0, POS2D_XWRAP, 4.0, 6.0, 0.0)) {
    ps.push_back(p);
  }
  
  // Print velocities and positions at t = 0.0.
  //std::cout << 0.0;
  //for (auto &p : ps) {
  //  std::cout << " " << p->GetVelocity().GetXLength() << " " << p->GetVelocity().GetYLength();
  //  std::cout << " " << p->GetPosition().GetX() << " " << p->GetPosition().GetY();
  //}
  //std::cout << std::endl;

  // Time loop.
  double finish_time_s {15.0};
  double dt {0.25};  
  for (auto t = dt; t < finish_time_s + dt; t += dt) {
    //std::cout << t;
    // Pedestrians loop.

    // Create a vector to store the resultant forces.
    std::vector<sfm::Vec2d> rs(ps.size());
    
    // Disable dynamic teams.
    omp_set_dynamic(0);

# pragma omp parallel for
    for (auto i = 0; i < ps.size(); ++i) {
      
      // Create a vector of other pedestrians.
      std::vector<std::shared_ptr<sfm::Pedestrian>> other_ps = ps;
      other_ps.erase(other_ps.begin() + i);
      
      // Update each pedestrian's velocity.
      rs[i] = sfm::ResultantForce(ps[i], other_ps, dt);

    }

# pragma omp parallel for
    for (auto i = 0; i < ps.size(); ++i) {

      // Update each pedestrian's velocity.
      ps[i]->SetVelocity(ps[i]->GetVelocity() + rs[i] * dt);
      
      // Update each pedestrian's position.
      ps[i]->SetPosition(ps[i]->GetPosition() + (ps[i]->GetVelocity() * dt));
      
      // Print updated velocities and positions at time t.
      //std::cout << " " << ps[i]->GetVelocity().GetXLength() << " " << ps[i]->GetVelocity().GetYLength();
      //std::cout << " " << ps[i]->GetPosition().GetX() << " " << ps[i]->GetPosition().GetY();
    }
    //std::cout << std::endl;
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
