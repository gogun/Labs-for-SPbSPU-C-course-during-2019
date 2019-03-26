#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.hpp"


class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double shiftX, double shiftY) = 0;
  virtual void move(point_t newPoint) = 0;
};

#endif
