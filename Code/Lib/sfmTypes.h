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


namespace sfm { // Start namespace.

  // TODO: Implement the XPPair class as a base class for Vec2d and Pos2d.
  
  /*
  //
  // Class XYPair.
  //

  class XYPair {
  public:
    // Constructors.
    XYPair();
    XYPair(const double x, const double y);
    // Destructor.
    ~XYPair();
    // Parameter value methods.
    double X(void);
    double Y(void);
  private:
    std::pair<double> xy;
  };
  */
  
  //
  // Class Vec2d - Vectors are defined by a (x_length, y_length) pair.
  //
  
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
    
  //
  // Class Pos2d - Positions are defined by a (x, y) pair.
  //
  
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
    static double Wrap(double z, double max_z); // Recursive method!
    double x;
    double y;
  };

} // End namespace.

#endif
