/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model 

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef sfmPedestrian_h
#define sfmPedestrian_h

#include "sfmMoverI.h"
#include "sfmBasicTypes.h";


// A class that implements a pedestrian.

namespace sfm {

  class Pedestrian : public MoverI {
  public:
    Pedestrian(const pos2d origin,
	       const pos2d destination,
	       const double desired_speed,
	       const double relaxation_time);
    ~Pedestrian();
    void print_velocity_and_position();
  private:
    // Additional attributes to those declared in MoverI. 
    const double desired_speed;
    const double relaxation_time;
  };

} // end namespace

#endif
