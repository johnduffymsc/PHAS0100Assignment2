/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model 

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  Author: John Duffy

=============================================================================*/

#ifndef sfmPedestrianSpawner_h
#define sfmPedestrianSpawner_h

#include "sfmTypes.h"
#include "sfmPedestrian.h"
#include "sfmTargetedPedestrian.h"
#include "sfmDirectionalPedestrian.h"

#include <vector>


namespace sfm {

  class PedestrianSpawner {
  public:
    PedestrianSpawner();

    ~PedestrianSpawner();

    std::vector<Pedestrian> Uniform(int n);
      
    std::vector<Pedestrian> Distributed(int n, double x_start, double x_end, double y_start, double y_end);

  private:
    std::vector<Pedestrian> Factory(int n, double x_start, double x_end, double y_start, double y_end);
  };

} // end namespace

#endif
