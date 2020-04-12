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

#include <iostream>


namespace sfm {

  PedestrianSpawner::PedestrianSpawner() {}

  PedestrianSpawner::~PedestrianSpawner() {}

  std::vector<Pedestrian> PedestrianSpawner::Uniform(int n) {
    return Factory(n, 0.0, POS2D_XWRAP, 0.0, POS2D_YWRAP);
  }
      
  std::vector<Pedestrian> PedestrianSpawner::Distributed(int n, double x_start, double x_end, double y_start, double y_end) {
    return Factory(n, x_start, x_end, y_start, y_end);
  }

  std::vector<Pedestrian> PedestrianSpawner::Factory(int n, double x_start, double x_end, double y_start, double y_end) {

  // Create random y positions on the closed interval [0, POS2D_YWRAP].
  std::random_device rd;
  std::mt19937 gen(rd());
  double a {0.0};
  double b {std::nextafter(POS2D_YWRAP, std::numeric_limits<double>::max())}; // For closed interval.
  std::uniform_real_distribution<double> y(a, b);






    ;
  }

} // end namespace
