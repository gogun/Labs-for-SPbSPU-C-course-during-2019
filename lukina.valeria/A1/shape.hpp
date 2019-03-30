#ifndef ShapeHPP
#define ShapeHPP

#include <iostream>
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void move(point_t NewPoint) = 0;
};

#endif
