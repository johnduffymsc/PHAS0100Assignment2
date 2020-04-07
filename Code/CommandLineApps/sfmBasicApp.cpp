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
#include <vector>


int main(int argc, char** argv)
{
  // Number of pedestrians to create.
  int n {3};
  
  // Standard initial parameters for pedestrians.
  double desired_speed {1.3};
  double relaxation_time {0.5};
  
  // Create a vector of pedestrians.
  std::vector<sfm::Pedestrian> pedestrians;
  for (auto i = 0; i < n; ++i) {
    sfm::pos2d origin(0.0, i + 1.0);
    sfm::pos2d destination(POS2D_XWRAP - 0.01, i + 1.0);
    pedestrians.push_back(sfm::Pedestrian(origin, destination, desired_speed, relaxation_time));
  }

  // Time loop.
  double finish_time_s {60.0};
  double dt {0.5};
  for (auto t = 0.0; t < finish_time_s; t += dt) {
    // Pedestriations loop.
    for (auto pedestrian : pedestrians) {
      std::cout << t << std::endl;
    }
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

