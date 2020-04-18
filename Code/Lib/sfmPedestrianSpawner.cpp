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


constexpr double DESIRED_SPEED {1.3};
constexpr double RELAXATION_TIME {0.5};


namespace sfm {

  VP PedestrianSpawner::CreateUniform(int n, PedestrianType type, Pos2d destination) {
    return Factory(n, type, Pos2d(0.0, 0.0), Pos2d(POS2D_XWRAP, POS2D_YWRAP), destination);
  }
      
  VP PedestrianSpawner::CreateDistributed(int n, PedestrianType type, Pos2d origin_min, Pos2d origin_max, Pos2d destination) {
    return Factory(n, type, origin_min, origin_max, destination);
  }

  VP PedestrianSpawner::Factory(int n, PedestrianType type, Pos2d origin_min, Pos2d origin_max, Pos2d destination) {
    // Initialise random number generator.
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Create a random x values within the box.
    std::uniform_real_distribution<double> x(origin_min.GetX(), origin_max.GetX());
    
    // Create a random y values within the box.
    std::uniform_real_distribution<double> y(origin_min.GetY(), origin_max.GetY());
    
    // Create n pedestrians.
    VP ps;
    for (auto i = 0; i < n; ++i) {      
      if (type == targeted) {
	ps.push_back(std::make_shared<TargetedPedestrian>(Pos2d(x(gen), y(gen)),
							  destination,
							  DESIRED_SPEED,
							  RELAXATION_TIME));
      }
      if (type == directional) {
	ps.push_back(std::make_shared<DirectionalPedestrian>(Pos2d(x(gen), y(gen)),
							     destination,
							     DESIRED_SPEED,
							     RELAXATION_TIME));
      }
    }

    return ps;
  }

} // end namespace
