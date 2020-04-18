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


namespace sfm {

  enum PedestrianType {targeted, directional};
    
  class PedestrianSpawner {
  public:
    static VP CreateUniform(int n, PedestrianType type, Pos2d destination);
      
    static VP CreateDistributed(int n, PedestrianType type, Pos2d origin_min, Pos2d origin_max, Pos2d destination);

  private:
    static VP Factory (int n, PedestrianType type, Pos2d origin_min, Pos2d origin_max, Pos2d destination);
  };

} // end namespace

#endif
