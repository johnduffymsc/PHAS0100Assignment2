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
#include "sfmBasicTypes.h"


// A class that implements a pedestrian.

namespace sfm {

  class Pedestrian : public MoverI {
  public:
    Pedestrian(pos2d &origin, pos2d &destination, double &desired_speed, double &relaxation_time);

    ~Pedestrian();

    void move(dir2d &direction);

    dir2d get_velocity(void);
    
    pos2d get_position(void);
    
    void print_velocity_and_position();

  private:
    pos2d origin;
    pos2d destination;
    double desired_speed;
    double relaxation_time;
    dir2d velocity;
    pos2d position;
  };

} // end namespace

#endif
