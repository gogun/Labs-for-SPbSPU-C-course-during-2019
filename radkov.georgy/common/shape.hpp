#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace radkov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const noexcept = 0;
    virtual void move(double dx, double dy) noexcept = 0;
    virtual void move(const point_t &pos) noexcept = 0;
    virtual void scale(double k) = 0;
  };
}

#endif
