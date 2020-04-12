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

  class PedestrianSpawner {
  public:
    PedestrianSpawner(Pos2d origin, Pos2d destination, double desired_speed, double relaxation_time);

    ~PedestrianSpawner();

    /*
    Pos2d GetOrigin(void);
    Pos2d GetDestination(void);
    Vec2d GetVelocity(void);
    Pos2d GetPosition(void);

    void SetVelocity(Vec2d velocity);
    void SetPosition(Pos2d position);

    Vec2d PedestrianDestinationForce(void);
    */
    
  private:
    /*
    Pos2d origin;
    Pos2d destination;
    double desired_speed;
    double relaxation_time;
    Vec2d velocity;
    Pos2d position;
    */
  };

} // end namespace

#endif
