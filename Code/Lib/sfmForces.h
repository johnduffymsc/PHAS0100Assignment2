/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  Author: John Duffy

=============================================================================*/

#ifndef sfmForces_h
#define sfmForces_h

#include "sfmTypes.h"
#include "sfmPedestrian.h"


namespace sfm
{
  double B(Vec2d r, Vec2d e, double v, double dt);

  double GradV(double b);
	   
  Vec2d PedestrianPedestrianForce(P p, P o, double dt);

  double GradU(Vec2d r);

  Vec2d PedestrianBorderForce(P p, double y);

  Vec2d ResultantForce(P p, VP other_ps, double dt);

} // End namespace.

#endif
