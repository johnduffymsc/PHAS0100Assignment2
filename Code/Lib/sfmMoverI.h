/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef sfmMoverI_h
#define sfmMoverI_h


// An interface class for all things that move, e.g. a pedestrian or vehicle.

namespace sfm {

  class MoverI {
  public:
    virtual void print_velocity_and_position() = 0;
  };

} // end namespace

#endif
