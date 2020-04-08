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

#include "sfmTypes.h"


namespace sfm {

  class Pedestrian {
  public:
    Pedestrian(const Pos2d origin,
	       const Pos2d destination,
	       const double desired_speed,
	       const double relaxation_time);

    ~Pedestrian();

    Vec2d GetVelocity(void);
    Pos2d GetPosition(void);

    void SetVelocity(const Vec2d velocity);
    void SetPosition(const Pos2d position);

    //Vec2d PedestrianDestinationAttractiveForce(void);
    
  private:
    const Pos2d origin;
    const Pos2d destination;
    const double desired_speed;
    const double relaxation_time;
    Vec2d velocity;
    Pos2d position;
  };

} // end namespace

#endif
