#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace chugaynov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual rectangle_t getFrameRect() const = 0;
    virtual double getArea() const = 0;
    virtual void move(const point_t &point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double coefficient) = 0;
  };
}
#endif
