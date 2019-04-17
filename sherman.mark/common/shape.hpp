#ifndef COMMON_SHAPE_HPP
#define COMMON_SHAPE_HPP
#include "base-types.hpp"

namespace sherman
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double, double) = 0;
    virtual void move(const point_t &) = 0;
    virtual void scale(double) = 0;
    virtual void printInformation() const = 0;
  };
}

#endif
