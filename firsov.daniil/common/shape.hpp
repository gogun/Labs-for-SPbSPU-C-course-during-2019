#ifndef A2_SHAPE_HPP
#define A2_SHAPE_HPP
#include "base-types.hpp"

namespace firsov
{
  class Shape {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void printShapeInfo() const = 0;
    virtual void scale(double multiplier) = 0;
  };
}
#endif
