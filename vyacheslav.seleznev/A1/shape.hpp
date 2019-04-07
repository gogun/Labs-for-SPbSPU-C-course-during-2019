#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
  public:
  Shape(point_t p): centre_(p)
  {
  };
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  void move(const point_t newPoint)
  {
    centre_ = newPoint;
  };
  void move(const double dx, const double dy)
  {
    double newX = centre_.x + dx;
    double newY = centre_.y + dy;

    centre_ = { newX, newY };
  };

  protected:
  point_t centre_;
};

#endif
