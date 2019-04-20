#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  Shape(point_t p): centre_(p)
  {
  }
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  void move(const point_t newPoint)
  {
    centre_ = newPoint;
  }
  void move(const double dx, const double dy)
  {
    centre_.x += dx;
    centre_.y += dy;
  }

protected:
  point_t centre_;
};

#endif
