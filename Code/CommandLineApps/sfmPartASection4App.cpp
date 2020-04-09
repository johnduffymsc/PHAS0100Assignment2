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
#include <sfmPedestrian.h>
#include <sfmForces.h>

#include <iostream>
#include <vector>


int main(int argc, char** argv)
{
  // Number of pedestrians to create.
  int n {3};
  
  // Common initial parameters for pedestrians.
  const double desired_speed {1.3};
  const double relaxation_time {0.5};
  
  // Create a vector of pedestrians.
  std::vector<sfm::Pedestrian> pedestrians;
  for (auto i = 0; i < n; ++i) {
    const sfm::Pos2d origin(0.0, i + 1.0);
    const sfm::Pos2d destination(POS2D_XWRAP, i + 1.0);
    pedestrians.push_back(sfm::Pedestrian(origin, destination, desired_speed, relaxation_time));
  }

  // Print velocities and positions at t = 0.0.
  std::cout << 0.0;
  for (auto const &p : pedestrians) {
    std::cout << " " << p.GetVelocity().GetXLength() << " " << p.GetVelocity().GetYLength();
    std::cout << " " << p.GetPosition().GetX() << " " << p.GetPosition().GetY();
  }
  std::cout << std::endl;

  // Time loop.
  double finish_time_s {4.0};
  double dt {0.1};
  for (auto t = dt; t < finish_time_s + dt; t += dt) {
    std::cout << t;
    // Pedestrians loop.
    for (auto &p : pedestrians) {
      // Update each pedestrian's velocity.
      p.SetVelocity(p.GetVelocity() + (sfm::ResultantForce(p, pedestrians) * dt));
      // Update each pedestrian's position.
      p.SetPosition(p.GetPosition() + (p.GetVelocity() * dt));
      // Print updated velocities and positions at time t.
      std::cout << " " << p.GetVelocity().GetXLength() << " " << p.GetVelocity().GetYLength();
      std::cout << " " << p.GetPosition().GetX() << " " << p.GetPosition().GetY();
    }
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}


  /*
  int returnStatus = EXIT_FAILURE;

  try
  {

    Eigen::MatrixXd m(2,2);
    std::cout << "Printing 2x2 Eigen::MatrixXd ..." << std::endl << m << std::endl;

    std::cout << "Calculating ... " << sfm::MyFirstAddFunction(1, 2) << std::endl;

    returnStatus = EXIT_SUCCESS;
  }
  catch (sfm::Exception& e)
  {
    std::cerr << "Caught sfm::Exception: " << e.GetDescription() << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << "Caught std::exception: " << e.what() << std::endl;
  }

  return returnStatus;
  */

