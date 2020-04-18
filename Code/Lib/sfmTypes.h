/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  Author: John Duffy

=============================================================================*/

#ifndef sfmTypes_h
#define sfmTypes_h

#ifndef POS2D_XWRAP
#define POS2D_XWRAP 50.0
#endif

#ifndef POS2D_YWRAP
#define POS2D_YWRAP 10.0
#endif


namespace sfm {

  // A class for 2D vectors, where the vector is defined by x and y lengths.
  
  class Vec2d {
  public:
    // Constructors.
    Vec2d();
    Vec2d(double x_length, double y_length);
    // Destructor.
    ~Vec2d();
    // Parameter value methods.
    Vec2d operator+(Vec2d v);
    Vec2d operator-(Vec2d v);
    Vec2d operator*(double scaling_factor);
    double Length(void);
    double GetXLength(void);
    double GetYLength(void);
  private:
    double x_length;
    double y_length;
  };
    
  // A class for 2D positions, where a position is defined by x and y values. 
  
  class Pos2d {
  public:
    // Constructors.
    Pos2d();
    Pos2d(double x, double y);
    // Destructor.
    ~Pos2d();
    // Parameter value methods.
    Pos2d operator+(Vec2d v);
    Vec2d operator-(Pos2d p);
    double GetX(void);
    double GetY(void);
  private:
    static double Wrap(double z, double max_z);
    double x;
    double y;
  };

} // End namespace.

#endif
