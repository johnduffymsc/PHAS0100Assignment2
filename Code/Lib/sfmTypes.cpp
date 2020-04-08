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
  // Class Vec2d.
  //
  
  Vec2d::Vec2d(void) : x_length{0.0}, y_length{0.0} {};

  Vec2d::Vec2d(const double x_length, const double y_length) : x_length{x_length}, y_length{y_length} {};

  Vec2d::~Vec2d(void) {};

  Vec2d Vec2d::operator+(const Vec2d v) {
    return Vec2d(x_length + v.x_length, y_length + v.y_length);
  }

  Vec2d Vec2d::operator*(const double scaling_factor) {
    return Vec2d(x_length * scaling_factor, y_length * scaling_factor);
  }

  double Vec2d::Length(void) {
    return std::sqrt(x_length * x_length + y_length * y_length);
  }

  double Vec2d::GetXLength(void) const {
    return x_length;
  }

  double Vec2d::GetYLength(void) const {
    return y_length;
  }

  //
  // Class Pos2d.
  //
  
  Pos2d::Pos2d(void) : x{0.0}, y{0.0} {};

  Pos2d::Pos2d(const double x, const double y) : x{Wrap(x, POS2D_XWRAP)}, y{Wrap(y, POS2D_YWRAP)} {};

  Pos2d::~Pos2d(void) {};

  Pos2d Pos2d::operator+(const Vec2d v) {
    return Pos2d(Wrap(x + v.GetXLength(), POS2D_XWRAP), Wrap(y + v.GetYLength(), POS2D_YWRAP));
  }

  Vec2d Pos2d::operator-(const Pos2d p) {
    return Vec2d(p.x - x, p.y - y);
  }

  double Pos2d::GetX() const {
    return x;
  }

  double Pos2d::GetY() const {
    return y;
  }

  double Pos2d::Wrap(const double z, const double max_z) { // Recursive method!
    if (z / max_z > 1.0) {
      return Wrap(z - max_z, max_z);
    }
    return z; 
  }

} // End namespace.
