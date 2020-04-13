/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model 

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  Author: John Duffy

=============================================================================*/

#ifndef sfmTargetedPedestrian_h
#define sfmTargetedPedestrian_h

#include "sfmWin32ExportHeader.h"

#include "sfmTypes.h"
#include "sfmPedestrian.h"


namespace sfm {

  class TargetedPedestrian : public Pedestrian {
  public:
    TargetedPedestrian(Pos2d origin, Pos2d destination, double desired_speed, double relaxation_time);

    ~TargetedPedestrian();

    Pos2d GetTarget(void);
  };

} // end namespace

#endif
