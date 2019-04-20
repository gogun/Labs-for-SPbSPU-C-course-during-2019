#ifndef ShapeHPP_A2
#define ShapeHPP_A2

#include "base-types.hpp"

namespace lukina
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(const point_t &newPoint) = 0;
    virtual void scale(double coefficient) = 0;
    virtual void printInfo() const = 0;
  };
}

#endif
