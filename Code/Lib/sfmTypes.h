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
  // Class Vec2d.
  //
  
  class Vec2d {
  public:
    // Constructors.
    Vec2d();
    Vec2d(const double x_length, const double y_length);
    // Destructor.
    ~Vec2d();
    // Parameter value methods.
    Vec2d operator+(const Vec2d v);
    Vec2d operator*(const double scaling_factor);
    double Length();
    double GetXLength(void) const;
    double GetYLength(void) const;
  private:
    double x_length;
    double y_length;
  };
    
  //
  // Class Pos2d.
  //
  
  class Pos2d {
  public:
    // Constructors.
    Pos2d();
    Pos2d(const double x, const double y);
    // Destructor.
    ~Pos2d();
    // Parameter value methods.
    Pos2d operator+(const Vec2d v);
    Vec2d operator-(const Pos2d p);
    double GetX() const;
    double GetY() const;
  private:
    static double Wrap(const double z, const double max_z); // Recursive method!
    double x;
    double y;
  };

} // End namespace.

#endif
