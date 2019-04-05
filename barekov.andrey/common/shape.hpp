#ifndef A2_SHAPE
#define A2_SHAPE

#include "base-types.hpp"

namespace barekov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual point_t getPos() const = 0;
    virtual void showScalableParameters() const = 0;
    virtual void move(const point_t& centre) = 0;
    virtual void move(double deltaX, double deltaY) = 0;
    virtual void scale(double scaleFactor) = 0;
  };
}

#endif
