#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.hpp"

namespace kornilov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const double dx, const double dy) = 0;
    virtual void move(const point_t& point) = 0;
    virtual void scale(const double coefficient) = 0;
  };
}

#endif
