/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <sfmExceptionMacro.h>
#include <sfmBasicTypes.h>
#include <sfmPedestrian.h>

#include <iostream>
#include <random>
#include <vector>


int main(int argc, char** argv)
{
  // Number of pedestrians to create at each end of the corridor.
  int n {20};

  // Initial configuration for all pedestrians.
  double desired_speed {1.3};
  double relaxation_time {0.5};
  
  // Empty vector of pedestrians.
  std::vector<sfm::Pedestrian> pedestrians;

  // Create random y positions on the closed interval [0, POS2D_YWRAP].
  std::random_device rd;
  std::mt19937 gen(rd());
  double a {0.0};
  double b {std::nextafter(POS2D_YWRAP, std::numeric_limits<double>::max())}; // For closed interval.
  std::uniform_real_distribution<double> y(a, b);

  // Add pedestrians starting at x = 0.
  for (auto i = 0; i < n; ++i) {
    sfm::pos2d origin {0, y(gen)};
    sfm::pos2d destination {POS2D_XWRAP - 0.1, y(gen)};
    pedestrians.push_back(sfm::Pedestrian(origin,
					  destination,
					  desired_speed,
					  relaxation_time));
  }
  
  // Add pedestrians starting at x = POS2D_XWRAP.
  for (auto i = 0; i < n; ++i) {
    sfm::pos2d origin {POS2D_XWRAP - 0.1, y(gen)};
    sfm::pos2d destination {0.1, y(gen)};
    pedestrians.push_back(sfm::Pedestrian(origin,
					  destination,
					  desired_speed,
					  relaxation_time));
  }


  for (auto p : pedestrians) {
    std::cout << p.GetPosition().x() << " " << p.GetPosition().y() << std::endl;
  }

  
  /*
  // Create a vector of pedestrians.
  std::vector<sfm::Pedestrian> pedestrians;
  for (auto i = 0; i < n; ++i) {
    sfm::pos2d origin(0.0, i + 1.0);
    sfm::pos2d destination(POS2D_XWRAP - 0.01, i + 1.0);
    pedestrians.push_back(sfm::Pedestrian(origin, destination, desired_speed, relaxation_time));
  }
  */


  /*
  // Time loop.
  double finish_time_s {60.0};
  double dt {0.5};
  for (auto t = 0.0; t < finish_time_s; t += dt) {
    // Pedestrians loop.
    for (auto p : pedestrians) {
      // Calculate resultant force.
      sfm::dir2d resultant_force = p.PedestrianDestinationAttractiveForce();
      // Update pedestrian's velocity.
      p.SetVelocity(p.GetVelocity() + ResultantForce(p) * dt);
      // Update pedestrian's position.
      p.SetPosition(p.GetPosition() + p.GetVelocity() * dt);

      
      std::cout << t << std::endl;
    }
  }
  */

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

