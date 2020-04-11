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

#include <cmath>


namespace sfm { // Start namespace.

  //
  // Class Vec2d - Vectors are defined by a (x_length, y_length) pair.
  //
  
  Vec2d::Vec2d(void) : x_length{0.0}, y_length{0.0} {};

  Vec2d::Vec2d(double x_length, double y_length) : x_length{x_length}, y_length{y_length} {};

  Vec2d::~Vec2d(void) {};

  Vec2d Vec2d::operator+(Vec2d v) {
    return Vec2d(x_length + v.x_length, y_length + v.y_length);
  }

  Vec2d Vec2d::operator-(Vec2d v) {
    return Vec2d(x_length + v.x_length, y_length + v.y_length) * -1.0;
  }

  Vec2d Vec2d::operator*(double scaling_factor) {
    return Vec2d(x_length * scaling_factor, y_length * scaling_factor);
  }

  double Vec2d::Length(void) {
    return std::sqrt(x_length * x_length + y_length * y_length);
  }

  double Vec2d::GetXLength(void) {
    return x_length;
  }

  double Vec2d::GetYLength(void) {
    return y_length;
  }

  //
  // Class Pos2d - Positions are defined by a (x, y) pair.
  //
  
  Pos2d::Pos2d(void) : x{0.0}, y{0.0} {};

  Pos2d::Pos2d(double x, double y) : x{Wrap(x, POS2D_XWRAP)}, y{Wrap(y, POS2D_YWRAP)} {};

  Pos2d::~Pos2d(void) {};

  Pos2d Pos2d::operator+(Vec2d v) {
    return Pos2d(Wrap(x + v.GetXLength(), POS2D_XWRAP), Wrap(y + v.GetYLength(), POS2D_YWRAP));
  }

  Vec2d Pos2d::operator-(Pos2d p) {
    return Vec2d(p.x - x, p.y - y);
  }

  double Pos2d::GetX(void) {
    return x;
  }

  double Pos2d::GetY(void) {
    return y;
  }

  double Pos2d::Wrap(double z, double max_z) { // Recursive method!
    if (z > max_z) {
      return Wrap(z - max_z, max_z);
    }
    if (z < 0.0) {
      return Wrap(z + max_z, max_z);
    } 
    return z; 
  }

} // End namespace.
