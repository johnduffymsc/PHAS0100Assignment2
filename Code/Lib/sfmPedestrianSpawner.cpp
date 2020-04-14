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
#include "sfmTargetedPedestrian.h"
#include "sfmDirectionalPedestrian.h"
#include "sfmPedestrianSpawner.h"

#include <random>
#include <memory>
#include <string>
#include <vector>


namespace sfm {

  std::vector<std::shared_ptr<Pedestrian>> PedestrianSpawner::Uniform(int n,
								      std::string type,
								      double x_target) {
    return Factory(n, type, 0.0, POS2D_XWRAP, 0.0, POS2D_YWRAP, x_target);
  }
      
  std::vector<std::shared_ptr<Pedestrian>> PedestrianSpawner::Distributed(int n,
									  std::string type,
									  double x_start,
									  double x_end,
									  double y_start,
									  double y_end,
									  double x_target) {
    return Factory(n, type, x_start, x_end, y_start, y_end, x_target);
  }

  std::vector<std::shared_ptr<Pedestrian>> PedestrianSpawner::Factory(int n,
								      std::string type,
								      double x_start,
								      double x_end,
								      double y_start,
								      double y_end,
								      double x_target) {
    // Initialise random number generator.
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Create random x box positions on the closed interval [x_start, x_end].
    std::uniform_real_distribution<double> x(x_start,
					     std::nextafter(x_end, std::numeric_limits<double>::max()));
    
    // Create random y box positions on the closed interval [y_start, y_end].
    std::uniform_real_distribution<double> y(y_start,
					     std::nextafter(y_end, std::numeric_limits<double>::max()));
    
    // Create random y target positions on the closed interval [0.0, POS2D_YWRAP].
    std::uniform_real_distribution<double> y_target(0.0,
						    std::nextafter(POS2D_YWRAP, std::numeric_limits<double>::max()));

    // Create n pedestrians.
    std::vector<std::shared_ptr<Pedestrian>> ps;
    for (auto i = 0; i < n; ++i) {
      
      // Common initial parameters.
      double desired_speed {1.3};
      double relaxation_time {0.5};

      // Spawn TargetedPedestrian(s) or DirectionalPedestrian(s).
      if (type == "targeted") {
	// Spawn TargetedPedestrians.
	ps.push_back(std::make_shared<TargetedPedestrian>(Pos2d(x(gen), y(gen)),
							  Pos2d(x_target, y_target(gen)),
							  desired_speed,
							  relaxation_time));
      }
      else if (type == "directional") {
	// Spawn DirectionalPedestrians.
	ps.push_back(std::make_shared<DirectionalPedestrian>(Pos2d(x(gen), y(gen)),
							     Pos2d(x_target, y_target(gen)),
							     desired_speed,
							     relaxation_time));
      }
      else {
	// Spawn TargetedPedestrians as the default.
	ps.push_back(std::make_shared<TargetedPedestrian>(Pos2d(x(gen), y(gen)),
							  Pos2d(x_target, y_target(gen)),
							  desired_speed,
							  relaxation_time));
      }
    }
    return ps;
  }

} // end namespace
