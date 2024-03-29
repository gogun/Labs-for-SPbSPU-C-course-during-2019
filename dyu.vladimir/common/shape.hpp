#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace dyu
{
  class Shape
  {
    public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &pos) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double coeficient) = 0;
  };
}

#endif // SHAPE_HPP
