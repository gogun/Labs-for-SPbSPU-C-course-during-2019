#ifndef SHAPE_HPP
#define SHAPE_HPP
<<<<<<< HEAD

=======
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
<<<<<<< HEAD
  
=======
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t &newPos) = 0;
  virtual void move(double dx, double dy) = 0;
};

#endif
